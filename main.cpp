#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <cstddef>
#include <cstdlib>
#include <new>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iterator>
#include "scene.h"

int wHeight = 600;
int wWidth = 800;
sf::RenderWindow window(sf::VideoMode(wWidth,wHeight),"Window");


int main()
{
    Scene* intro = new introScene();
    Scene* scenes[] = {intro};
    int sceneIndex = 0;

    while(window.isOpen())
    {
        sf::Event event; 
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && intro->renderScene(window) == true)
            {
                
            }

        }

        window.clear(sf::Color::Black);
        //scenes[sceneIndex]->scene(window);
        //intro_Scene->scene(window);
        scenes[sceneIndex]->renderScene(window);
        window.display();
    }
}