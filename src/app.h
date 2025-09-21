#ifndef FT_APP_H
#define FT_APP_H
#include <SFML/Graphics.hpp>
#include <optional>
#include <GL/glew.h>
#include <iostream>
#include "vector_resolver.h"

struct MainApplication{
    sf::RenderWindow window;
    sf::RenderWindow winctl;
    std::optional<sf::Event> event {std::nullopt};
    int return_val {0};
    sf::VertexArray vertices {sf::PrimitiveType::LineStrip,0};
    sf::VertexArray coord {sf::PrimitiveType::Lines,4};
    sf::VertexArray vectors { sf::PrimitiveType::LineStrip,0};
    VResolver resolver;
    sf::View center;
    sf::View ui;
    sf::Font defFont;

    float half_w,half_h;

    inline void setup(){
        window.create(
            sf::VideoMode(sf::Vector2u(800,800)),
            "Fourier Transform",
            sf::State::Windowed
        );
        center = ui = window.getDefaultView();
        half_w = window.getSize().x / 2.f;
        half_h = window.getSize().y / 2.f;
        
        // 有些特殊配置需要从default view中继承才能正确显示
        center.move({-400,-400});

        winctl.create(
            sf::VideoMode(sf::Vector2u(400,800)),
            "Console - Fourier Transform",
            sf::Style::Default & ~sf::Style::Close,
            sf::State::Windowed
        );

        winctl.setPosition(window.getPosition() + sf::Vector2i(800,0));

        resolver.vectors.push_back(Vector({100,0},std::chrono::milliseconds(5000)));
        resolver.vectors.push_back(Vector({40,0},std::chrono::milliseconds(2000)));
        resolver.vectors.push_back(Vector({20,0},std::chrono::milliseconds(1500)));
        resolver.vectors.push_back(Vector({40,0},std::chrono::milliseconds(-1200)));
        resolver.vectors.push_back(Vector({32,15},std::chrono::milliseconds(3000)));

        coord[0].color = sf::Color(255,255,255);
        coord[1].color = sf::Color(255,255,255);
        coord[2].color = sf::Color(255,255,255);
        coord[3].color = sf::Color(255,255,255);
        
        coord[0].position = sf::Vector2f(0,half_h);
        coord[1].position = sf::Vector2f(half_w * 2,half_h);
        coord[2].position = sf::Vector2f(half_w,0);
        coord[3].position = sf::Vector2f(half_w,half_h * 2);

        defFont.openFromFile("./res/nerd_font.ttf"); 
    }

    void run();
};

#endif