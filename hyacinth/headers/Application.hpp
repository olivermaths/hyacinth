#ifndef _HYACINTH_APPLICATION
#define _HYACINTH_APPLICATION
#include "Window.hpp"
#include <iostream>
namespace hct
{
    class Application
    {
    private:
        Window *hct_Window;
        bool hct_running;

    public:
        Application();
        ~Application();
        void run();
         void onEvent(Event &event);
    };

    // to be defined in client
    Application *CreateApplication();
}

#endif //
