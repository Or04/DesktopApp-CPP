#include "TextBox.h"

#define SPACE 32

bool checkChar(int character);
COORD getCursorPosition();

TextBox::TextBox(short width, short top, short left, std::string value)
    : WIDTH(width), TOP(top), LEFT(left), value(value), HAS_BORDER(true),
      color(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY),
      background(0) {}

void TextBox::onKeyboardPress(KEY_EVENT_RECORD &event)
{
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!event.bKeyDown)
        return;

    if (checkChar(event.wVirtualKeyCode))
    {
        if (value.length() == (WIDTH - 1))
            WIDTH += 2;

        COORD cursorPosition = getCursorPosition();
        auto cursorPosX = cursorPosition.X - (LEFT + 1);
        cursorPosition.X += 1;

        value.insert(cursorPosX, 1, event.uChar.AsciiChar);
        draw();
        SetConsoleCursorPosition(handle, cursorPosition);

        return;
    }

    if (event.wVirtualKeyCode == VK_LEFT || event.wVirtualKeyCode == VK_RIGHT)
    {
        int textWidth = value.length();
        COORD cursorPosition = getCursorPosition();

        if ((cursorPosition.X > LEFT) && (cursorPosition.X < WIDTH + LEFT + 1))
        {
            if (event.wVirtualKeyCode == VK_LEFT)
            {
                if (cursorPosition.X == LEFT + 1)
                    return;
                SetConsoleCursorPosition(handle, {cursorPosition.X - 1, cursorPosition.Y});
            }
            if (event.wVirtualKeyCode == VK_RIGHT)
            {
                if (cursorPosition.X > value.length() + LEFT)
                    return;
                if (cursorPosition.X == WIDTH + LEFT)
                    return;
                SetConsoleCursorPosition(handle, {cursorPosition.X + 1, cursorPosition.Y});
            }
        }
    }
    if (event.wVirtualKeyCode == VK_BACK)
    {
        COORD cursorPosition = getCursorPosition();
        auto cursorPosX = cursorPosition.X - (LEFT + 1);
        cursorPosition.X -= 1;
        if (value.length() == 0 || cursorPosX == 0)
            return;
        value.erase(cursorPosX - 1, 1);
        draw();
        SetConsoleCursorPosition(handle, cursorPosition);
    }
}

void TextBox::onMousePress(MOUSE_EVENT_RECORD &event)
{
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (event.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
    {
        COORD cursorPosition = getCursorPosition();
        if (event.dwMousePosition.Y == 1 && (event.dwMousePosition.X > LEFT && event.dwMousePosition.X < WIDTH + LEFT))
        {
            if (event.dwMousePosition.X > LEFT + value.length())
            {
                SetConsoleCursorPosition(handle, {LEFT + value.length() + 1, event.dwMousePosition.Y});
                return;
            }
            SetConsoleCursorPosition(handle, {event.dwMousePosition.X, event.dwMousePosition.Y});
        }
        return;
    }
}
COORD getCursorPosition()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(handle, &info);
    return info.dwCursorPosition;
}

void TextBox::draw()
{
    COORD coord = {LEFT, TOP};
    auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
    SetConsoleTextAttribute(handle, color | (background << 4));
    std::cout << (char)0xda;
    for (int i = 0; i < WIDTH; i++)
        std::cout << (char)0xc4;
    std::cout << (char)0xbf;

    SetConsoleCursorPosition(handle, {coord.X, coord.Y + 1});
    std::cout << (char)0xb3;

    for (int i = 0; i < WIDTH; i++)
        std::cout << (i <= value.length() ? value[i] : ' ');

    SetConsoleCursorPosition(handle, {LEFT + WIDTH + 1, TOP + 1});
    std::cout << (char)0xb3;

    SetConsoleCursorPosition(handle, {LEFT, TOP + 2});
    std::cout << (char)0xc0;
    for (int i = 0; i < WIDTH; i++)
        std::cout << (char)0xc4;
    std::cout << (char)0xd9;

    SetConsoleCursorPosition(handle, {LEFT + 1 + value.length(), TOP + 1});
}
bool checkChar(int character)
{
    if (((character >= 0x30) && (character <= 0x5a)) || character == SPACE)
        return true;
    return false;
}