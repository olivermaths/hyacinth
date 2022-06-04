#ifndef _HYACINTH_EVENT
#define _HYACINTH_EVENT

namespace hct
{

    enum EventType
    {
        none = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = 0x100,
        EventCategoryInput = 0x200,
        EventCategoryKeyboard = 0x300,
        EventCategoryMouse = 0x400,
        EventCategoryMouseButton = 0x450,
    };

    class Event
    {

    private:
        void ApplicationEvent();
        void MouseEvent();
        void KeyboardEvent();
        Event();
        ~Event();
    };

}

#endif //
