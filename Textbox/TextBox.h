#include <string>
#include <windows.h>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class TextBox
{
public:
  short WIDTH;
  const short TOP;
  const short LEFT;
  const bool HAS_BORDER;
  const WORD color;
  const WORD background;

  std::string value;
  TextBox(short width, short top, short left, std::string value);
  void onKeyboardPress(KEY_EVENT_RECORD &);
  void onMousePress(MOUSE_EVENT_RECORD &);
  void draw();

private:
  void putChar();
};