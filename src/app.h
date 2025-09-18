#ifndef FT_APP_H
#define FT_APP_H
#include <SFML/Graphics.hpp>
#include <optional>
#include "vector_resolver.h"

struct MainApplication{
    sf::RenderWindow window;
    sf::RenderWindow winctl;
    std::optional<sf::Event> event {std::nullopt};
    int return_val {0};
    sf::VertexArray vertices;
    VResolver resolver;
    sf::View center;

    inline void setup(){
        window.create(
            sf::VideoMode(sf::Vector2u(800,600)),
            "Fourier Transform",
            sf::State::Windowed
        );
        //在带缩放的系统下面优点小问题
        center.move({- int(window.getSize().x) / 2.0f,- int(window.getSize().y) / 2.0f});

        winctl.create(
            sf::VideoMode(sf::Vector2u(400,300)),
            "Console - Fourier Transform",
            sf::Style::Default & ~sf::Style::Close,
            sf::State::Windowed
        );

        resolver.vectors.push_back(Vector({100,0},std::chrono::milliseconds(300)));
        vertices.setPrimitiveType(sf::PrimitiveType::LineStrip);
    }

    void run();
};

#endif