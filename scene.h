#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<iostream>
class Scene {
    public:
    Scene();
    virtual bool renderScene(sf::RenderWindow &w) = 0;
};

class introScene : public Scene{
    public:
    introScene();
    bool renderScene(sf::RenderWindow &w);
};

class scene_1 : public Scene{
    public:
    scene_1();
    bool renderScene(sf::RenderWindow &w);

};
