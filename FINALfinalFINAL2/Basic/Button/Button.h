#pragma once
#include "../../Control/Control.h"

class Button;

struct MouseListener{
  virtual void MousePressed(Button &b, int x, int y, bool isLeft) = 0;
};

class Button : public Control {

private:
  string value;
  MouseListener* listener;

public:
  Button(int);
  void SetValue(string value)         { this->value = value; }      
  string GetValue()                   { return this->value; }       
  void keyDown(int, char)             { this->graphics.clearScreen(); }
  void AddListener(MouseListener &listener) { this->listener = &listener; }
  bool canGetFocus()                  { return false; }            
  void mousePressed(int xPos, int yPos, DWORD button) { listener->MousePressed(*this, xPos, yPos, true); }
  void draw(Graphics, int, int, size_t);
};