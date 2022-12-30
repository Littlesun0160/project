#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace AN
{
	class Game
	{
	private:
		
		std::string m_head;
	public:
		int m_width, m_length;
		sf::RenderWindow* m_window = nullptr;
		Game(int width, int length, std::string head)
		{
			m_width = width;
			m_length = length;
			m_head = head;
		}
		~Game()
		{
			if (m_window != nullptr)
			{
				delete m_window;
			}
		}
		bool Game::Setup(std::string FileLocation1);
		void Game::Move(sf::CircleShape shape1,sf::CircleShape shape2, float Radius1, float Radius2);
	};
}
