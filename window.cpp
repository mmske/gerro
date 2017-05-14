#include "window.hpp"
#include "statictext.hpp"
#include "examplecheckbox.hpp"
#include "pushbutton.hpp"
#include "vegevan.hpp"

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
    game=true;
    ures=0;
}

void Window::feltolt()
{
    for(int i=0; i<=_db; i++)
    {
        for(int j=0; j<_db; j++)
        {
            StaticText *tx[i*j];
            ExampleCheckBox *ex[i*j+1];
            ex[i*j]= new ExampleCheckBox(30*i,30*j,30,30);
            tx[i*j]= new StaticText(30*i,30*j,30,30," ");
            widgetsex.push_back(ex[i*j]);
            widgetstx.push_back(tx[i*j]);
        }
    }
}
void Window::endjatek(string XvagyO)
{
    Vegevan *vg=new Vegevan(100,700,255,255,255,XvagyO);
    Vegevan *vg2;
    if(XvagyO=="X" || XvagyO=="X")
    {
        vg2=new Vegevan(100+gout.twidth(XvagyO)+4,700,255,255,255,"jat�kos nyert!");
    }
    vg->draw();
    vg2->draw();
    kilep=false;
}
void Window::motor()
{
    string XvagyO="";
    for(int i=0; i<_db*_db; i++)
    {
        if(widgetsex[i]->is_checked() && kov_jatekos==true && widgetstx[i]->getText()==" " )
        {
            widgetstx[i]->setText("X");
            kov_jatekos=false;
            XvagyO="X";
        }
        else if(widgetsex[i]->is_checked() && kov_jatekos==false && widgetstx[i]->getText()==" ")
        {
            widgetstx[i]->setText("O");
            kov_jatekos=true;
            XvagyO="O";
        }
    }
    for(int i=0; i<(_db*_db); i++)
    {
        if(widgetstx[i]->getText()==XvagyO && widgetstx[i+1]->getText()==XvagyO
                && widgetstx[i+2]->getText()==XvagyO && widgetstx[i+3]->getText()==XvagyO
                && widgetstx[i+4]->getText()==XvagyO)
        {
            endjatek(XvagyO);
        }
    }
    for(int i=0; i<(_db*_db); i++)
    {
        if(widgetstx[i]->getText()==XvagyO && widgetstx[i+_db]->getText()==XvagyO
                && widgetstx[i+2*_db]->getText()==XvagyO && widgetstx[i+3*_db]->getText()==XvagyO
                && widgetstx[i+4*_db]->getText()==XvagyO)
        {
            endjatek(XvagyO);
        }
    }
    for(int i=0; i<(_db*_db); i++)
    {
        if(widgetstx[i]->getText()==XvagyO && widgetstx[(i+_db)+1]->getText()==XvagyO
                && widgetstx[(i+2*_db)+2]->getText()==XvagyO && widgetstx[(i+3*_db)+3]->getText()==XvagyO
                && widgetstx[(i+4*_db)+4]->getText()==XvagyO)
        {
            endjatek(XvagyO);
        }
    }
    for(int i=0; i<(_db*_db); i++)
    {
        if(widgetstx[i]->getText()==XvagyO && widgetstx[(i+_db)-1]->getText()==XvagyO
                && widgetstx[(i+2*_db)-2]->getText()==XvagyO && widgetstx[(i+3*_db)-3]->getText()==XvagyO
                && widgetstx[(i+4*_db)-4]->getText()==XvagyO)
        {
            endjatek(XvagyO);
        }
    }
    for(int i=0; i<_db*_db-1; i++)
    {
        if(widgetstx[i]->getText()==" ")
        {
            ures++;
        }
    }
    if(ures==0)
    {
        endjatek("Megtelt a p�lya!");
    }
}
void Window::event_loop()
{
    gout.open(_XX,_YY);
    gout.set_title(_neve);
    event ev;
    int focus=-1;
    PushButton *pb;
    PushButton *pb2;
    pb=new PushButton(650,50,80,30,"J�t�k",false);
    pb2=new PushButton(650,50,80,30,"Kil�p�s",false);
    while(gin>>ev && game)
    {
        if(kilep==false)
        {
            pb2->draw();
            pb2->handle(ev);
            if(pb2->getJatek()==true)
            {
                game=false;
            }
        }
        else
        {
            if (ev.type==ev_mouse)
            {
                for (int i=0; i<_db*_db; i++)
                {
                    if (widgetsex[i]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        focus = i;
                    }
                }
            }
            motor();
            if (focus!=-1)
            {
                widgetsex[focus]->handle(ev);
            }
            for (int i=0; i<_db*_db; i++)
            {
                pb->draw();
                pb->handle(ev);
                if(pb->getJatek()==true)
                {
                    pb->torol();
                    widgetsex[i]->draw();
                    widgetstx[i]->draw();
                }
            }
        }
        gout<<refresh;
    }
}
