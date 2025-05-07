package freezemonster;

import freezemonster.sprite.Gelo;
import freezemonster.sprite.Gosma;
import freezemonster.sprite.Monstro;
import freezemonster.sprite.Woody;
import freezemonster.Commons;
import spriteframework.AbstractBoard;
import spriteframework.sprite.BadSprite;
import spriteframework.sprite.Player;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;

public class FreezeMonsterBoard extends AbstractBoard {

    private Gelo gelo;

    private int deaths = 0;

    private int direction = -1;

    // métodos para visualização do tabuleiro
    @Override
    protected void drawBackground(Graphics2D g) {
        g.setColor(Color.cyan);
    }

    @Override
    protected void drawGameOver(Graphics2D g) {
        g.setColor(new Color(50, 0, 0));
        g.fillRect(0, 0, Commons.BOARD_WIDTH, Commons.BOARD_HEIGHT);
        g.setColor(Color.white);
        g.setFont(new Font("Courier New", Font.BOLD, 24));
        g.drawString("Você perdeu!", Commons.BOARD_WIDTH / 2 - 80, Commons.BOARD_HEIGHT / 2);
    }

    protected void drawGameWon(Graphics2D g) {
        g.setColor(new Color(0, 150, 0));
        g.fillRect(0, 0, Commons.BOARD_WIDTH, Commons.BOARD_HEIGHT);
        g.setColor(Color.white);
        g.setFont(new Font("Courier New", Font.BOLD, 24));
        g.drawString("Você ganhou!", Commons.BOARD_WIDTH / 2 - 80, Commons.BOARD_HEIGHT / 2);
    }

    @Override
    protected Color getBackgroundColor() {
        return new Color(100,193,76);
    }

    @Override
    protected void initBoard() {
        addKeyListener(new TAdapter());
        setFocusable(true);
        d = new Dimension(Commons.BOARD_WIDTH, Commons.BOARD_HEIGHT);
        setBackground(Color.cyan);  // visual diferente

        timer = new Timer(10, new GameCycle()); // pode ser mais lento, se quiser

        timer.start();

        createPlayers();
        numberPlayers = 1;
        badSprites = new LinkedList<>();
        createBadSprites();
        createOtherSprites();
    }

    protected Player createPlayer() {
        return new Woody();
    }

    protected void createPlayers() {
        players = new LinkedList<Player>();
        players.add(createPlayer());
    }

    @Override
    protected void createBadSprites() {

        Random rand = new Random();

        for (int i = 0; i < freezemonster.Commons.MONSTRO_ROWS; i++) {
            for (int j = 0; j < freezemonster.Commons.MONSTRO_COLS; j++) {
                int tipo = rand.nextInt(9) + 1;
                Monstro monstro = new Monstro(Commons.MONSTRO_INIT_X + 18 * j,
                        Commons.MONSTRO_INIT_Y + 18 * i,
                        tipo);
                badSprites.add(monstro);
            }
        }

    }

    @Override
    protected void createOtherSprites() {
        gelo = new Gelo();
        gelo.setVisible(false); // garante que ele já é setado logo de começo
    }

    private void drawShot(Graphics g) {
        if (gelo.isVisible()) {
            g.drawImage(gelo.getImage(), gelo.getX(), gelo.getY(), this);
        }
    }

    @Override
    protected void drawOtherSprites(Graphics g) {
        drawShot(g);
    }

