#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
//Manipolazione dei caratteri- stringhe vettori di caratteri 
enum button_states{BTN_IDLE = 0,BTN_HOVER, BTN_ACTIVE};// sono gli umori del bottone; c'é una mappa implicita tra i numeri interi e le cariabile dell'enumerazione

class Button {
    private:
    //sono gli sbirri del traffico
    short unsigned buttonState_;

    //Maschera dell'oggetto 
    sf::RectangleShape shape_; // la figura rettangolare;float x, float y, float width, float height 
    sf::Font* font_;// puntatore ad un carattere 
    sf::Text text_;
    
    sf::Color idleColor_;//Colore inattivo
    sf::Color hoverColor_;//quando la freccia è sopra al mouse
    sf::Color activeColor_;//Colore attivo   

    public:
     Button(float x, float y, float width, float height,std::string text, sf::Font* font, sf::Color idleColor ,sf::Color hoverColor,sf::Color active Color ); 
     ~Button();
     //Functions
     void update(sf::Vector2f mousePos);
     void render (sf::RenderTarget * target);


}
#endif 