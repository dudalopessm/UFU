class TicTacToe:
    def __init__(self,players):
        self.players = players
        self.board = [" " for x in range (9)]
        self.gameOver = False
        self.winner = " "

    def printBoard(self):
        print()
        for x in range(3):
            print(" | ", end="")
            for y in range(3):
                index = x * 3 + y
                content = self.board[index]

                if content in ['X', 'O']:
                    if content == 'X':
                        print(f"\033[31m{content}\033[0m", end="")
                    else:
                        print(f"\033[94m{content}\033[0m", end="")
                else:
                    print(index, end="")
                
                print(" | ", end="")
            
            # Imprime a linha separadora horizontal, se não for a última linha
            if x < 2:
                print("\n |---|---|---|")
        print("\n")
        

    def playGame(self,verbose=False):
        if verbose: self.printBoard()
        while(True):
            move = self.players[0].makeMove(self.board)
            self.board[move] ="X"
            if verbose: self.printBoard()

            #checa se o jogo acaba com essa jogada de X
            self.checkForWin()
            if(self.gameOver):
                break

            move = self.players[1].makeMove(self.board)
            self.board[move] ="O"
            if verbose: self.printBoard()
            
            #checa se o jogo acaba com essa jogada de O
            self.checkForWin()
            if(self.gameOver):
                break

    def checkForWin(self):
        win_conditions = [
            (0,1,2),(3,4,5),(6,7,8), #horizontais
            (0,3,6),(1,4,7),(2,5,8), #verticais
            (0,4,8),(2,4,6)          #diagonais
        ]
        for (i,j,k) in win_conditions:
            if(self.board[i]!=" " and self.board[i]==self.board[j]==self.board[k]):
                if(self.board[i]=="X"):
                    self.winner = 0
                    self.gameOver = True
                else:
                    self.winner = 1
                    self.gameOver = True
        if " " not in self.board and self.winner == " ": #empate
            self.gameOver =  True
            self.winner = 2

    def reset(self):
        self.board = [" " for x in range(9)]
        self .gameOver = False
        self.winner = " "