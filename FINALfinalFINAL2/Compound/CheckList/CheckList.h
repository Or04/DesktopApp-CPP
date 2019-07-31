#pragma once
#include "../../Control/Control.h"

class CheckList : public Control
{
protected:
	vector<string> options;
	vector<size_t> checked;

public:
	CheckList(int, int, vector<string>);
	vector<size_t> GetSelectedIndices() { return this->checked; }
	void draw(Graphics, int, int, size_t);
	void keyDown(int, char);
	inline bool canGetFocus() { return true; }
	void mousePressed(int, int, DWORD);
	void DeselectIndex(size_t index) { this->checked[index] = 0; }
	void SelectIndex(size_t index) { this->checked[index] = 1; }
};
