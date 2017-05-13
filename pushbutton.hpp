#ifndef PUSHBUTTON_HPP_INCLUDED
#define PUSHBUTTON_HPP_INCLUDED

#include "widgets.hpp"

class PushButton : public Widget
{
    std::string _s;
    bool jatek;
public:
    PushButton(int x, int y, int sx, int sy, std::string s);
    void draw() const ;
    void torol() const ;
    void handle(genv::event ev);
    bool jateke() const
    {
        return jatek;
    }
};


#endif // PUSHBUTTON_HPP_INCLUDED
