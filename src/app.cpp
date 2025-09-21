#include "app.h"
#include <chrono>

void MainApplication::run(){
    sf::Clock timer;
    sf::Vertex point;
    point.color = sf::Color(255,255,255);
    point.texCoords = {0,0};
    sf::Cursor cur_hand(sf::Cursor::Type::Hand),cur_arrow(sf::Cursor::Type::Arrow);

    sf::Vector2f mouse_pos;
    while(window.isOpen()){
        while(!!(event = window.pollEvent())){
            if(event->is<sf::Event::Closed>()){
                window.close();
                winctl.close();
            }
        }
        window.clear();
        window.setView(ui);
        window.draw(coord);
        
        window.setView(center);

        //vectors and circles
        {
            sf::CircleShape c;
            c.setFillColor(sf::Color(0,0,0,0));
            c.setOutlineColor(sf::Color(128,128,128));
            c.setOutlineThickness(1);

            vectors.resize(resolver.vectors.size() + 1);
            vectors[0].position = sf::Vector2f(0,0);
            vectors[0].color = sf::Color(255,255,255);
            int i = 0;
            for(auto & t : resolver.vectors){
                ++i;
                float len = t.direction.length();
                vectors[i].color = sf::Color(255,255,255);
                c.setRadius(len);
                c.setPosition(vectors[i-1].position - sf::Vector2f(len,len));
                window.draw(c);
                vectors[i].position = vectors[i-1].position + t.generate(std::chrono::milliseconds(timer.getElapsedTime().asMilliseconds()));
            }
            window.draw(vectors);
        }

        // trail
        point.position = resolver.generateNextPoint(std::chrono::milliseconds(timer.getElapsedTime().asMilliseconds()));
        vertices.append(point);
        window.draw(vertices);
        
        window.display();

        winctl.clear();
        {
            auto tv = sf::Mouse::getPosition(winctl);
            mouse_pos = sf::Vector2f(tv.x,tv.y);
        }
        {
            sf::Text a(defFont,"HelloWorld");
            if(a.getGlobalBounds().contains(mouse_pos)){
                winctl.setMouseCursor(cur_hand);
            }else winctl.setMouseCursor(cur_arrow);
            winctl.draw(a);
        }

        winctl.display();
    }
}