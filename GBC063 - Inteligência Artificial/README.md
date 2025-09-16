# Jogo da Velha com Inteligência Artificial (Q-Learning)

Este projeto apresenta a implementação de uma Inteligência Artificial para o jogo da velha (TicTacToe), utilizando o algoritmo de Q-Learning.  
A IA é treinada por meio de autojogos, atualizando sua Q-Table de acordo com as recompensas atribuídas ao resultado de cada partida.

---

## Objetivos

- Aplicar conceitos de **Aprendizado por Reforço (Reinforcement Learning)** em um ambiente simples.  
- Implementar o algoritmo **Q-Learning** para treinar um agente autônomo.  
- Explorar os seguintes conceitos fundamentais:
  - Função de Recompensa
  - Função Ação-Valor (Q-Table)
  - Política ε-greedy
  - Equilíbrio entre exploração e aproveitamento do conhecimento adquirido

---

## Funcionalidades

- Treinamento da IA com número configurável de episódios.  
- Definição personalizada de recompensas para vitória, derrota e empate.  
- Salvamento e carregamento da **Q-Table** utilizando a biblioteca `pickle`.  
- Modos de jogo disponíveis:
  - Humano contra Humano
  - Humano contra IA
  - IA contra IA

---

## Execução do Projeto
Não há necessidade de instalação de pacotes externos.

### 1. Clonar o repositório
```bash
git clone https://github.com/seu-usuario/jogo-da-velha-ia.git
cd jogo-da-velha-ia
```

### 2. Executar o programa
```bash
python main.py
```
No início da execução será exibido um menu solicitando a escolha do modo de jogo.

---

## Autoria
Este projeto foi desenvolvido como parte de atividade acadêmica na disciplina de Inteligência Artificial, com o objetivo de aplicar técnicas de Aprendizado por Reforço em um ambiente de jogo clássico. A implementação foi realizada em Python, com foco na clareza e na compreensão do processo de aprendizagem por Q-Learning.

Autores: Eduarda Lopes, Lucas Matos, Kamily Cristina Gomes, Gabriel Augusto Alves, Matheus Vinicius Máximo, Anna Clara Rodrigues e Pedro Miguel de Paula