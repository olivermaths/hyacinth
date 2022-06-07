#include "headers/Window.hpp"
#include "headers/Application.hpp"
#include "headers/Core.hpp"
#include "headers/Events/Event.hpp"
#include <GLFW/glfw3.h>

namespace hct {
Window::Window(const char *title, int height, int width)
    : title(title), height(height), width(width), event(none) {
  glfwInit();
  p_window = glfwCreateWindow(this->width, this->height, this->title, 0, 0);
  glfwMakeContextCurrent(p_window);
  glfwSetWindowUserPointer(p_window, this);
  glfwSetWindowCloseCallback(this->p_window, [](GLFWwindow *window) {
    Window *hct_window = (Window *)glfwGetWindowUserPointer(window);
    hct_window->event.setEvent(WindowClose);
    hct_window->EventCallBackFn();
  });
  glfwSetKeyCallback(this->p_window, [](GLFWwindow *window, int key,
                                        int scancode, int action, int mods) {
    Window *hct_window = (Window *)glfwGetWindowUserPointer(window);
    std::cout << mods << std::endl;
    if(mods == 4){
        hct_window->event.setMod(HCT_ALT);
        HCT_INFO("pressing alt + q", 0);
    }


    if (action == 1) {
      switch (key) {
      case 65: {
        hct_window->event.setEvent(HCT_KEY_A);
        hct_window->EventCallBackFn();
      } break;
      case 66: {
        hct_window->event.setEvent(HCT_KEY_B);
        hct_window->EventCallBackFn();
      } break;
      case 67: {
        hct_window->event.setEvent(HCT_KEY_C);
        hct_window->EventCallBackFn();
      } break;
      case 68: {
        hct_window->event.setEvent(HCT_KEY_D);
        hct_window->EventCallBackFn();
      } break;
      case 69: {
        hct_window->event.setEvent(HCT_KEY_E);
        hct_window->EventCallBackFn();
      } break;
      case 70: {
        hct_window->event.setEvent(HCT_KEY_F);
        hct_window->EventCallBackFn();
      } break;
    case 81: {
        hct_window->event.setEvent(HCT_KEY_Q);
        hct_window->EventCallBackFn();
      } break;
      case 90: {
        hct_window->event.setEvent(HCT_KEY_Z);
        hct_window->EventCallBackFn();
      } break;
      default:;
      }
    }
  });
}
Window::~Window() { glfwDestroyWindow(p_window); }

// callbacks
void Window::SetEventCallBack(void *ptr) { this->caller = ptr; }
void Window::EventCallBackFn() {
  Application *app = (Application *)caller;
  app->onEvent(this->event);
};

void Window::OnUpdate() {
  glfwPollEvents();
  glfwSwapBuffers(p_window);
};
int Window::GetWidth() { return this->width; };
int Window::GetHeight() { return this->height; };
// proprieties
void Window::SetVSync(bool enabled) {
  if (enabled)
    glfwSwapInterval(1);
  else
    glfwSwapInterval(0);

  VSync = enabled;
};
bool Window::IsVSync() { return this->VSync; };

} // namespace hct