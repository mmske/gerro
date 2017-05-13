#include "window.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "iostream"

using namespace genv;
using namespace std;

Window::Window(int XX,int YY,int db,string neve):_XX(XX),_YY(YY),_db(db),_neve(neve)
{
    kov_jatekos=true;
    sz=0;
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
        if(widgetsex[i]->is_checked() && kov_jatekos==true && widgetstx[i]->is_voltmar()==false)
        {
            widgetstx[i]->setText(widgetstx[i]->value());
            kov_jatekos=false;
        }
        else if(widgetsex[i]->is_checked() && kov_jatekos==false && widgetstx[i]->is_voltmar()==false)
        {
            widgetstx[i]->setText(widgetstx[i]->value2());
            kov_jatekos=true;
        }
    }
}

void Window::soroszlop()
{
    vector<StaticText*> sor;
    sor.clear();
    vector<StaticText*> oszlop;
    oszlop.clear();
    for(int i=0; i<_db; i++)
    {
        for(int j=0; j<_db; j++)
        {
            if(widgetstx[i*_db+j]->o_volt())
            {
                sor.push_back(widgetstx[i*_db+j]);
                if(sor.size()>=5)
                {
                    cout<<sor.size();
                }
            }
            else if(widgetstx[j*_db+i]->o_volt())
            {
                oszlop.push_back(widgetstx[j*_db+i]);
                if(oszlop.size()>=5)
                {
                    cout<<oszlop.size();
                }
            }
//            if(widgetstx[j*_db+i]->o_volt())
//            {
//                cout<<(j*_db+i)<<endl;
//            }
//            if(widgetstx[j*_db+i]->o_volt())
//            {
//                cout<<(j*_db+i)<<endl;
//            }
        }
    }
}


void Window::event_loop()
{
    gout.open(_XX,_YY);
    gout.set_title(_neve);
    event ev;
    unsigned int focus = -1;
    while(gin >> ev || !sz==5)
    {
        if (ev.type == ev_mouse)
        {
            for (size_t i=0; i<widgetsex.size(); i++)
            {
                if (widgetsex[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
                if(ev.type==ev_mouse && widgetsex[i]->is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left)
                {
                    soroszlop();
                }
            }
        }
        if (focus!=-1)
        {
            widgetsex[focus]->handle(ev);
        }
        for (size_t i=0; i<widgetsex.size(); i++)
        {
            widgetsex[i]->draw();
            widgetstx[i]->draw();
        }
        motor();
        gout << refresh;
    }
}
