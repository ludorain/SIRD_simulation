#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <typeinfo>
#include <limits>
#include <iostream>
#include <chrono>
#include <thread>


#include "pandemic.hpp"
#include "parameters.hpp"


//Function for reading integers
bool readInt(int &x) {
  std::cin >> x;
  if(std::cin.fail()||std::cin.peek()!='\n')
  {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
  }
  return true;
}


int main () {

    Parameters ps;
    Pandemic population;

    float b,g,m;

    std::cout << "Infection probability [range 0-1]: ";
    std::cin >> b;
    ps.set_Beta(b);
    
    std::cout << "Recovery probability [range 0-0.5]: ";
    std::cin >> g;
    ps.set_Gamma(g);

    std::cout << "Death probability [range 0-0.5]: ";
    std::cin >> m;
    ps.set_Mu(m);
    

    try {
        int er = 2;
        
        if (ps.get_Gamma()+ps.get_Mu()>ps.get_Beta()){
            throw (er);
        }
    }

    catch(int er) {
        std::cerr<<"The epidemy won't start. Program abort. \n";
        exit(0);
    }


    //Init simulation values
    int l;
    std::cout<<"Please insert: \nGrid lengh = ";
    std::cin >> l;
    if (readInt(l)) {
      population.set_Side(l);
    } 
    

    int infected;
    std:: cout << "\nInfected = " ;
    std::cin >> infected ;
    if (readInt(infected)) {
      population.set_I(infected);
    } 


    int t;
    std::cout<<"\nSimulation time = ";
    std::cin >> t;
    if (t<0 || t>300) {
        t=50;
        std::cout<< "Value out of range. Initialized to 50";
    } 
    

    int mapSize = population.get_Side();


    //Init map variables
    float gridSizeF = 680/mapSize;
    //float dt;
    sf::Clock dtClock;

    //Init window     
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Pandemic evolution");

    //Create graphic elements
    sf::RectangleShape shape(sf::Vector2f(gridSizeF, gridSizeF));
    std::vector<std::vector <sf::RectangleShape>> tileMap;
    tileMap.resize(mapSize, std::vector<sf::RectangleShape>());

    population = Pandemic::start(population, population.get_I()); 

    //Initializing map with population initial values
    for(int x=0; x< mapSize; x++) {

        tileMap[x].resize(mapSize, sf::RectangleShape());

        for(int y=0; y< mapSize; y++) {
                
            tileMap[x][y].setSize(sf::Vector2f(gridSizeF, gridSizeF));
            tileMap[x][y].setOutlineThickness(1.f);
            tileMap[x][y].setOutlineColor(sf::Color::White);
            tileMap[x][y].setPosition(x*gridSizeF, y*gridSizeF);

            if (population.Reading_cell(x,y) == Person::Susceptible ) {
            
                tileMap[x][y].setFillColor(sf::Color::Blue);

            } else if(population.Reading_cell(x,y) == Person::Infected){

                tileMap[x][y].setFillColor(sf::Color::Red);
            }
        }
    }

    while (window.isOpen()){

        for(int x=0; x< mapSize; x++) {   

            for(int y=0; y< mapSize; y++) {

                window.draw(tileMap[x][y]);
            }
        }

        //update dt
        //dt = dtClock.restart().asSeconds();
        window.setView(window.getDefaultView());

        //Events
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close(); 
            }
        }

        window.clear();        
        window.draw(shape);

        for (int j = 0; j != t ; j++) {

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            population = Pandemic::evolve(population, ps);
            
            for(int x=0; x< mapSize; x++) {

                for(int y=0; y< mapSize; y++) {

                    if (population.Reading_cell(x,y) == Person::Susceptible )
                    {tileMap[x][y].setFillColor(sf::Color::Blue);}

                    if(population.Reading_cell(x,y) == Person::Infected)
                    {tileMap[x][y].setFillColor(sf::Color::Red);}

                    if(population.Reading_cell(x,y) == Person::Recovered)
                    {tileMap[x][y].setFillColor(sf::Color::Green);}

                    if(population.Reading_cell(x,y) == Person::Dead)
                    {tileMap[x][y].setFillColor(sf::Color::Black);}
                }
            }  

            for(int x=0; x< mapSize; x++) {   
                
                for(int y=0; y< mapSize; y++) {

                    window.draw(tileMap[x][y]);
                }
            }
            
            window.setView(window.getDefaultView());
        
            window.display();
       
            sf::Clock clock;
            //sf::Time dt = clock.restart();         
        
        }

    }

    return 0;

}