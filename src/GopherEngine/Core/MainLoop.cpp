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

        renderer_.initialize(window_);

        while(window_.is_open())
        {
            window_.handle_events();

            if(window_.get_dirty()) {
                renderer_.resize_viewport(window_.get_width(), window_.get_height());
                window_.set_dirty(false);
            }

            renderer_.draw();
            window_.display();
        }

        return EXIT_SUCCESS;
    }
}
