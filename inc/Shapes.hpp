#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace AN
{
	class CShapes
	{
	private:
		float m_radius;
		int m_R, m_G, m_B;
	public: 
		sf::CircleShape* m_shape = nullptr;
		CShapes()
		{
			m_radius = 15;
			m_R = 228;
			m_G = 160;
			m_B = 16;
			m_shape = new sf::CircleShape(m_radius);
			m_shape->setFillColor(sf::Color(m_R, m_G, m_B));
		}
		CShapes(float radius, int R, int G, int B)
		{
			m_radius = radius;
			m_R = R;
			m_G = G;
			m_B = B;
			m_shape = new sf::CircleShape(m_radius);
			m_shape->setFillColor(sf::Color(m_R, m_G, m_B));
		}
		~CShapes()
		{
			if (m_shape != nullptr)
			{
				delete m_shape;
			}
		}
	};

	class Sprites
	{
	public:
		sf::Sprite m_sprite;
		Sprites(std::string Location)
		{
			sf::Image Image;
			Image.loadFromFile(Location);
			sf::Texture ShapeTexture;
			ShapeTexture.loadFromImage(Image);
			m_sprite.setTexture(ShapeTexture);
			m_sprite.setPosition(50, 50);
		}
		~Sprites(){}

		void Sprites::Sprite(int x, int y);
	};
}