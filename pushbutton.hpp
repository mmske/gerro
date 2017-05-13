#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"

class PushButton : public Widget
{
    std::string _s;
    bool _jatek;
public:
    PushButton(int x, int y, int sx, int sy, std::string s,bool jatek);
    void draw() const ;
    void torol() ;
    void handle(genv::event ev);
    bool getJatek()
    {
        return _jatek;
    }
    void setJatek(bool jatek)
    {
        _jatek=jatek;
    }

};

#endif // PUSHBUTTON_HPP_INCLUDED
