#include "window.hpp"

int main()
{
    Window mywindow(800,800,20,"Amoba");
    mywindow.feltolt();
    mywindow.motor();
    mywindow.event_loop();
    return 0;
}
