#include <string>
#include <Windows.h>

using namespace std;

class CheckList
{
  private:
	//coordinations
	COORD position;
	//double word, like unsigned int
	//important for Windows.h
	DWORD bg;
	DWORD fg;
	string description;

  public:
	CheckList(COORD pos, string description);
	COORD nextLinePos(COORD position);
	void set_bg(DWORD bg);
	void set_fg(DWORD fg);
	void makeBox();
	~CheckList(){};
};
