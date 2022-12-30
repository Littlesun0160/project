#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace AN
{
	class Balls
	{
	private:
		
	public:
		int m_x0, m_y0, m_radius;
		Balls(int x0, int y0, int radius)
		{
			m_x0 = x0;
			m_y0 = y0;
			m_radius = radius;
		}
		~Balls() {}

	};
}
