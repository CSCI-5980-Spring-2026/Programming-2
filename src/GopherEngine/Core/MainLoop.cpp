#include <GopherEngine/Core/MainLoop.hpp>
#include <GopherEngine/Renderer/Renderer.hpp>

#include <iostream>

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

        if(!window_.set_active(true)) {
            std::cerr << "Failed to set window to active" << std::endl;
            return EXIT_FAILURE;
        }

        renderer_.initialize(window_.get_width(), window_.get_height());

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

