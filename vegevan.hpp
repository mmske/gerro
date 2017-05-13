#ifndef VEGEVAN_HPP_INCLUDED
#define VEGEVAN_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

using namespace std;

class Vegevan : public Widget
{
    string _s;
    int _b;
public:
    Vegevan(int x, int y, int sx, int sy,int b, string s);
    void draw() const;
};



#endif // VEGEVAN_HPP_INCLUDED
