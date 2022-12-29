#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "../inc/Shapes.hpp"
#include "../inc/Game.hpp"
#include <iostream>

namespace AN
{
	void Sprites::Sprite(int x, int y)
	{
		m_sprite.setTextureRect(sf::IntRect(x,y,15,13));
	}

	
}