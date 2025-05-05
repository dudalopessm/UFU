# Freeze Monster Game baseado no framework Sprite

Este é um jogo 2D inspirado no jogo Space Invaders, também presente no repositório.

## Tecnologias Utilizadas

- Java 8+
- Java Swing (interface gráfica)
- Padrões de Projeto (Design Patterns)

---

## Arquitetura e Padrões de Projeto

### Template Method

Define a estrutura do game loop na superclasse `AbstractBoard`, delegando etapas específicas para subclasses como `FreezeMonsterBoard`.

```java
private void doDrawing(Graphics g) {
    if (inGame) {
        drawBackground(g);
        drawBadSprites(g);
        drawPlayers(g);
        drawOtherSprites(g);
    } else {
        if (timer.isRunning()) timer.stop();
        if ("Game won!".equals(message)) {
            drawGameWon(g);
        } else {
            drawGameOver(g);
        }
    }
}
```

Assim, o método Template é o doDrawing que tem uma implementação base que possui vários hookMethods que permitem a personalização do método sem exigir que a estrutura principal seja alterada.

Há vários métodos abstratos que as classes devem implementar: createBadSprites(), createOtherSprites(), drawOtherSprites(Graphics g), update(), processOtherSprites(Player player, KeyEvent e), drawBackground(Graphics2D g), drawGameOver(Graphics2D g), drawGameWon(Graphics2D g) e getBackgroundColor().

Esses métodos personalizáveis garantem a unicidade de cada jogo construído a partir do framework.

### Factory 

Fornece uma interface para criação de um objeto e permite que as subclasses escolham qual classe instanciar.

```java
protected abstract Player createPlayer(); // em AbstractBoard
protected Player createPlayer() {
    return new Woody(); // criação concreta do jogador em FreezeMonsterBoard
}

protected abstract AbstractBoard createBoard(); // no MainFrame
protected AbstractBoard createBoard() {
    return new FreezeMonsterBoard(); // em FreezeMonsterGame implementando concretamente
}

```

Esse padrão permite trocar o tipo de jogador ou tabuleiro com facilidade baseado no framework.

### Composite

Permite tratar objetos individuais e composições de objetos de forma uniforme.

No jogo, BadnessBoxSprite pode conter uma lista de outros BadSprite, formando uma estrutura hierárquica. 

Logo, a hierarquia é usada com BadnessBox agindo como um Composite que pode conter outros objetos BadSprite.

```java
// BadnessBoxSprite.java
public class BadnessBoxSprite extends BadSprite {
    LinkedList<BadSprite> badnesses = new LinkedList<BadSprite>();
     
    void add(BadSprite b) {
        badnesses.add(b);
    }
     
    public LinkedList<BadSprite> getBadnesses() {
        return badnesses;
    }
}
```
A classe Monstro estende BadnessBoxSprite e gerencia a Gosma como se fosse uma filha.

```java
@Override
public LinkedList<BadSprite> getBadnesses() {
    if(this.isCongelado() == true){
        return new LinkedList<>();
    } else {
        LinkedList<BadSprite> aGosma = new LinkedList<>();
        aGosma.add(gosma);
        return aGosma;
    }
}
```

### Elementos dos padrões Observer e Command

Pode ser observado um resquício do padrão **Observer** em que o jogo utiliza um sistema de notificação baseado em listener com ActionListener no ciclo do jogo.

```java
timer = new Timer(20, new GameCycle());

// And the GameCycle class:
public class GameCycle implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
        doGameCycle();
    }
}
```

Há também uma semelhança com o padrão Command no jeito que o controle do teclado funciona com o TAdapter, em que as teclas pressionadas são encapsuladas como comandos para ser executados pelo player.

```java
public class TAdapter extends KeyAdapter {
    @Override
    public void keyPressed(KeyEvent e) {
        for (Player player: players) {
            player.keyPressed(e);
            processOtherSprites(player, e);
        }
    }
}
```

---

## Conclusão

A arquitetura do jogo utiliza diversos padrões de projeto para garantir uma base de código flexível e de fácil manutenção. Os padrões mais evidentes são:

Template Method: definir a estrutura do algoritmo do loop do jogo.

Factory Method: criação de componentes específicos do jogo.

Composite: gerenciamento de hierarquias de objetos do tipo sprite.

Elementos dos padrões Observer, Command e Strategy: comportamentos relacionados à comunicação entre componentes e controle de entrada.

Essa abordagem baseada em frameworks permite a criação de diferentes jogos com uma arquitetura compartilhada, mas com comportamentos personalizados, como demonstrado pela implementação do Freeze Monster.

Além disso, o jogo base Space Invaders também continua funcionando, ou seja, a melhoria do framework feita com o desenvolvimento do Freeze Monsters não quebra nenhum jogo baseado nele.

---
