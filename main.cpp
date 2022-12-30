#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "inc/Game.hpp"
#include "inc/Shapes.hpp"

int main()
{
   setlocale(LC_ALL, "ru");
   AN::Game Game(800,600,"Project");
   Game.Setup("image/candy.png");

   const float Radius1 = 100, Radius2 = 50;
   sf::CircleShape shape1(Radius1);
   shape1.setFillColor(sf::Color(186, 85, 211));
   sf::CircleShape shape2(Radius2);
   shape2.setFillColor(sf::Color(2, 171, 157));

 
   Game.Move(shape1, shape2, Radius1, Radius2);
   
   return 0;
}