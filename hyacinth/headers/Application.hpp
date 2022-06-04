#ifndef _HYACINTH_APPLICATION
#define _HYACINTH_APPLICATION
#include "Core.hpp"
#include "Window.hpp"
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
    };

    // to be defined in client
    Application *CreateApplication();
}

#endif //
