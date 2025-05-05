package freezemonster.sprite;

import javax.swing.ImageIcon;

import spriteframework.sprite.BadSprite;

import java.awt.*;

public class Gelo extends BadSprite{

    private int direcao;

    public Gelo() {
    }

    public Gelo(int x, int y, int direcao) {
        this.direcao = direcao;
        initGelo(x, y);
    }

    public int getDirecao() {
        return direcao;
    }

    private void initGelo(int x, int y) {

        ImageIcon ii = new ImageIcon(getClass().getResource("/images/ray.png"));

        Image geloImage = ii.getImage().getScaledInstance(30, 30, Image.SCALE_DEFAULT);
        setImage(geloImage);;

        int H_SPACE = 6;
        setX(x + H_SPACE);

        int V_SPACE = 1;
        setY(y - V_SPACE);

        this.dx = direcao; // define como última direção
        setVisible(true);
    }
}