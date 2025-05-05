public class Application {
    private Button button;
    private Checkbox checkbox;
    private Scrollbar scrollbar;

    public Application(GUIFactory guiFactory) {
        this.button = guiFactory.criarButton();
        this.checkbox = guiFactory.criarCheckbox();
        this.scrollbar = guiFactory.criarScrollbar();
    }

    public void renderUI(){
        button.paint();
        checkbox.paint();
        scrollbar.paint();
    }
}
