#include "TextBox.h"

HANDLE handle;
DWORD fdwSaveOldMode;
VOID ErrorExit(LPSTR);

int main(int argc, char const *argv[])
{

    DWORD cNumRead, fdwMode, i;
    INPUT_RECORD ir;
    DWORD count;
    handle = GetStdHandle(STD_INPUT_HANDLE);
    if (handle == INVALID_HANDLE_VALUE)
        ErrorExit("GetStdHandle");
    if (!GetConsoleMode(handle, &fdwSaveOldMode))
        ErrorExit("GetConsoleMode");
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(handle, fdwMode);
    TextBox tb(8, 0, 4, "hello");
    tb.draw();
    while (1)
    {
        if (!ReadConsoleInput(handle, &ir, 1, &count))
            ErrorExit("ReadConsoleInput");
        if (count)
        {
            if (ir.EventType == KEY_EVENT)
                tb.onKeyboardPress(ir.Event.KeyEvent);
            if (ir.EventType == MOUSE_EVENT)
                tb.onMousePress(ir.Event.MouseEvent);
        }
    }
    SetConsoleMode(handle, fdwSaveOldMode);
    return 0;
}

VOID ErrorExit(LPSTR lpszMessage)
{
    fprintf(stderr, "%s\n", lpszMessage);
    SetConsoleMode(handle, fdwSaveOldMode);
    ExitProcess(0);
}