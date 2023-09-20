#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../Core.hpp"
#include "../Error/MyError.hpp"
#include "./Components/Parallax.hpp"
#include "./Entity/Player.hpp"
#include "./Entity/Monster.hpp"
#include "./Loader/Loader.hpp"
#include "./Entity/Rocket.hpp"
#include "./Components/EventManager.hpp"

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

namespace game {
    class Game: public components::EventManager {
        public:
            Game();
            ~Game();
            int MainLoop();
            sf::Vector2u _screenSize;
        private:
            sf::RenderWindow _window;
            long _lastTime;

            components::Parallax _parallax1;
            components::Parallax _parallax2;
            entity::Player _player1;
            entity::Monster _monster1;
            std::vector<entity::Rocket> _rockets;
            loader::Loader _manager;
    };
}
