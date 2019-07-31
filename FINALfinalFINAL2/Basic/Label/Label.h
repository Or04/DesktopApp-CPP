#pragma once
#include "../../Control/Control.h"

class Label : public Control
{
  private:
    int width;
    int height = 3;
    string value = "default value";

  public:
    Label(int);
    void SetValue(string value)         { this->value = value; }
    string GetValue()                   { return this->value; }
    void keyDown(int, char)             {};
    void mousePressed(int, int, DWORD)  {};
    bool canGetFocus()                  { return false; }
    void draw(Graphics, int, int, size_t);
};