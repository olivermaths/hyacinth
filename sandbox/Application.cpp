#include "../hyacinth/hyacinth.hpp"

class Sandbox : public hct::Application
{
public:
    Sandbox(){};
    ~Sandbox(){};
};
hct::Application *hct::CreateApplication()
{
    return new Sandbox();
};