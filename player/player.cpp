//player
#include "player.h"

using namespace player;

void player_1::initPlayer(float xStart, float yStart, float moveAmount, std::string textureFileName){
    xPosition = xStart;
    yPosition = yStart;
    moveIncrement = moveAmount;
    if (!player_1::playerTexture.loadFromFile(textureFileName)){
        std::cout << "Texture not loaded";
    }
    else {
        std::cout << "Brick Texture loaded";
    }
    player_1::playerTexture.setSmooth(true);
    player_1::playerSprite.setTexture(playerTexture);
    player_1::playerSprite.setScale(2.f, 2.f);
    player_1::playerSprite.setOrigin(4.f, 4.f);
    player_1::playerSprite.setPosition(xPosition, yPosition);
};
void player_1::updateLocation(float xUpdateValue, float yUpdateValue){
    xPosition += xUpdateValue;
    yPosition += yUpdateValue;
    player_1::playerSprite.setPosition(xPosition, yPosition);
};
