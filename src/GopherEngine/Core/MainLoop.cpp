#include <GopherEngine/Core/MainLoop.hpp>

namespace GopherEngine {
    MainLoop::MainLoop()
    {
    }

    MainLoop::~MainLoop()
    {
    }

    int MainLoop::run()
    {
        initialize();

        window_.create_window();

        while(window_.is_open())
        {
            window_.handle_events();
        }

        return EXIT_SUCCESS;
    }
}
