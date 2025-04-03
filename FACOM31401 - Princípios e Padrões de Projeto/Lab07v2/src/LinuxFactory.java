public class LinuxFactory implements GUIFactory{

    @Override
    public Button criarButton() {
        return new ButtonLinux();
    }

    @Override
    public Checkbox criarCheckbox() {
        return new CheckboxLinux();
    }

    @Override
    public Scrollbar criarScrollbar() {
        return new ScrollbarLinux();
    }
}
