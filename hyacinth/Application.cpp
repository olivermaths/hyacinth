#include "headers/Application.hpp"
#include "headers/Window.hpp"
#include <GL/gl.h>
namespace hct
{
    void Application::run()
    {
        while (hct_running)
        {
            glClearColor(0.2,0.02, 0.84, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            hct_Window->OnUpdate();
        
        }
    }
    Application::Application()
    {
        hct_running = true;
        hct_Window = new Window();
    };
    Application::~Application()
    {
        delete this->hct_Window;
    };

}