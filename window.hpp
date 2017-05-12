#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "widgets.hpp"
#include <vector>

using namespace std;

class Window
{
protected:
    vector<Widget*> widgets;
    string _neve;
    int _XX,_YY,_db;
    bool kov_jatekos;
public:
    Window(int XX,int YY,int db,string neve);
    void event_loop() ;
    void feltolt() ;
    void motor() ;
};



#endif // WINDOW_HPP_INCLUDED