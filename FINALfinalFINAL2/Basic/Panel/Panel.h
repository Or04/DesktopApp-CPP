#pragma once
#include "../../Control/Control.h"

class Panel : public Control {
 
private:
	vector<Control*> controls;

public:
	Panel(int, int);
	void getAllControls(vector <Control*>* myControls)	{ *myControls = this->controls; }
	void keyDown(int, char)								              {}
	void addControl(Control&, int, int);
	void draw(Graphics, int, int, size_t);
	bool canGetFocus()									                { return false; }
	void mousePressed(int, int, DWORD);
};
