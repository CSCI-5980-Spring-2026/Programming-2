#include <SFML/Window.hpp>
#include <string>

namespace GopherEngine {
    class Window {
        public:
            Window(std::string title = "GopherEngine", unsigned int width = 800, unsigned int height = 600);
            ~Window();
            
            void create_window();
            void handle_events();

            void set_title(std::string title);
            void set_size(unsigned int width, unsigned int height);
            void set_style(int style);
            void set_state(sf::State state);
            void set_vertical_sync(bool vertical_sync);

            int get_width();
            int get_height();
            bool is_open();

        private: 
            sf::Window* window_;
            std::string title_;
            unsigned int width_;
            unsigned int height_;
            int style_;
            sf::State state_;  
            bool vertical_sync_;
    };
} 