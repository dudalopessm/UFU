package spriteframework;

import javax.swing.*;

public abstract class MainFrame extends JFrame  {

	protected abstract AbstractBoard createBoard();

	public MainFrame(String t) {

		AbstractBoard board = createBoard();
		add(board);

		setTitle(t);
		pack(); // Faz o frame ter o tamanho do conteúdo, e nao o de common

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setResizable(false);
		setLocationRelativeTo(null);
		setVisible(true);
	}
}
