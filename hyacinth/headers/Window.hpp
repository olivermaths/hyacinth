#ifndef _HYACINTH_WINDOW
#define _HYACINTH_WINDOW
#include "Core.hpp"
#include "Events/Event.hpp"
#include <GLFW/glfw3.h>
#include <GL/gl.h>

namespace hct
{

    class Window
    {
    private:
        const char* title;
        GLFWwindow *p_window;
        int height;
        int width;
        bool VSync;
        void *caller;
        Event event;

    public:
        ~Window();
        Window(const char *title = "hyacinth", int height=600, int width=800);
        void OnUpdate();
        int GetWidth();
        int GetHeight();
    

        //Window attributes
        void EventCallBackFn();

        Event *getEvent(){
            return &this->event;
        }

        void SetEventCallBack(void *ptr);
        void SetVSync(bool enabled);
        bool IsVSync();

    
    };

}

#endif //
