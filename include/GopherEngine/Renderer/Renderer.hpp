#pragma once

namespace GopherEngine
{
    class Renderer
    {
        public:
            Renderer();
            ~Renderer();
            void initialize(unsigned int width, unsigned int height);
            void resize_viewport(unsigned int width, unsigned int height);
            void draw();
    };
}