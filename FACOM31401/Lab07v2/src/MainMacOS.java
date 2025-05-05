public class MainMacOS {
    public static void main(String[] args) {
        GUIFactory factory;

        factory = new MacOSFactory();

        Application app = new Application(factory);
        app.renderUI();
    }
}
