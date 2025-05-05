public class Main {
    public static void main(String[] args) {
        GUIFactory factory;

        factory = new WindowsFactory();

        Application app = new Application(factory);
        app.renderUI();
    }
}