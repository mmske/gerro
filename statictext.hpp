#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

using namespace genv;
using namespace std;

class StaticText : public Widget
{
protected:
    string _s;
public:
    StaticText(int x, int y, int sx, int sy, string s);
    void draw() const ;
    void setText(string s)
    {
        _s=s;
    }
    string getText()
    {
        return _s;
    }
};


#endif // STATICTEXT_HPP_INCLUDED
