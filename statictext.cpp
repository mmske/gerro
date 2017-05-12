#include "statictext.hpp"
#include <string>
using namespace std;
using namespace genv;
StaticText::StaticText(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy)
{
    _s=s;
    voltmar=false;
}
void StaticText::draw() const
{
    gout << move_to(_x+15,_y+15) << color(255,255,255) << text(_s);
}
void StaticText::handle()
{
    if(_s=="X" || _s=="O")
        voltmar=true;
}
bool StaticText::is_voltmar() const
{
    return voltmar;
}

