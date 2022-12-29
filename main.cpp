#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
#include "inc/Game.hpp"
#include "inc/Shapes.hpp"

int main()
{
   setlocale(LC_ALL, "ru");

   AN::Game Ok(800, 600, "YRA!!!");
   Ok.Setup("resources/key.png");
  
   AN::Sprites MC("resources/spritesheet.png");
   MC.Sprite(0, 146);


   const int count = 5;
   AN::CShapes Money[count];

   while (Ok.m_window->isOpen())
   {
       Ok.Event();
       Ok.MoveC(MC.m_sprite, Money);
       Ok.IsConflict(MC.m_sprite);
   }
    return 0;
}