#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class StaticText : public Widget
{
protected:
    std::string _s;
    bool voltmar;
    bool xvolt;
    bool ovolt;
public:
    StaticText(int x, int y, int sx, int sy, std::string s);
    virtual void draw() const ;
    virtual void vizsgal() ;
    bool x_volt();
    bool o_volt();
    virtual bool is_voltmar() const
    {
        return voltmar;
    }
    void setText(std::string s)
    {
        _s=s;
    }
    inline std::string value()
    {
        _s="X";
        return _s;
    }
    inline std::string value2()
    {
        _s="O";
        return _s;
    }
};


#endif // STATICTEXT_HPP_INCLUDED
