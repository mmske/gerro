#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "pushbutton.hpp"
#include "vegevan.hpp"
#include <vector>

using namespace std;

class Window
{
protected:
    vector<ExampleCheckBox*> widgetsex;
    vector<StaticText*> widgetstx;
    string _neve;
    int _XX,_YY,_db,sz;
    bool kov_jatekos,kilep,game;
public:
    Window(int XX,int YY,int db,string neve);
    void event_loop() ;
    void feltolt() ;
    void motor() ;
    void endjatek() ;
};

#endif // WINDOW_HPP_INCLUDED
