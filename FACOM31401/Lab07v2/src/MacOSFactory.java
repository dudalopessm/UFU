public class MacOSFactory implements GUIFactory{
    @Override
    public Button criarButton() {
        return new ButtonMacOS();
    }

    @Override
    public Checkbox criarCheckbox() {
        return new CheckboxMacOS();
    }

    @Override
    public Scrollbar criarScrollbar() {
        return new ScrollbarMacOS();
    }
}