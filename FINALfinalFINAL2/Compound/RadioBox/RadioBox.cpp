#pragma once
#include "RadioBox.h"

RadioBox::RadioBox(int height, int width, vector<string> options) : CheckList(height, width, options)
{
	this->toCheck = 0;
	this->height = height;
	this->width = width;
	this->options = options;
	this->showed = true;
}

void RadioBox::draw(Graphics g, int x, int y, size_t z)
{
	this->graphics.setBackground(this->background);
	this->graphics.setForeground(this->foreground);

	for (int i = 0; i < this->options.size(); i++)
	{
		if (this->toCheck == i)
		{
			this->graphics.write(x, y + i, "(*)");
			this->graphics.write(x + 7, y + i, this->options[i]);
		}
		else
		{
			this->graphics.write(x, y + i, "( )");
			this->graphics.write(x + 7, y + i, this->options[i]);
		}
	}
	this->graphics.setForeground(Color::White);
	this->graphics.setBackground(Color::Black);
}

void RadioBox::keyDown(int keyCode, char character)
{
	this->graphics.setCursorVisibility(true);

	for (int i = 0; i < this->options.size(); i++)
	{
		this->graphics.moveTo(this->getLeft() + 1, this->getTop() + i);
		int c = 0;
		c = getchar();
		do
		{
			if (c == VK_TAB)
				break;
			this->toCheck = 1;
			putchar('*');
			for (int j = 0; j < this->options.size(); j++)
			{
				if (i != j)
				{
					this->toCheck = 0;
					this->graphics.moveTo(this->getLeft() + 1, this->getTop() + j);
					putchar(' ');
				}
				break;
			}
			break;
		} while (c != VK_TAB);
	}
}

void RadioBox::mousePressed(int a, int b, DWORD button)
{
	for (int i = 0; i < this->getHeight(); i++)
	{
		if (a == (this->getLeft() + 1) && b == (this->getTop() + i))
		{
			this->graphics.moveTo(this->getLeft() + 1, this->getTop() + i);

			if (this->toCheck != i)
			{
				this->graphics.moveTo(this->getLeft() + 1, this->getTop() + this->toCheck);

				putchar(' ');
				this->toCheck = i;
				this->graphics.moveTo(this->getLeft() + 1, this->getTop() + i);

				putchar('*');
			}
			break;
		}
	}
};
