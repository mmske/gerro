#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget
{
protected:
    bool _checked;

public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    bool is_checked() const
    {
        return _checked;
    }

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
