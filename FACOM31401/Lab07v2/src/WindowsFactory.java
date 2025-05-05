public class WindowsFactory implements GUIFactory {

    public Button criarButton() {
        return new ButtonWindows();
    }

    public Checkbox criarCheckbox() {
        return new CheckboxWindows();
    }

    public Scrollbar criarScrollbar() {
        return new ScrollbarWindows();
    }
}
