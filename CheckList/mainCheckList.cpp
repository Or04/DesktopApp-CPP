#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "CheckList.h"
using namespace std;
//
const int boxesAmount = 3;
const COORD initCoords[boxesAmount] = {{5, 5}, {5, 9}, {5, 13}};
const COORD printCoords[boxesAmount] = {{5 + 2, 5 + 1}, {5 + 2, 9 + 1}, {5 + 2, 13 + 1}};
//
int mapPrintCoordsToItem(int Y)
{
	for (int i = 0; i < boxesAmount; i++)
		if (printCoords[i].Y == Y)
			return i;
	return 0;
}
//
int main(int argc, char **argv)
{
	CheckList box1(initCoords[0], " Item 1");
	CheckList box2(initCoords[1], " Item 2");
	CheckList box3(initCoords[2], " Item 3");

	box1.makeBox();
	box2.makeBox();
	box3.makeBox();

	void *input = GetStdHandle(STD_INPUT_HANDLE);
	void *output = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD modes;
	modes = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(input, modes);

	DWORD char1;
	DWORD char2;
	char *keyBuffer = new char[2];
	char *mouseBuffer = new char[2];

	SetConsoleCursorPosition(output, {0, 0});
	int AtItem = 0;
	SetConsoleCursorPosition(output, {printCoords[AtItem].X, printCoords[AtItem].Y});
	while (1)
	{
		INPUT_RECORD ir;
		DWORD count;
		ReadConsoleInput(input, &ir, 1, &count);
		switch (ir.EventType)
		{
		case MOUSE_EVENT:
		{
			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				for (size_t i = 0; i < boxesAmount; i++)
				{
					if (ir.Event.MouseEvent.dwMousePosition.X == printCoords[i].X && ir.Event.MouseEvent.dwMousePosition.Y == printCoords[i].Y)
					{
						COORD pos = {printCoords[i].X, printCoords[i].Y};
						AtItem = mapPrintCoordsToItem(pos.Y);
						SetConsoleCursorPosition(output, {pos.X, pos.Y});
						ReadConsoleOutputCharacter(output, mouseBuffer, 2, pos, &char2);
						if (mouseBuffer[0] != 'X')
							cout << "X";
						if (mouseBuffer[0] == 'X')
							cout << "  ";
						SetConsoleCursorPosition(output, {pos.X, pos.Y});
					}
				}
			}
		}
		case KEY_EVENT:
		{
			if (ir.Event.KeyEvent.bKeyDown)
			{
				if (ir.Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
				{
					AtItem = ++AtItem % boxesAmount;
					SetConsoleCursorPosition(output, {printCoords[AtItem].X, printCoords[AtItem].Y});
				}
				else if (ir.Event.KeyEvent.wVirtualKeyCode == VK_UP)
				{
					AtItem = --AtItem % boxesAmount;
					AtItem = AtItem == -1 ? boxesAmount - 1 : AtItem;
					SetConsoleCursorPosition(output, {printCoords[AtItem].X, printCoords[AtItem].Y});
				}
				else if (ir.Event.KeyEvent.wVirtualKeyCode == VK_SPACE)
				{
					ReadConsoleOutputCharacter(output, keyBuffer, 2, {printCoords[AtItem].X, printCoords[AtItem].Y}, &char1);
					if (keyBuffer[0] != 'X')
						cout << "X";
					if (keyBuffer[0] == 'X')
						cout << "  ";
					SetConsoleCursorPosition(output, {printCoords[AtItem].X, printCoords[AtItem].Y});
				}
			}
		}
		}
	}
	cin.get();
}
