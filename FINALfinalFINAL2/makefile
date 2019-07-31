ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = /usr/bin/i686-w64-mingw32-g++
endif

OBJS = main.o ./Basic/Button/Button.o ./Basic/Label/Label.o ./Basic/Panel/Panel.o ./Basic/TextBox/TextBox.o ./Compound/CheckList/CheckList.o ./Compound/ComboBox/ComboBox.o ./Compound/NumericBox/NumericBox.o ./Compound/RadioBox/RadioBox.o ./Control/Control.o ./EventEngine/EventEngine.o ./Graphics/Graphics.o

all: $(OBJS)
	$(CXX) $(OBJS) -o MAIN.exe -static
clean: rm -f *.o