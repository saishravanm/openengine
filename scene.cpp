#include "scene.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include "entity.h"
Scene::Scene()
{
    
}
introScene::introScene()
{

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
    introText.setString("Press enter to start");
    introText.setCharacterSize(24);
    introText.setFillColor(sf::Color::White);
    introText.setPosition(150,250);
    w.draw(introText);

    bool playerInputStart = true;
    return playerInputStart;
}

bool scene_1::renderScene(sf::RenderWindow &w)
{
    sf::Vector2i p(100,200), v(20,10);
    Player p1;
    p1.cName = std::make_shared<CName>("Player");
    p1.cShape = std::make_shared<CShape>(sf::RectangleShape rect(sf::Vector2f(100,100));
    p1.cTransform = std::make_shared<CTransform>(p,v);
}
