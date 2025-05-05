package freezemonster;

import spaceinvaders.SpaceInvadersBoard;
import spaceinvaders.SpaceInvadersGame;
import spriteframework.AbstractBoard;
import spriteframework.MainFrame;

import java.awt.*;

public class FreezeMonsterGame extends MainFrame {

    public FreezeMonsterGame() {
        super("Freeze Monster");
    }

    protected AbstractBoard createBoard() {
        return new FreezeMonsterBoard();
    }


    public static void main(String[] args) {

        EventQueue.invokeLater(FreezeMonsterGame::new);
    }
}