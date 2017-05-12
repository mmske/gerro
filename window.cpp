#include "window.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "iostream"
using namespace genv;
using namespace std;

Window::Window(int XX,int YY,int db,string neve):_XX(XX),_YY(YY),_db(db),_neve(neve)
{
    kov_jatekos=true;
}

void Window::feltolt()
{
    for(size_t i=0; i<_db; i++)
    {
        for(size_t j=0; j<_db; j++)
        {
            StaticText *tx[i*j];
            ExampleCheckBox *ex[i*j];
            ex[i*j]= new ExampleCheckBox(30*i,30*j,30,30);
            tx[i*j]=new StaticText(30*i,30*j,30,30," ");
            widgets.push_back(ex[i*j]);
            widgets.push_back(tx[i*j]);
        }
    }
}

void Window::motor()
{
    for(size_t i=0; i<widgets.size(); i++)
    {
        if((tx*)widgets[i]->is_checked() && kov_jatekos==true)
            {
                tx->setText(tx->value());
                kov_jatekos==false;
            }
            if(ex->is_checked==true && kov_jatekos==false)
            {
                tx->setText(tx->value2());
                kov_jatekos==true;
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
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}