    @Override
    protected void update() {

        // player
        for (Player player : players)
            player.act();

        // gelo (substitui o shot original)
        if (gelo != null && gelo.isVisible()) {

            int geloX = gelo.getX();
            int geloY = gelo.getY();

            // verificar colisão com monstros
            for (BadSprite alien : badSprites) {

                int alienX = alien.getX();
                int alienY = alien.getY();

                if (alien.isVisible() && gelo.isVisible()) {
                    if (geloX >= alienX &&
                            geloX <= (alienX + Commons.MONSTRO_WIDTH) &&
                            geloY >= alienY &&
                            geloY <= (alienY + Commons.MONSTRO_HEIGHT)) {

                        if (alien instanceof Monstro monstro) {
                            alien.setImage(monstro.getImagemCongelado());
                            monstro.setCongelado(true);
                        }

                        alien.setDy(0);
                        alien.setDx(0);

                        gelo.die(); // mata o tiro
                    }
                }

                // verificar colisão com gosmas
                if (alien instanceof Monstro monstro && gelo.isVisible()) {
                    Gosma gosma = monstro.getGosma();

                    if (!gosma.isDestroyed()) {
                        int gosmaX = gosma.getX();
                        int gosmaY = gosma.getY();

                        // verificar colisão do gelo com a gosma
                        // mesma lógica de colisão que é usada para outros objetos
                        if (geloX >= gosmaX &&
                                geloX <= (gosmaX + Commons.GOSMA_WIDTH) &&
                                geloY >= gosmaY &&
                                geloY <= (gosmaY + Commons.GOSMA_HEIGHT)) {

                            gosma.setDestroyed(true); // destrói a gosma
                            gelo.die(); // destrói o gelo também
                        }
                    }
                }
            }

            // atualiza a posição com base na direção
            int direcao = gelo.getDirecao();
            switch (direcao) {
                case 1: // direita
                    gelo.setX(gelo.getX() + 4);
                    break;
                case -1: // esquerda
                    gelo.setX(gelo.getX() - 4);
                    break;
                case 2: // cima
                    gelo.setY(gelo.getY() - 4);
                    break;
                case -2: // baixo
                    gelo.setY(gelo.getY() + 4);
                    break;
            }

            // caso saia da tela
            if (gelo.getX() < 0 ||
                    gelo.getX() > Commons.BOARD_WIDTH ||
                    gelo.getY() < 0 ||
                    gelo.getY() > Commons.BOARD_HEIGHT) {
                gelo.die();
            }
        }

        // movimentação dos monstros
        for (BadSprite alien : badSprites) {
            if (alien.isVisible()) {
                int y = alien.getY();

                // usa act() ao invés de moveX()
                if (alien instanceof Monstro monstro) {
                    monstro.act(); // diferente do space invaders, controlamos as bordas dentro do act e não dentro do tabuleiro
                }
            }
        }

        // verifica se todos os monstros estão congelados
        boolean todosCongelados = true;
        int monstrosCongelados = 0;

        for (BadSprite alien : badSprites) {
            if (alien instanceof Monstro monstro) {
                if (alien.isVisible() && !monstro.isCongelado()) {
                    todosCongelados = false;
                    break;
                }
                if (monstro.isCongelado()) {
                    monstrosCongelados++;
                }
            }
        }

        // verifica se venceu
        if (todosCongelados && monstrosCongelados > 0) {
            inGame = false;
            timer.stop();
            message = "Game won!";
        }

        // bombs e outros sprites
        updateOtherSprites();
    }

    @Override
    protected void processOtherSprites(Player player, KeyEvent e) {

        int x = player.getX();
        int y = player.getY();

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_SPACE) {

            if (inGame) {

                if (!gelo.isVisible()) {

                    gelo = new Gelo(x, y, player.getDirecao() // usa a última direção do woody para definir a direção do gelo
                    );
                }
            }
        }
    }

    protected void updateOtherSprites() {
        for (BadSprite alien : badSprites) {
            // só continua se o monstro for visível
            if (!(alien instanceof Monstro monstro) || !alien.isVisible()) continue;

            Gosma gosma = monstro.getGosma();

            // só processa gosma para monstros ativos
            // se o monstro for congelado, a gosma é destruída
            if (monstro.isCongelado()) {
                gosma.setDestroyed(true);
                continue;
            }

            // lança gosma para direção contrária do monstro
            if (gosma.isDestroyed() && alien.isVisible()) {
                int direcaoGosma = -monstro.getDirecao();
                gosma.setDestroyed(false);
                gosma.setX(monstro.getX());
                gosma.setY(monstro.getY());
                gosma.setDirecao(direcaoGosma);
            }

            // controla o movimento da gosma
            if (!gosma.isDestroyed()) {
                switch (gosma.getDirecao()) {
                    case 1 -> gosma.setX(gosma.getX() + 2);
                    case -1 -> gosma.setX(gosma.getX() - 2);
                    case 2 -> gosma.setY(gosma.getY() - 2);
                    case -2 -> gosma.setY(gosma.getY() + 2);
                }

                // verifica se a gosma saiu da tela, se sim, ela é destruída
                if (gosma.getX() < 0 || gosma.getX() > Commons.BOARD_WIDTH ||
                        gosma.getY() < 0 || gosma.getY() > Commons.GROUND) {
                    gosma.setDestroyed(true);
                }

                // verifica colisão da gosma com o jogador -> jogador morre
                Player player = players.get(0);

                int gx = gosma.getX();
                int gy = gosma.getY();
                int px = player.getX();
                int py = player.getY();

                if (player.isVisible()
                        && gx >= px && gx <= (px + Commons.PLAYER_WIDTH)
                        && gy >= py && gy <= (py + Commons.PLAYER_HEIGHT)) {

                    player.setDying(true);
                    gosma.setDestroyed(true);
                }
            }
        }
    }
}