#include "headers/Application.hpp"
#include "headers/Events/Event.hpp"
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

     void Application::onEvent(Event &event){
         EventType eventype = event.getEvent();
         ModType modType = event.getMod();
         if(eventype == HCT_KEY_Q && modType == HCT_ALT){
              HCT_INFO("Closing window event", NULL);
             this->hct_running = false;
         }
         if(eventype == WindowClose){
             HCT_INFO("Closing window event", NULL);
             this->hct_running = false;
         }
         else if(eventype >= HCT_KEY_A && eventype <= HCT_KEY_Z){
             HCT_INFO("key %i pressed ", eventype);
         }
     };
    Application::Application()
    {
        hct_running = true;
        hct_Window = new Window();
        hct_Window->SetEventCallBack(this);
    };
    Application::~Application()
    {
        delete this->hct_Window;
    };

}