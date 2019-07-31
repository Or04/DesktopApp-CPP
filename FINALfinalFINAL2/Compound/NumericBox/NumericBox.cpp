#pragma once
#include <string>
#include "NumericBox.h"

NumericBox::NumericBox(int width, int min, int max)
{
	this->width = width;
	this->height = 3;
	this->min = min;
	this->max = max;
	this->showed = true;
}

void NumericBox::draw(Graphics g, int x, int y, size_t z)
{
	this->graphics.setBackground(this->background);
	this->graphics.setForeground(this->foreground);

	this->graphics.write(x, y + 1, "(-)");

	this->graphics.write(x + 3, y, "\xC9");
	for (int i = 0; i < this->getWidth() - 8; i++)
		graphics.write("\xCD");

	this->graphics.write("\xBB\n");
	this->graphics.write(x + 3, y + 1, "\xBA");
	this->graphics.write(x + this->getWidth() - 4, y + 1, "\xBA");
	this->graphics.write(x + 3, y + 2, "\xC8");

	for (int i = 0; i < this->getWidth() - 8; i++)
		this->graphics.write("\xCD");

	this->graphics.write("\xBC");

	string val = to_string(this->value);
	this->graphics.write(x + this->getWidth() / 2, y + 1, val);

	this->graphics.write(x + this->getWidth() - 3, y + 1, "(+)");

	this->graphics.setForeground(Color::White);
	this->graphics.setBackground(Color::Black);
}

void NumericBox::mousePressed(int x, int y, DWORD button)
{
	this->graphics.setCursorVisibility(true);
	this->graphics.moveTo(x, y);

	if (x == this->getLeft() + 1)
		if (this->value > this->min)
			this->SetValue(this->value - 1);

	if (x == (this->getLeft() + this->getWidth() - 2))
		if (this->value < this->max)
			this->SetValue(this->value + 1);
}
