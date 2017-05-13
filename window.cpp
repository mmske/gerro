#include "window.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "pushbutton.hpp"
#include "iostream"

using namespace genv;
using namespace std;

Window::Window(int XX,int YY,int db,string neve)
{
    _XX=XX;
    _YY=YY;
    _db=db;
    _neve=neve;
    kov_jatekos=true;
    kilep=true;
    sz=0;
}

void Window::feltolt()
{
    PushButton *pb;
    PushButton *pb2;
    pb=new PushButton(650,50,80,30,"Új játék");
    pb2=new PushButton(650,50,80,30,"Kilépés");
    widgetspb.push_back(pb);
    widgetspb.push_back(pb2);
    for(int i=0; i<_db; i++)
    {
        for(int j=0; j<_db; j++)
        {
            StaticText *tx[i*j];
            ExampleCheckBox *ex[i*j];
            ex[i*j]= new ExampleCheckBox(30*i,30*j,30,30);
            tx[i*j]= new StaticText(30*i,30*j,30,30," ");
            widgetsex.push_back(ex[i*j]);
            widgetstx.push_back(tx[i*j]);
        }
    }
}

void Window::motor()
{
    for(size_t i=0; i<widgetstx.size(); i++)
    {
        if(widgetsex[i]->is_checked() && kov_jatekos==true && widgetstx[i]->getText()==" " )
        {
            widgetstx[i]->setText("X");
            kov_jatekos=false;
        }
        else if(widgetsex[i]->is_checked() && kov_jatekos==false && widgetstx[i]->getText()==" ")
        {
            widgetstx[i]->setText("O");
            kov_jatekos=true;
        }
    }
}

void Window::soroszlop()
{
    for(size_t i=0; i<widgetstx.size(); i++)
    {
        if(widgetstx[i]->getText()=="O" && widgetstx[i+1]->getText()=="O")
        {
            sz++;
            cout<<sz<<endl;
        }
    }
}

void Window::event_loop()
{
    gout.open(_XX,_YY);
    gout.set_title(_neve);
    event ev;
    int focus = -1;
    while(gin >> ev && kilep==true)
    {
        motor();
        soroszlop();
        if (ev.type == ev_mouse)
        {
            for (size_t i=0; i<widgetsex.size(); i++)
            {
                if (widgetsex[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgetsex[focus]->handle(ev);
        }
        for (size_t i=0; i<widgetsex.size(); i++)
        {

            widgetspb[0]->draw();
            widgetspb[0]->handle(ev);
            if(widgetspb[0]->jateke()==true)
            {
                widgetspb[1]->draw();
                widgetspb[1]->handle(ev);
                if(widgetspb[1]->jateke()==false)
                {
                    kilep=false;
                }
                widgetsex[i]->draw();
                widgetstx[i]->draw();
            }
        }
        gout << refresh;
    }
}
