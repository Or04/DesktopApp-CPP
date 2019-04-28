#include <iostream>
#include "CheckList.h"

CheckList::CheckList(COORD pos, string description) : position(pos)
{
	this->bg = 0;
	this->fg = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	this->description = description;
}
COORD CheckList::nextLinePos(COORD position)
{
	position.Y++;
	return position;
}
void CheckList::set_fg(DWORD fg)
{
	this->fg = fg;
}

void CheckList::set_bg(DWORD bg)
{
	this->bg = bg;
}
void CheckList::makeBox()
{
	void *output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(output, &info);
	SetConsoleCursorPosition(output, this->position);
	SetConsoleTextAttribute(output, this->fg | this->bg);
	std::cout << "\xDA"
				 "\xC4"
				 "\xC4"
				 "\xC4"
				 "\xBF";
	SetConsoleCursorPosition(output, this->nextLinePos(this->position));
	std::cout << "\xB3"
				 "   "
				 "\xB3" +
					 description;
	SetConsoleCursorPosition(output, this->nextLinePos(this->nextLinePos(this->position)));
	std::cout << "\xC0"
				 "\xC4"
				 "\xC4"
				 "\xC4"
				 "\xD9";
	SetConsoleCursorPosition(output, this->nextLinePos(this->position));
}