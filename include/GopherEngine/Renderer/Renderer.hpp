#pragma once

#include <GopherEngine/Platform/Window.hpp>

namespace GopherEngine {
    class Renderer {
        public:
            Renderer();
            ~Renderer();
            void initialize(Window& window);
            void resize_viewport(int width, int height);
            void draw();
    };
} 