public class MainLinux {
    public static void main(String[] args) {
        GUIFactory factory;

        factory = new LinuxFactory();

        Application app = new Application(factory);
        app.renderUI();
    }
}
