#pragma once
#include "../../Control/Control.h"

class ComboBox : public Control
{

private:
	vector<string> options;
	size_t selected;
	bool isOpened = false;

public:
	ComboBox(int, vector<string>);
	size_t GetSelectedIndex() { return this->selected; }
	void SetSelectedIndex(size_t index) { this->selected = index; }
	virtual void draw(Graphics, int, int, size_t);
	virtual bool canGetFocus() { return true; }
	virtual void mousePressed(int, int, DWORD);
	virtual void keyDown(int, char);
};