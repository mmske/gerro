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
            tx[i*j]= new StaticText(30*i,30*j,30,30," ");
            widgetsex.push_back(ex[i*j]);
            widgetstx.push_back(tx[i*j]);
        }
    }
}

void Window::endjatek()
{
    Vegevan *vg=new Vegevan(100,700,255,255,255,"Vege a jateknak!");
    vg->draw();
    kilep=false;
}

void Window::motor()
{
    string xvagyy="";
    for(size_t i=0; i<widgetstx.size(); i++)
    {
        if(widgetsex[i]->is_checked() && kov_jatekos==true && widgetstx[i]->getText()==" " )
        {
            widgetstx[i]->setText("X");
            kov_jatekos=false;
            xvagyy="X";
        }
        else if(widgetsex[i]->is_checked() && kov_jatekos==false && widgetstx[i]->getText()==" ")
        {
            widgetstx[i]->setText("O");
            kov_jatekos=true;
            xvagyy="O";
        }
        if(widgetstx[i]->getText()==xvagyy && widgetstx[i+1]->getText()==xvagyy
                && widgetstx[i+2]->getText()==xvagyy && widgetstx[i+3]->getText()==xvagyy
                && widgetstx[i+4]->getText()==xvagyy)
        {
            endjatek();
        }
        else if(widgetstx[i]->getText()==xvagyy && widgetstx[i+_db]->getText()==xvagyy
                && widgetstx[i+2*_db]->getText()==xvagyy && widgetstx[i+3*_db]->getText()==xvagyy
                && widgetstx[i+4*_db]->getText()==xvagyy)
        {
            endjatek();
        }
        else if(widgetstx[i]->getText()==xvagyy && widgetstx[(i+_db)+1]->getText()==xvagyy
                && widgetstx[(i+2*_db)+2]->getText()==xvagyy && widgetstx[(i+3*_db)+3]->getText()==xvagyy
                && widgetstx[(i+4*_db)+4]->getText()==xvagyy)
        {
            endjatek();
        }
        else if(widgetstx[i]->getText()==xvagyy && widgetstx[(i+_db)-1]->getText()==xvagyy
                && widgetstx[(i+2*_db)-2]->getText()==xvagyy && widgetstx[(i+3*_db)-3]->getText()==xvagyy
                && widgetstx[(i+4*_db)-4]->getText()==xvagyy)
        {
            endjatek();
        }
    }
    for(int i=0; i<_db*_db; i++)
    {
        if(widgetstx[i]->getText()==" ")
        {
            sz++;
        }
    }
    if( sz==0 )
    {
        endjatek();
    }

}

void Window::event_loop()
{
    gout.open(_XX,_YY);
    gout.set_title(_neve);
    event ev;
    int focus = -1;
    PushButton *pb;
    PushButton *pb2;
    pb=new PushButton(650,50,80,30,"Játék",false);
    pb2=new PushButton(650,50,80,30,"Kilépés",false);
    while(gin>>ev && game)
    {
        if(kilep==false)
        {
            if(pb2->getJatek()==true)
            {
                pb2->handle(ev);
                pb2->draw();
            }
        }
        else
        {
            motor();
            if (ev.type==ev_mouse)
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
                pb->draw();
                pb->handle(ev);
                if(pb->getJatek()==true)
                {
                    widgetsex[i]->draw();
                    widgetstx[i]->draw();
                    pb2->setJatek(true);
                }
            }
            gout << refresh;
        }
    }
}
