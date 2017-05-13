#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED

#include "examplecheckbox.hpp"
#include "statictext.hpp"
#include "pushbutton.hpp"
#include <vector>

using namespace std;

class Window
{
protected:
    vector<ExampleCheckBox*> widgetsex;
    vector<StaticText*> widgetstx;
    vector<PushButton*> widgetspb;
    string _neve;
    int _XX,_YY,_db,sz;
    bool kov_jatekos,kilep;
public:
    Window(int XX,int YY,int db,string neve);
    void event_loop() ;
    void feltolt() ;
    void motor() ;
    void soroszlop() ;
};

#endif // WINDOW_HPP_INCLUDED
