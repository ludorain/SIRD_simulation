 #include <SFML/Graphics.hpp>
//#include <SFML/Time.hpp>
//#include <SFML/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
//#include "pandemic.hpp"
//#include "button.hpp"
//using namespace life;


int main (){
//creazione della finestra
    //Init game
    float gridSizeF = 100.f;
    unsigned gridSizeU= static_cast<unsigned>(gridSizeF);
    float dt = 0.f;
    sf::Clock dtClock;
    //Init window     
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pandemic evolution");
    sf::View view;
    view.setSize(1000.f, 1000.f);
    view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);
    float viewSpeed = 200.f;
    sf::RectangleShape shape(sf::Vector2f(gridSizeF, gridSizeF));

    //Init game elemets
    while (window.isOpen())
    {
        //update dt
        dt = dtClock.restart().asSeconds();
        //Events

        sf::Event event;
        while (window.pollEvent(event))// finchè è vero continua il loop; pollEvent intervista gli eventi e se sono in sospeso ritorna true
        {
            //sf::Text

            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update place

        //Update input
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            view.move(-viewSpeed * dt, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
             view.move(viewSpeed * dt, 0.f);
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            view.move(0.f, -viewSpeed * dt);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
             view.move(0.f, viewSpeed * dt);
        }

        window.clear();
        window.setView(view);

        //Reder elements
        window.draw(shape);

        window.setView(window.getDefaultView()); //this is gonna reset the view at the end of the drawing





        
        window.display();
        //////////////////////////////////////////////
        sf::Clock clock;
        sf::Time elapsed = clock.restart();
    }
    //creazione dei bottoni 
//creazione della griglia, con cambiamento delle celle coi 4 colori associati (nero=morti, blu=susciettibili, rosso=infettati, verde=guariti): display.hpp
 //class Pandemic ;
 /*int l;
 std::cin >> l;
 Pandemic population(l);
//inserimento dei dati input 
 //struct Probability;
 Probability prob_;
 std::cin >> prob_.beta ;
 std::cin >> prob_.alfa;
 std::cin >> prob_.gamma;
 prob_.omega = 100-prob_.omega;
 //struct Count;
 Count count_;
 std::cin >> count_.s;
 std::cin >> count_.i;
 std::cin >> count_.r;
 std::cin >> count_.d;
 int T;
 std::cin >> T;
//avviamento dell'esecuzione 
    for (int i = 0;i<= T ; i++){
   std::cout<< population << std::endl;
   //chiamata evolve()
   population = population.evolve(population, prob_, count_);
    }*/
}
