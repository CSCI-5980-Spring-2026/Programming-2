#include <GopherEngine/Platform/Window.hpp>

namespace GopherEngine {
    class MainLoop {
        public:
            MainLoop();
            ~MainLoop();
            int run();

        protected:
            virtual void initialize() = 0;
            Window window_;
    };
} 