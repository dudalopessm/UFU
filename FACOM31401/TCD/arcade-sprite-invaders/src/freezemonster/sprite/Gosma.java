package freezemonster.sprite;

import javax.swing.ImageIcon;

import spriteframework.sprite.BadSprite;

import java.awt.*;

public class Gosma extends BadSprite{

    private boolean destroyed;
    private int direcao;

    public Gosma(int x, int y) {

        initGosma(x, y);
    }

    public int getDirecao() {
        return direcao;
    }

    public void setDirecao(int direcao) {
        this.direcao = direcao;
    }

    private void initGosma(int x, int y) {

        setDestroyed(true);

        this.x = x;
        this.y = y;

        String gosmaImg = "/images/gosma.png";
        ImageIcon ii = new ImageIcon(getClass().getResource(gosmaImg));
        Image gosmaImage = ii.getImage().getScaledInstance(40, 40, Image.SCALE_DEFAULT);
        setImage(gosmaImage);
    }

    public void setDestroyed(boolean destroyed) {
        this.destroyed = destroyed;
    }

    public boolean isDestroyed() {
        return destroyed;
    }
}
