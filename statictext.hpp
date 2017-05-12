#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class StaticText : public Widget
{
protected:
    std::string _s;
    bool voltmar;
public:
    StaticText(int x, int y, int sx, int sy, std::string s);
    virtual void draw() const ;
    virtual void handle() ;
    virtual bool is_voltmar() const ;
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
