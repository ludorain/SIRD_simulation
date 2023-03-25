#include "button.hpp"




Button::Button(float x, float y, float width, float height,std::string text, sf::Font* font, sf::Color idleColor ,sf::Color hoverColor,sf::Color active Color ){
    //umore
    this-> buttonState_ = BTN_IDLE;
    //shape
    this->shape_.setSize(sf::Vector2f(width.height))
    this->shape_.setPosistion(sf::Vector2f(x,y));
    this->shape_.setFillColor(this->idleColor)
   
    //Font
    this->font_ = font;
    //testo
    this->text_.setFont(*this->font_);
    this->text_.setString(text);
    this->text_.setFillColor(sf::Color::White);//stomettendo kla scritta bianca  
    this->text_.setCharacterSize(12);//dimesione del carattere 
    //textposition
    this->text_.setPosition(0,0);//posizione della scritta nel bottone 
    /*this->text_.setPosition((this->shape_.getPosition().x/2.f )-(this->text.getGlobalBounds().width),
    (this->shape_.getPosition().y/2.f)-((this->text.getGlobalBounds().height)));//2.f è un divide reper 2 e dire che è un float*/
   //Colore
    this->idleColor_ = idleColor;
    this->hoverColor_ = hoverColor;
    this->activeColor_ = activeColor;

    void Button::updatestate( const sf::Vector2f mousePos){
     
        /*update the booleans for hover and pressed*/
     //Idle
     this->buttonState = BTN_IDLE ; 
     //Hover
      if (this->shape.getGlobalBounds().contains(mousePos))
      {
         this->buttonState = BTN_HOVER;  
      }
      //Pressed
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
      {
         this->buttonState = BTN_ACTIVE;  
      }
      switch (buttonState_)
      case BTN_IDLE:
          break;
      case BTN_HOVER:
          break;
      case BTN_ACTIVE:
          break;


    };
  
   void Button::render (sf::RenderTarget * target)
{
    target->draw(this->shape);
};


}
