#include "headers/Window.hpp"
#include <GLFW/glfw3.h>
#include <SDL2/SDL_video.h>

namespace hct
{
  Window::Window(const char *title, int height, int width):title(title), height(height), width(width){
      glfwInit();     
      p_window = glfwCreateWindow(this->width, this->height, this->title,0, 0);
      glfwMakeContextCurrent(p_window);

  }
  Window::~Window(){
      glfwDestroyWindow(p_window);
  }

    //callbacks
    void Window::SetEventCallBack(){};
    void Window::EventCallBackFn(Event&){};
    void Window::OnUpdate(){
        glfwPollEvents();
        glfwSwapBuffers(p_window);        
    };
    int Window::GetWidth(){
        return this->width;
    };
    int Window::GetHeight(){
        return this->height;
    };
    //proprieties
    void Window::SetVSync(bool enabled){
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        
        VSync = enabled;
    };
    bool Window::IsVSync(){
        return this->VSync;
    };

}