#include "scene.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include "entity.h"
Scene::Scene()
{
    
}
introScene::introScene()
{

}
scene_1::scene_1()
{

}
Player player_Init()
{
    sf::Vector2i p(100,100), v(20,10);
    Player p1;
    sf::RectangleShape playerRect(sf::Vector2f(5,5));
    playerRect.setPosition(sf::Vector2f(p));
    p1.cName = std::make_shared<CName>("Player");
    p1.cShape = std::make_shared<CShape>(playerRect);
    p1.cTransform = std::make_shared<CTransform>(p,v);
    p1.cPhysics = std::make_shared<CPhysics>();
    return p1;
}
bool introScene::renderScene(sf::RenderWindow &w)
{
     sf::Font font;
    if(!font.loadFromFile("Perfect DOS VGA 437.ttf"))
    {
        std::cout << "Font not found!";
    }
    sf::Text introText; 
    introText.setFont(font);
    introText.setString("Click the mouse to start");
    introText.setCharacterSize(24);
    introText.setFillColor(sf::Color::White);
    introText.setPosition(150,250);
    w.draw(introText);

    bool playerInputStart = true;
    return playerInputStart;
}

bool scene_1::renderScene(sf::RenderWindow &w)
{
  
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
            //p1.cPhysics->move_right(playerRect);
            //std::cout << "right";
            
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
           // p1.cPhysics->move_left(playerRect);
            
            
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player_Init().cPhysics->jump(player_Init().cTransform->pos);
    }
    w.draw(player_Init().cShape->shape);
    bool renderSceneStart = true;
    return renderSceneStart;
}
