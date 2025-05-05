package spriteframework;


import javax.swing.JPanel;
import javax.swing.Timer;

import spriteframework.sprite.BadSprite;
import spriteframework.sprite.Player;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.LinkedList;


public abstract class AbstractBoard extends JPanel {
    protected Dimension d;
    
    //define sprites
//    private List<Alien> aliens;
    protected LinkedList<Player> players;
    
    protected LinkedList<BadSprite> badSprites;
    
//    private Shot shot;
//    
    // define global control vars   
//    private int direction = -1;
//    private int deaths = 0;

    protected int numberPlayers;  // de private para protected
    protected boolean inGame = true;
//    private String explImg = "src/images/explosion.png";
    protected String message = "Game Over";

    protected Timer timer;

    // Frozen Spots
    //  void initBoard()
    // 
    // HotSpots
    protected abstract void createBadSprites();
    protected abstract void createOtherSprites();
    protected abstract void drawOtherSprites(Graphics g);
    protected abstract void update();
    protected abstract void processOtherSprites(Player player, KeyEvent e);
    // declarações de métodos abstratos para modificação do método template doDrawing()
    protected abstract void drawBackground(Graphics2D g);
    protected abstract void drawGameOver(Graphics2D g);
    protected abstract void drawGameWon(Graphics2D g);
    protected abstract Color getBackgroundColor();

    public AbstractBoard() {

        initBoard();
        createPlayers();
		        numberPlayers = 1;
		        badSprites = new LinkedList<BadSprite>();
		        createBadSprites();
		        createOtherSprites();
		//        shot = new Shot();
    }

    protected abstract void initBoard(); // virou abstrato para mudar o tamanho de cada jogo.

    @Override
    public Dimension getPreferredSize() {
        return d; // usa o tamanho que você definiu em initBoard(), será usado para o AbstractBoard e MainFrame
    }

    protected void createPlayers() {
		players = new LinkedList<Player>();
        players.add(createPlayer());
	}

	protected abstract Player createPlayer();

   public Player getPlayer(int i) {
	   if (i >=0 && i<players.size())
		   return players.get(i);
	   return null;
   }
   
    private void drawBadSprites(Graphics g) {

        for (BadSprite bad : badSprites) {

            if (bad.isVisible()) {

                g.drawImage(bad.getImage(), bad.getX(), bad.getY(), this);
            }

            if (bad.isDying()) {

                bad.die();
            }
            if (bad.getBadnesses()!= null) {
            	for (BadSprite badness: bad.getBadnesses()) {
            		if (!badness.isDestroyed()) {
            			g.drawImage(badness.getImage(), badness.getX(), badness.getY(), this);
            		}
            	}
            }
        }
    }

    private void drawPlayers(Graphics g) {
    	for (Player player: players) {
    		if (player.isVisible()) {
    			g.drawImage(player.getImage(), player.getX(), player.getY(), this);
    		}

    		if (player.isDying()) {

    			player.die();
    			inGame = false;
    		}
    	}
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        doDrawing(g);
    }

    private void doDrawing(Graphics g1) { // Template Method modificado pelo grupo
        Graphics2D g = (Graphics2D) g1;
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);

        g.setColor(getBackgroundColor());
        g.fillRect(0, 0, d.width, d.height);

        if (inGame) {
            drawBackground(g); // hook para fundo decorativo
            drawBadSprites(g);
            drawPlayers(g);
            drawOtherSprites(g);
        } else {
            if (timer.isRunning()) {
                timer.stop();
            }
            if ("Game won!".equals(message)) {
                drawGameWon(g);
            } else {
                drawGameOver(g); // hook para tela de game over personalizada
            } // hook para tela de game over personalizada
        }

        Toolkit.getDefaultToolkit().sync();
    }


    private void doGameCycle() {

        update();
        repaint();
    }

	public class GameCycle implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {

            doGameCycle();
        }
    }

    public class TAdapter extends KeyAdapter {

        @Override
        public void keyReleased(KeyEvent e) {
            for (Player player: players)
                 player.keyReleased(e);
        }

        @Override
        public void keyPressed(KeyEvent e) {
        	for (Player player: players) {
                player.keyPressed(e);

                processOtherSprites(player, e); // hotspot
        	}
        }
    }
}