ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = /usr/bin/i686-w64-mingw32-g++
endif

OBJS = mainTextBox.o TextBox.o

all: $(OBJS)
	$(CXX) $(OBJS) -o TextBox.exe -static
clean: rm -f *.o