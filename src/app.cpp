#include "app.h"
#include <chrono>

void MainApplication::run(){
    sf::Clock timer;
    vertices.resize(2);
    vertices[0].position = sf::Vector2f(0,0);
    vertices[0].color = sf::Color(255,255,255);
    vertices[0].texCoords = {0,0};
    vertices[1].color = sf::Color(255,255,255);
    vertices[1].texCoords = {0,0};
    vertices[1].position = {100,100};

    while(window.isOpen()){
        while(!!(event = window.pollEvent())){
            if(event->is<sf::Event::Closed>()){
                window.close();
                winctl.close();
            }
        }

        window.setView(center);
        window.clear();

        vertices[1].position = resolver.generateNextPoint(std::chrono::milliseconds(timer.getElapsedTime().asMilliseconds()));
        window.draw(vertices);

        window.display();
    }
}