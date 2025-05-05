package freezemonster;

public interface Commons extends spriteframework.Commons{

    int MONSTRO_HEIGHT = 40;
    int MONSTRO_WIDTH = 40;
    int MONSTRO_INIT_X = 350;
    int MONSTRO_INIT_Y = 200;

    int MONSTRO_ROWS = 3; // GERA 9 MONSTROS
    int MONSTRO_COLS = 3;

    int NUMBER_OF_MONSTERS_TO_DESTROY = MONSTRO_ROWS*MONSTRO_COLS;

    int BOARD_WIDTH = 1000;
    int BOARD_HEIGHT = 780;
    int GROUND = 780; // mesmo da altura da tela;
    int PLAYER_WIDTH = 60; // hitbox do woody
    int PLAYER_HEIGHT = 60;

    int INIT_PLAYER_X = 500;
    int INIT_PLAYER_Y = 500;
}
