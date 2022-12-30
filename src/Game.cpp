#include "../inc/Game.hpp"
#include "../inc/Shapes.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace AN
{
	bool Game::Setup(std::string FileLocation1)
	{
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_length), m_head);
		sf::Image icon;
		if (!icon.loadFromFile(FileLocation1))
		{
			return 1;
		}
		m_window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

	void Game::Move(sf::CircleShape shape1,sf::CircleShape shape2, float Radius1, float Radius2)
	{
		float deltax1 = 0.05; float deltay1 = 0.05;
		float deltax2 = 0.07; float deltay2 = 0.07;
		AN::Balls Ball1(Radius1, Radius1, Radius1);
		AN::Balls Ball2(m_length-Radius2-1, m_length-Radius2-1, Radius2);

		float x1 = Ball1.m_x0; float y1 = Ball1.m_y0;
		float x2 = Ball2.m_x0; float y2 = Ball2.m_y0;

		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window->close();
			}

			x1 += deltax1; y1 += deltay1;
			x2 += deltax2; y2 += deltay2;

			//Столкновение шаров с границами
			if (((x1 + Ball1.m_radius) > (m_width)) || ((x1 - Ball1.m_radius) < 0))
			{
				deltax1 = -deltax1;
			}
			if (((y1 + Ball1.m_radius) > (m_length)) || ((y1 - Ball1.m_radius) < 0))
			{
				deltay1 = -deltay1;
			}

			if (((x2 + Ball2.m_radius) > (m_width)) || ((x2 - Ball2.m_radius) < 0))
			{
				deltax2 = -deltax2;
			}
			if (((y2 + Ball2.m_radius) > (m_length)) || ((y2 - Ball2.m_radius) < 0))
			{
				deltay2 = -deltay2;
			}

			//Столкновение шаров между собой
			//Находим гипотенузу треугольника(расстояние между центрами шариков)
			float hypotenuse = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			if (hypotenuse == 0) //Гипотенуза не может быть равна 0
			{
				hypotenuse = 0.01;
			}
			float sin = (x1 - x2) / hypotenuse;
			float cos = (y1 - y2) / hypotenuse;
			if (hypotenuse < (Ball1.m_radius + Ball2.m_radius))
			{
				//Производим поворот системы координат
				float newx1= deltax1 * sin + deltay1 * cos;
				float newy1 = -deltax1 * cos + deltay1 * sin;
				float newx2 = deltax2 * sin + deltay2 * cos;
				float newy2 = -deltax2 * cos + deltay2 * sin;
				
				std::swap(newx1, newx2); 

				deltax1 = newx1 * sin - newy1 * cos;
				deltay1 = newx1 * cos + newy1 * sin;
				deltax2 = newx2 * sin - newy2 * cos;
				deltay2 = newx2 * cos + newy2 * sin;
			}


			m_window->clear();
			shape1.setOrigin(Ball1.m_radius, Ball1.m_radius);
			shape2.setOrigin(Ball2.m_radius, Ball2.m_radius);
			shape1.setPosition(x1, y1);
			shape2.setPosition(x2, y2);
			m_window->draw(shape1);
			m_window->draw(shape2);
			m_window->display();
		}
		
	}
}