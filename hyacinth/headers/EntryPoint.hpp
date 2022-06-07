#ifndef _HYACINTH_ENTRYPOINT
#define _HYACINTH_ENTRYPOINT

extern hct::Application *hct::CreateApplication();

int main(int argc, char **arv)
{

    auto *app = hct::CreateApplication();
    app->run();
    delete app;
}

#endif //
