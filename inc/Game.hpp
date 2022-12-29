#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <Shapes.hpp>

namespace AN
{
	class Game
	{
	private:
		int m_width, m_length;
		std::string m_head;
		
		float m_PosX, m_PosY;
	public:
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

		bool Game::Setup(std::string FileLocation);
		void Game::Event();
		void Game::MoveC(sf::Sprite SpriteMC, AN::CShapes Money[5]);
		void Game::IsConflict(sf::Sprite SpriteMC);
	};

	
}