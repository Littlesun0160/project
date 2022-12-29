#include "../inc/Game.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <Shapes.hpp>

namespace AN
{
	bool Game::Setup(std::string FileLocation)
	{
		m_window = new sf::RenderWindow (sf::VideoMode(m_width, m_length), m_head);
		sf::Image icon;
		if (!icon.loadFromFile(FileLocation))
		{
			return 1;
		}
		m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

    void Game::Event()
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }
    }

    void Game::MoveC(sf::Sprite SpriteMC, AN::CShapes Money[5])
    {
        m_window->clear();
        for (int i = 0; i < 5; i++)
        {
            Money[i].m_shape->setPosition(100 + 100 * i, 100 + 100 * i);
            m_window->draw(*Money[i].m_shape);
        }
        m_window->draw(SpriteMC);
        m_window->display();
        
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
           SpriteMC.move(0.15f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            SpriteMC.move(0.f, 0.15f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            SpriteMC.move(-0.15f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            SpriteMC.move(0.f, -0.15f);
        }
    }
    void Game::IsConflict(sf::Sprite SpriteMC)
    {
        if (SpriteMC.getPosition().x < (-20))
            SpriteMC.setPosition(-20, (SpriteMC).getPosition().y);
        else if (SpriteMC.getPosition().x > 600)
            SpriteMC.setPosition(600, SpriteMC.getPosition().y);
        if (SpriteMC.getPosition().y < (-20))
            SpriteMC.setPosition(SpriteMC.getPosition().x, -20);
        else if (SpriteMC.getPosition().y > 400)
            SpriteMC.setPosition(SpriteMC.getPosition().x, 400);
    }
}