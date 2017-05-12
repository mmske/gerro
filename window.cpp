#include "window.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "iostream"
#include "typeinfo"
using namespace genv;
using namespace std;

Window::Window(int XX,int YY,int db,string neve):_XX(XX),_YY(YY),_db(db),_neve(neve)
{
    kov_jatekos=0;
}

void Window::feltolt()
{
    for(int i=0; i<_db; i++)
    {
        for(int j=0; j<_db; j++)
        {
            StaticText *tx[i*j];
            ExampleCheckBox *ex[i*j];
            ex[i*j]= new ExampleCheckBox(30*i,30*j,30,30);
            tx[i*j]=new StaticText(30*i,30*j,30,30," ");
            widgetsex.push_back(ex[i*j]);
            widgetstx.push_back(tx[i*j]);
        }
    }
}

void Window::motor()
{
    for(int i=0; i<widgetstx.size(); i++)
    {
        if(widgetsex[i]->is_checked() && kov_jatekos==true)
        {
            {
                for(int j=0; i<widgetstx.size(); j++)
                {
                    widgetstx[j]->setText(widgetstx[j]->value());
                }
                kov_jatekos=false;
            }
        }
        if(widgetsex[i]->is_checked() && kov_jatekos==false)
        {
            for(int j=0; i<widgetstx.size(); j++)
            {
                widgetstx[j]->setText(widgetstx[j]->value2());
            }
            kov_jatekos=true;
        }
    }
}


void Window::event_loop()
{
    gout.open(_XX,_YY);
    gout.set_title(_neve);
    event ev;
    unsigned int focus = -1;
    while(gin >> ev )
    {
        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0; i<widgetsex.size(); i++)
            {
                if (widgetsex[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        for (size_t i=0; i<widgetsex.size(); i++)
        {
            widgetsex[i]->draw();
            widgetstx[i]->draw();
        }
        if (focus!=-1)
        {
            widgetsex[focus]->handle(ev);
            widgetstx[focus]->handle(ev);
        }
        gout << refresh;
    }
}
