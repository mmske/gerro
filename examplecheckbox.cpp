#include "examplecheckbox.hpp"
#include "graphics.hpp"

using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
}

void ExampleCheckBox::draw() const
{
    gout<<color(190,190,190)<<move_to(_x,_y) << box(_size_x,_size_y);
    gout<<color(50,80,80)<<move_to(_x+1,_y+1) << box(_size_x-2,_size_y-2);
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type==ev_mouse && is_selected(ev.pos_x,ev.pos_y) && ev.button==btn_left)
    {
        _checked=true;
    }
}
