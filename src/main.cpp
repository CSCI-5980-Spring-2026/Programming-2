/* Programming 2: Runtime Engine Architecture
 * CSCI 5980, Spring 2026, University of Minnesota
 * Instructor: Evan Suma Rosenberg <suma@umn.edu>
 * License: Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International
 */ 

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

int main()
{
	// Request a 24-bit depth buffer when creating the window
	sf::ContextSettings contextSettings;
	contextSettings.depthBits   = 24;
	contextSettings.sRgbCapable = false;

    // Create the window
    sf::Window window(sf::VideoMode({800, 600}), 
					  "SFML graphics with OpenGL",
					  sf::Style::Default,
					  sf::State::Windowed,
					  contextSettings);
					  
    window.setVerticalSyncEnabled(true);

    // Make the window the active window for OpenGL calls
	if (!window.setActive(true))
	{
		std::cerr << "Failed to set window to active" << std::endl;
		return EXIT_FAILURE;
	}

	// Graphics initialization
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
	glClearDepth(1.f);
	glDisable(GL_LIGHTING);

	// Configure the viewport (the same size as the window)
    glViewport(0, 0, static_cast<GLsizei>(window.getSize().x), static_cast<GLsizei>(window.getSize().y));

	// Setup a perspective projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	const GLfloat ratio = static_cast<float>(window.getSize().x) / static_cast<float>(window.getSize().y);
	glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

	// Define a 3D cube (6 faces made of 2 triangles)
	constexpr std::array<GLfloat, 180> cube =
	{
		-20, -20, -20,
		-20,  20, -20,
		-20, -20,  20,
		-20, -20,  20, 
		-20,  20, -20, 
		-20,  20,  20,

		20, -20, -20,
		20,  20, -20,
		20, -20,  20,
		20, -20,  20,
		20,  20, -20,
		20,  20,  20,

		-20, -20, -20,
		20, -20, -20,
		-20, -20,  20,
		-20, -20,  20, 
		20, -20, -20,
		20, -20,  20,

		-20,  20, -20,
		20,  20, -20,
		-20,  20,  20,
		-20,  20,  20,
		20,  20, -20,
		20,  20,  20,

		-20, -20, -20, 
		20, -20, -20,
		-20,  20, -20,
		-20,  20, -20, 
		20, -20, -20,
		20,  20, -20,

		-20, -20,  20, 
		20, -20,  20,
		-20,  20,  20,
		-20,  20,  20,
		20, -20,  20, 
		20,  20,  20
	};

	// Enable position and texture coordinates vertex components
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), cube.data());

	// Disable normal and color vertex components
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    while (window.isOpen())
    {
        // Handle events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
				window.close();
            }
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
				glViewport(0, 0, static_cast<GLsizei>(window.getSize().x), static_cast<GLsizei>(window.getSize().y));
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				const GLfloat newRatio =  static_cast<float>(resized->size.x) / static_cast<float>(resized->size.y);
				glFrustum(-newRatio, newRatio, -1.f, 1.f, 1.f, 500.f);
            }
        }

        // Clear the buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Get the position of the mouse cursor so that we can move the box accordingly
		sf::Vector2i pos;

		pos = sf::Mouse::getPosition(window);
		const float x = pos.x * 200.f / window.getSize().x - 100.f;
		const float y = -pos.y * 200.f / window.getSize().y + 100.f;

		// Apply some transformations
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(x, y, -100.f);

        // Draw the cube
    	glDrawArrays(GL_TRIANGLES, 0, 36);

        // End the current frame (internally swaps the front and back buffers)
        window.display();
    }

	return EXIT_SUCCESS;
}