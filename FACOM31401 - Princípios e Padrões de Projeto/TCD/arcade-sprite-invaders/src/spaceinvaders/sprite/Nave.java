package spaceinvaders.sprite;

import spriteframework.Commons;
import spriteframework.sprite.Player;

import javax.swing.*;
import java.awt.event.KeyEvent;

public class Nave extends Player {
    protected void loadImage () {
        ImageIcon ii = new ImageIcon(this.getClass().getResource("/images/player.png"));
        width = ii.getImage().getWidth(null);
        setImage(ii.getImage());
    }

    public void act() {

        x += dx;

        if (x <= 2) {

            x = 2;
        }

        if (x >= spriteframework.Commons.BOARD_WIDTH - 2 * width) {

            x = spriteframework.Commons.BOARD_WIDTH - 2 * width;
        }
    }

    public void keyPressed(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {

            dx = -2;
        }

        if (key == KeyEvent.VK_RIGHT) {

            dx = 2;
        }
    }

    public void keyReleased(KeyEvent e) {

        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {

            dx = 0;
        }

        if (key == KeyEvent.VK_RIGHT) {

            dx = 0;
        }
    }

    private void resetState() {
        setX(spriteframework.Commons.INIT_PLAYER_X);
        setY(Commons.INIT_PLAYER_Y);
    }
}
