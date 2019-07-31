#pragma once
#include "CheckList.h"

CheckList::CheckList(int height, int width, vector<string> options)
{
	this->height = height;
	this->width = width;
	this->options = options;
	this->checked = {0, 0, 0};
	this->showed = true;
}

void CheckList::draw(Graphics g, int x, int y, size_t z)
{
	graphics.setBackground(this->background);
	graphics.setForeground(this->foreground);

	for (int i = 0; i < this->options.size(); i++)
	{
		if (this->checked[i] == 1)
		{
			graphics.write(x, y + i, "(*)");
			graphics.write(x + 7, y + i, this->options[i]);
		}
		if (this->checked[i] == 0)
		{
			graphics.write(x + 7, y + i, this->options[i]);
			graphics.write(x, y + i, "( )");
		}
	}
}

void CheckList::keyDown(int keyCode, char c)
{
	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
		int _char = getchar();

		do
		{
			if (_char == VK_TAB)
				break;
			switch (this->checked[i])
			{
			case 1:
				this->checked[i] = 0;
				putchar(' ');
				break;
			case 0:
				this->checked[i] = 1;
				putchar('*');
				break;
			}
			break;
		} while (_char != VK_TAB);
	}
}

void CheckList::mousePressed(int x, int y, DWORD btn)
{
	for (int i = 0; i < this->getHeight(); i++)
	{
		if (x == (this->getLeft() + 1) && y == (this->getTop() + i))
		{
			graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
			switch (this->checked[i])
			{
			case 1:
				this->checked[i] = 0;
				putchar(' ');
				break;
			case 0:
				this->checked[i] = 1;
				putchar('*');
				break;
			}
			break;
		}
	}
}
