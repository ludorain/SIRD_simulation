 #include <SFML/Graphics.hpp>
//#include <SFML/Time.hpp>
//#include <SFML/Clock.hpp>
//#include <SFML/Window.hpp>
#include <iostream>
#include "pandemic.hpp"
//#include "button.hpp"
using namespace life;


int main (){
//creazione della finestra 
  
    sf::RenderWindow window(sf::VideoMode(200, 200), "Pandemic evolution");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))// finchè è vero continua il loop; pollEvent intervista gli eventi e se sono in sospeso ritorna true
        {
            sf::Text
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
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
