#pragma once
#include "../../Control/Control.h"

class NumericBox : public Control
{
private:
	int min, max, value = 0;

public:
	NumericBox(int, int, int);
	void SetValue(int value) { this->value = value; }
	int GetValue() { return this->value; }
	void keyDown(int, char) {}
	void mousePressed(int, int, DWORD);
	bool canGetFocus() { return false; }
	void draw(Graphics, int, int, size_t);
};