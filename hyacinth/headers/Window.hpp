#ifndef _HYACINTH_WINDOW
#define _HYACINTH_WINDOW
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

    public:
        ~Window();
        Window(const char *title = "hyacinth", int height=600, int width=800);
        void EventCallBackFn(Event&);
        void OnUpdate();
        int GetWidth();
        int GetHeight();


        //Window attributes
        void SetEventCallBack();
        void SetVSync(bool enabled);
        bool IsVSync();

    
    };

}

#endif //
