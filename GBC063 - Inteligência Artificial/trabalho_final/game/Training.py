from .Player import Player
from .TicTacToe import TicTacToe

def training(numero_rodadas_treino: int, win_value: int, loose_value: int, draw_value):
    # Definindo os jogadores e as IA's
    AI_FIRST  = Player("AI_FIRST", "AI", 0.9999)
    AI_SECOND = Player("AI_SECOND", "AI", 0.9999)
    
    # Jogador aleatorio para competir entre eles para melhora de ambos
    RAMDOM_PLAYER = Player("Player2", "random", 0.99) 

    # Jogadores na primeira rodada de treino
    players = [AI_FIRST, RAMDOM_PLAYER]

    game = TicTacToe(players)
    # Rodada de treino com jogador numero 1 numero o 
    for x in range(numero_rodadas_treino): #treino
        game.playGame()
        
        # A IA ganhou o jogo
        if(game.winner == 0):
            AI_FIRST.updateQTable(win_value)
        
        # A IA perdeu o jogo
        elif(game.winner == 1):
            AI_FIRST.updateQTable(loose_value)
        
        # A IA empatou o jogo
        else:
            AI_FIRST.updateQTable(draw_value)

        # Jogo eh resetado para recomeçar o treino
        game.reset()

        # Valor do epsilon
        AI_FIRST.updateE(x, numero_rodadas_treino)
    
    # Finalização do primeiro treinamento

    # Treinamento com a IA jogando segundo
    players = [RAMDOM_PLAYER, AI_SECOND]
    game = TicTacToe(players)

    for x in range(numero_rodadas_treino): #treino
        game.playGame()

        # A IA ganhou o jogo
        if(game.winner == 1):
            AI_SECOND.updateQTable(win_value)
        
        # A IA perdeu o jogo
        elif(game.winner == 0):
            AI_SECOND.updateQTable(loose_value)
        
        # A IA empatou o jogo
        else:
            AI_SECOND.updateQTable(draw_value)
        game.reset()

        AI_SECOND.updateE(x, numero_rodadas_treino)

    # Finalizando o segundo treinamento
    AI_FIRST.epsilon = 0.9999
    AI_SECOND.epsilon = 0.9999

    # Treinamento com a IA contra IA
    players = [AI_FIRST, AI_SECOND]
    game = TicTacToe(players)

    for x in range(numero_rodadas_treino): #treino
        game.playGame()

        if(game.winner == 1):
            AI_SECOND.updateQTable(win_value)
            AI_FIRST.updateQTable(loose_value)

        elif(game.winner == 0):
            AI_SECOND.updateQTable(loose_value)
            AI_FIRST.updateQTable(win_value)
        
        # A IA empatou o jogo
        else:
            AI_SECOND.updateQTable(draw_value)
            AI_FIRST.updateQTable(draw_value)
        game.reset()

        AI_SECOND.updateE(x, numero_rodadas_treino)
        AI_FIRST.updateE(x, numero_rodadas_treino)
    
    # Treinamento com a IA contra IA
    
    AI_FIRST.epsilon = 0.9999
    AI_SECOND.epsilon = 0.9999
    players = [AI_SECOND, AI_FIRST]
    game = TicTacToe(players)

    for x in range(numero_rodadas_treino): #treino
        game.playGame()

        if(game.winner == 0):
            AI_SECOND.updateQTable(win_value)
            AI_FIRST.updateQTable(loose_value)

        elif(game.winner == 1):
            AI_SECOND.updateQTable(loose_value)
            AI_FIRST.updateQTable(win_value)
        
        # A IA empatou o jogo
        else:
            AI_SECOND.updateQTable(draw_value)
            AI_FIRST.updateQTable(draw_value)
        game.reset()

        AI_SECOND.updateE(x, numero_rodadas_treino)
        AI_FIRST.updateE(x, numero_rodadas_treino)
    
    AI_FIRST.epsilon  = 0
    AI_SECOND.epsilon = 0    
    return (AI_FIRST, AI_SECOND)

# Avalia o desempenho da IA jogando em ambos os casos
def evaluate(player_01: Player, player_02: Player = Player("Aleatorio", "random", 0.99)):
    """
    Avalia o desempenho de um jogador (player_01) contra um oponente (player_02),
    tanto começando o jogo quanto jogando em segundo.
    """
    
    # --- Cenário 1: player_01 começa jogando ---
    game_p1_starts = TicTacToe([player_01, player_02])
    wins_p1_starts = 0
    ties_p1_starts = 0
    losses_p1_starts = 0
    numero_jogos = 100000

    print(f"Avaliando {player_01.name} como primeiro jogador e {player_02.name} como segundo... Aguarde.")
    for _ in range(numero_jogos):
        game_p1_starts.playGame()
        if game_p1_starts.winner == 0:  # player_01 (index 0) venceu
            wins_p1_starts += 1
        elif game_p1_starts.winner == 1:  # player_02 (index 1) venceu
            losses_p1_starts += 1
        else:  # Empate
            ties_p1_starts += 1
        game_p1_starts.reset()

    # --- Cenário 2: player_01 joga em segundo ---
    game_p1_seconds = TicTacToe([player_02, player_01]) 
    wins_p1_seconds = 0
    ties_p1_seconds = 0
    losses_p1_seconds = 0

    print(f"Avaliando {player_01.name} como segundo jogador e {player_02.name} como primeiro jogador... Aguarde.")
    for _ in range(numero_jogos):
        game_p1_seconds.playGame()
        if game_p1_seconds.winner == 1:  # player_01 (index 1) venceu
            wins_p1_seconds += 1
        elif game_p1_seconds.winner == 0:  # player_02 (index 0) venceu
            losses_p1_seconds += 1
        else:  # Empate
            ties_p1_seconds += 1
        game_p1_seconds.reset()
    
    # --- Impressão dos Resultados ---
    print("\n" + "="*40)
    print(f"    RESULTADOS PARA: {player_01.name.upper()}    ")
    print("="*40)

    # IA jogando primeiro
    p_wins_1   = (wins_p1_starts / numero_jogos) * 100
    p_losses_1 = (losses_p1_starts / numero_jogos) * 100
    p_ties_1   = (ties_p1_starts / numero_jogos) * 100
    print(f"\nQuando joga primeiro (como 'X') contra {player_02.name}:")
    print(f"  Vitórias: {wins_p1_starts:<7} ({p_wins_1:.2f}%)")
    print(f"  Derrotas: {losses_p1_starts:<7} ({p_losses_1:.2f}%)")
    print(f"  Empates:  {ties_p1_starts:<7} ({p_ties_1:.2f}%)")

    # IA Jogando segundo
    p_wins_2   = (wins_p1_seconds / numero_jogos) * 100
    p_losses_2 = (losses_p1_seconds / numero_jogos) * 100
    p_ties_2   = (ties_p1_seconds / numero_jogos) * 100
    print(f"\nQuando joga em segundo (como 'O') contra {player_02.name}:")
    print(f"  Vitórias: {wins_p1_seconds:<7} ({p_wins_2:.2f}%)")
    print(f"  Derrotas: {losses_p1_seconds:<7} ({p_losses_2:.2f}%)")
    print(f"  Empates:  {ties_p1_seconds:<7} ({p_ties_2:.2f}%)")
    print("="*40 + "\n")