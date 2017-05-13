#include "statictext.hpp"
#include "graphics.hpp"
#include <string>

using namespace std;
using namespace genv;

StaticText::StaticText(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy)
{
    _s=s;
    xvolt=false;
    ovolt=false;
    voltmar=false;
}
void StaticText::draw() const
{
    gout << move_to(_x+15,_y+15) << color(255,255,255) << text(_s);
}
void StaticText::vizsgal()
{
    if(_s!=" ")
    {
        voltmar=true;
    }
}
bool StaticText::x_volt()
{
    if(_s=="X")
    {
        xvolt=true;
        return xvolt;
    }
}
bool StaticText::o_volt()
{
    if(_s=="O")
    {
        ovolt=true;
        return ovolt;
    }
}

