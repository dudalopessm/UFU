import random
import numpy as np
from .TicTacToe import TicTacToe

class Player:
    def __init__(self, name, strategy, epsilon):
        self.name = name
        self.strategy = strategy
        self.epsilon = epsilon
        self.q_table = {}
        self.states = []
    
    def makeMove(self, board):
        validMoves = [] 
        #board = [" ", "X", "O", "X", "O"...]
        #validMoves = [3,5,7,...]
        for x in range(len(board)):
            if(board[x] == " "):
                validMoves.append(x)
        if(self.strategy == "human"):
            print("Os seus movimentos validos são:", validMoves)
            print("Qual movimento deseja realizar? ")
            move = int(input())
            while(move not in validMoves):
                print("IMovimento inválido. Tente novamente!")
                move = int(input())
            return move
        elif(self.strategy == "random"):
            return random.choice(validMoves)
        elif(self.strategy == "AI"):
            # Estados possíveis entre os valores
            state = tuple(board)

            # Aplicar transposição de estados para o jogo
            move_index = 0
            if state not in self.q_table: 
                #se ainda nao passou por esse estado salva ele na tabela e 
                # zera todos os seus valores de movimento inicialmente
                self.q_table[state] = [0.0 for _ in range(9)]

            # Mask invalid moves: set them to -inf so np.argmax won't select them
            masked_q_values = np.array([
                self.q_table[state][i] if i in validMoves else -np.inf for i in range(9)
            ])
            if(random.random() < self.epsilon):
                move = random.choice(validMoves)
            else:
                move = int(np.argmax(masked_q_values))
            self.states.append((state, move))

            return move

    #New Version
    def updateQTable(self, reward):
        alpha = 0.1  # Learning rate
        gamma = 0.9  # Discount factor

        for (state, action_index) in self.states:
            max_future_q = max(self.q_table[state])  # Max Q-value of next state
            self.q_table[state][action_index] += alpha * (reward + gamma * max_future_q - self.q_table[state][action_index])
        self.states.clear()
    
    # Funcao para atualizar o epsilon a medida do tempo
    def updateE(self, current_episode, total_episodes, min_epsilon=0.01, max_epsilon=1.0):
        
        # Calcula a taxa de decaimento necessária para atingir o min_epsilon no final
        decay_rate = -np.log(min_epsilon / max_epsilon) / total_episodes
        
        # Atualiza o epsilon usando a fórmula de decaimento exponencial
        self.epsilon = max(min_epsilon, max_epsilon * np.exp(-decay_rate * current_episode))