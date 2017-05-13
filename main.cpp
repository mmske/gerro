#include "window.hpp"

int main()
{
    Window mywindow(800,800,20,"Amoba");
    mywindow.feltolt();
    mywindow.event_loop();
    return 0;
}
