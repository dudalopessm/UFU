package spriteframework.sprite;

import javax.swing.ImageIcon;

import spriteframework.Commons;

import java.awt.Image;
import java.awt.event.KeyEvent;

public abstract class Player extends Sprite {

    protected int width;
    protected int direcao;

    public Player() {
        loadImage();
		getImageDimensions();
		resetState();
    }

    protected abstract void loadImage ();

    public abstract void act();

    public abstract void keyPressed(KeyEvent e);

    public abstract void keyReleased(KeyEvent e);

    public int getDirecao(){
        return direcao;
    }

    private void resetState() {
        setX(Commons.INIT_PLAYER_X);
        setY(Commons.INIT_PLAYER_Y);
    }
}
