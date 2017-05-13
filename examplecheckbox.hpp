#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "widgets.hpp"

using namespace genv;

class ExampleCheckBox : public Widget
{
protected:
    bool _checked;

public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    void draw() const ;
    void handle(event ev);
    bool is_checked() const
    {
        return _checked;
    }

};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
