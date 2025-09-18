#ifndef FT_VR_H
#define FT_VR_H
#include <SFML/Graphics.hpp>
#include <chrono>
#include <numbers>
#include <cmath>

struct Vector{
    sf::Vector2f direction;
    std::chrono::milliseconds T;

    inline sf::Vector2f generate(std::chrono::milliseconds time){
        double angle = time.count() % T.count() / (float)T.count() * std::numbers::pi * 2;
        double cosv = std::cos(angle);
        double sinv = std::sin(angle);
        return {
            float(direction.x * cosv - direction.y * sinv),
            float(direction.x * sinv + direction.y * cosv) 
        };
    }
};

struct VResolver{
    std::vector<Vector> vectors;

    inline sf::Vector2f generateNextPoint(std::chrono::milliseconds time){
        sf::Vector2f v = {0,0};

        for(auto & i : vectors){
            v += i.generate(time);
        }

        return v;
    }
};

#endif