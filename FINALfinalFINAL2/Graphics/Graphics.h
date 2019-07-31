#pragma once
#include <string>
#include <Windows.h>

using namespace std;

enum class Color
{
	Black,
	Blue,
	Green,
	Red,
	Cyan,
	Purple,
	Orange,
	White
};

bool isInside(int x, int y, int left, int top, int width, int height);
class Graphics
{
public:
	Graphics(DWORD stdHandle = STD_OUTPUT_HANDLE);
	void clearScreen();
	void moveTo(int x, int y);
	void setBackground(Color color);
	void setForeground(Color color);
	void write(int x, int y, string s);
	void write(wstring s);
	void write(string s);
	void write(int x, int y, wstring s);
	void setCursorVisibility(bool isVisible);

private:
	HANDLE _console;
	Color background, foreground;
	void updateConsoleAttributes();
};