#include <GopherEngine/Renderer/Renderer.hpp>

#include <SFML/OpenGL.hpp>
#include <array>

namespace GopherEngine {
    Renderer::Renderer()
    {}

    Renderer::~Renderer()
    {}

    void Renderer::initialize(unsigned int width, unsigned int height)
    {
        // Graphics initialization
        glEnable(GL_DEPTH_TEST);
        glDepthMask(GL_TRUE);
        glClearDepth(1.f);
        glDisable(GL_LIGHTING);

        resize_viewport(width, height);
    }

    void Renderer::resize_viewport(unsigned int width, unsigned int height) {
        glViewport(0, 0, static_cast<GLsizei>(width), static_cast<GLsizei>(height));
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        const GLfloat new_ratio =  static_cast<float>(width) / static_cast<float>(height);
        glFrustum(-new_ratio, new_ratio, -1.f, 1.f, 1.f, 500.f);
    }

    void Renderer::draw() {

        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Define a 3D cube (6 faces made of 2 triangles)
        constexpr std::array<GLfloat, 180> cube =
        {
            -.5f, -.5f, -.5f,
            -.5f,  .5f, -.5f,
            -.5f, -.5f,  .5f,
            -.5f, -.5f,  .5f, 
            -.5f,  .5f, -.5f, 
            -.5f,  .5f,  .5f,

            .5f, -.5f, -.5f,
            .5f,  .5f, -.5f,
            .5f, -.5f,  .5f,
            .5f, -.5f,  .5f,
            .5f,  .5f, -.5f,
            .5f,  .5f,  .5f,

            -.5f, -.5f, -.5f,
            .5f, -.5f, -.5f,
            -.5f, -.5f,  .5f,
            -.5f, -.5f,  .5f, 
            .5f, -.5f, -.5f,
            .5f, -.5f,  .5f,

            -.5f,  .5f, -.5f,
            .5f,  .5f, -.5f,
            -.5f,  .5f,  .5f,
            -.5f,  .5f,  .5f,
            .5f,  .5f, -.5f,
            .5f,  .5f,  .5f,

            -.5f, -.5f, -.5f, 
            .5f, -.5f, -.5f,
            -.5f,  .5f, -.5f,
            -.5f,  .5f, -.5f, 
            .5f, -.5f, -.5f,
            .5f,  .5f, -.5f,

            -.5f, -.5f,  .5f, 
            .5f, -.5f,  .5f,
            -.5f,  .5f,  .5f,
            -.5f,  .5f,  .5f,
            .5f, -.5f,  .5f, 
            .5f,  .5f,  .5f
        };

        // Enable position and texture coordinates vertex components
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), cube.data());

        // Disable normal and color vertex components
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        // Apply some transformations
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -2.f);

        // Draw the cube
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}