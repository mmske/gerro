#include "vegevan.hpp"
#include <string>

using namespace std;
using namespace genv;

Vegevan::Vegevan(int x, int y, int sx, int sy,int b, string s) : Widget(x,y,sx,sy)
{
    _s=s;
    _b=b;
}
void Vegevan::draw() const
{
    gout<<move_to(_x,_y)<<color(_size_x,_size_y,_b)<<text(_s);
}
