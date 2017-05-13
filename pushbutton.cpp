#include "pushbutton.hpp"

using namespace std;
using namespace genv;

PushButton::PushButton(int x, int y, int sx, int sy, string s,bool jatek): Widget(x,y,sx,sy)
{
    _s=s;
    _jatek=jatek;
}

void PushButton::draw() const
{
    gout<<color(255,255,255)<<move_to(_x-2, _y-2)<<box(_size_x+4, _size_y+4);
    gout<<color(30,30,30)<<move_to(_x, _y)<<box(_size_x, _size_y);
    gout<<color(255,255,255)<<move_to(_x+5, _y+20)<< text(_s);
}
void PushButton::torol()
{
    gout<<color(0,0,0)<<move_to(_x-2, _y-2)<<box(_size_x+4, _size_y+4);
}

void PushButton::handle(genv::event ev)
{
    if (is_selected(ev.pos_x,ev.pos_y) && ev.type==ev_mouse && ev.button==btn_left)
    {
        _jatek=true;
    }
}

