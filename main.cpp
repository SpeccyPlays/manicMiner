#include <iostream>
#include <SFML/Graphics.hpp>
#include "player/player.h"

using namespace player;

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML stuff", sf::Style::Default);
player_1 willy;

void drawStuff();
void init();

int main(){
    init();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Keyboard keys;
        if (keys.isKeyPressed(keys.Left)){
            willy.updateLocation(-willy.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Right)){
            willy.updateLocation(willy.moveIncrement, 0);
        }
        if (keys.isKeyPressed(keys.Up)){
            willy.updateLocation(0, -willy.moveIncrement);
        }
        if (keys.isKeyPressed(keys.Down)){
            willy.updateLocation(0, willy.moveIncrement);
        }
        drawStuff();
    }

    return 0;
}
void init(){
    willy.initPlayer(100.f, 100.f, 1.f, "brickTexture.png");
    window.setFramerateLimit(60);
}
void drawStuff(){
    window.clear();
    window.draw(willy.playerSprite);
    window.display();
}
