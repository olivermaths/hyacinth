#ifndef _HYACINTH_RENDERER_CONTEXT
#define _HYACINTH_RENDERER_CONTEXT

namespace hct
{
    namespace renderer
    {
        class Context
        {
        public:
            virtual void init() = 0;
            virtual void SwapBuffers() = 0;
            Context();
            ~Context();
        };
    }

}

#endif //
