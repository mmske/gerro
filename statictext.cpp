#include "statictext.hpp"
#include "graphics.hpp"
#include <string>

using namespace std;
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy)
{
    _s=s;
}
void StaticText::draw() const
{
    gout << move_to(_x+12,_y+18) << color(255,255,255) << text(_s);
}

