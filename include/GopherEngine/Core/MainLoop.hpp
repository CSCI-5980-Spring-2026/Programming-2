#pragma once

#include <GopherEngine/Platform/Window.hpp>
#include <GopherEngine/Renderer/Renderer.hpp>

namespace GopherEngine {
    class MainLoop {
        public:
            MainLoop();
            ~MainLoop();
            int run();

        protected:
            virtual void initialize() = 0;
            Window window_;
            Renderer renderer_;
    };
} 