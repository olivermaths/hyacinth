#ifndef _HYACINTH_EVENT
#define _HYACINTH_EVENT

namespace hct {

enum EventType {
  none = 0,
  // Window Events
  WindowClose = 0x100,
  WindowResize,
  WindowFocus,
  WindowLostFocus,
  WindowMoved,
  // App Events
  AppTick = 0x150,
  AppUpdate,
  AppRender,
  // Mouse events
  MouseButtonPressed = 0x200,
  MouseButtonReleased,
  MouseMoved,
  MouseScrolled,
  // Key events
  HCT_KEY_A = 0x300,
  HCT_KEY_B,
  HCT_KEY_C,
  HCT_KEY_D,
  HCT_KEY_E,
  HCT_KEY_F,
  HCT_KEY_Q,
  HCT_KEY_Z,
};
enum ModType {
  HCT_ALT = 0x00,
  HCT_CTRL,
};

class Event {
public:
  Event(EventType eventType) : eventType(eventType){};
  ~Event(){

  };
  EventType getEvent() { return this->eventType; }
  ModType getMod() { return this->modType; }
  void setEvent(EventType eventType) { this->eventType = eventType; }
  void setMod(ModType modType) { this->modType = modType; }

private:
  EventType eventType;
  ModType modType;
  void ApplicationEvent();
  void MouseEvent();
  void KeyboardEvent();
};

} // namespace hct

#endif //
