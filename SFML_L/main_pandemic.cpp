#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "pandemic.hpp"


int main () {

    //Init simulation values
    class Pandemic;
    Count count;


    int l;
    std::cout<<"Please insert: \n Grid lengh = ";
    std::cin >> l;

    bool control;
    control = count.set_L(l);
    if ( control == false ) {
        std::cout<< "Value out of range. Initialized to default.";
    } 


    int infected;
    std:: cout << "Infected = " ;
    std::cin >> infected ;

    bool control;
    control = count.set_I(infected);
    if ( control == false ) {
        std::cout<< "Value out of range. Initialized to default.";
    } 

    int gamma;
    std:: cout << "Gamma = " ;
    std::cin >> gamma ;

    int mu;
    std:: cout << "Mu = " ;
    std::cin >> mu ;

    const int mapSize = l;
    ////BOH
    if(count.I_>mapSize/20){
        std::cout<<"Eccessive number of initial infected, reduced to" << std::round(mapSize/20) << '\n';
        count.i=std::round(mapSize/20);
    }


    count.S_= ;
    count.R_=0;
    count.D_=0;

    int T;
    std::cout<<"Simulation time = ";
    std::cin >> T;

    bool control;
    control = ;
    if ( control == false ) {
        std::cout<< "Value out of range. Initialized to default.";
    }

    //Init map variables
    float gridSizeF = 680/mapSize;
    float dt = 0.f;
    sf::Clock dtClock;


    //Init window     
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Pandemic evolution");

    //Create graphic elements
    sf::RectangleShape shape(sf::Vector2f(gridSizeF, gridSizeF));
    std::vector<std::vector <sf::RectangleShape>> tileMap;
    tileMap.resize(mapSize, std::vector<sf::RectangleShape>());

    //Creating simulation objects
    Pandemic population(l);
    population.check_number(count_.i,l);//the grid side and the infected number input control 
    Probability prob_={0.1,0.30,0.10,0.1};


        /*Se volessimo mettere un bottone qui ci andrebbe
        l'if(botton is pressed)*/

    //Set population (Pandemic object) with initial values
    population = Pandemic::start(population, count.i); 
    //std::cout<< population << std::endl;

    //Initializing map with population initial values
    for(size_t x=0; x< mapSize; x++)
        {   
            tileMap[x].resize(mapSize, sf::RectangleShape());

            for(size_t y=0; y< mapSize; y++)
            {   
                tileMap[x][y].setSize(sf::Vector2f(gridSizeF, gridSizeF));
                tileMap[x][y].setOutlineThickness(1.f);
                tileMap[x][y].setOutlineColor(sf::Color::White);
                tileMap[x][y].setPosition(x*gridSizeF, y*gridSizeF);

                if (population.Reading_cell(x,y) == life::Person::Susceptible )
                {
                tileMap[x][y].setFillColor(sf::Color::Blue);
                } else if(population.Reading_cell(x,y) == life::Person::Infected)
                    {
                    tileMap[x][y].setFillColor(sf::Color::Red);
                    }
            }
        }

        while (window.isOpen())
        {
            for(size_t x=0; x< mapSize; x++)        
                {   for(size_t y=0; y< mapSize; y++)  
                    { 
                        window.draw(tileMap[x][y]);
                    }
                }
            //update dt
            dt = dtClock.restart().asSeconds();
            window.setView(window.getDefaultView());

            //Events
            sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                    window.close(); 
                    }
                }

            window.clear();        
            window.draw(shape);

            //forse ci va un primo draw tileMap qui

            for (int j = 0; j != T ; j++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                population = life::Pandemic::evolve(population, prob_, count);
                
                // idealmente metodo draw_map()
                for(size_t x=0; x< mapSize; x++)
                {
                    for(size_t y=0; y< mapSize; y++)
                    {   
                        if (population.Reading_cell(x,y) == life::Person::Susceptible )
                        {tileMap[x][y].setFillColor(sf::Color::Blue);}

                        if(population.Reading_cell(x,y) == life::Person::Infected)
                        {tileMap[x][y].setFillColor(sf::Color::Red);}

                        if(population.Reading_cell(x,y) == life::Person::Recovered)
                            {tileMap[x][y].setFillColor(sf::Color::Green);}

                        if(population.Reading_cell(x,y) == life::Person::Dead)
                            {tileMap[x][y].setFillColor(sf::Color::Black);}
                    }
                }  

                for(size_t x=0; x< mapSize; x++)        
                {   for(size_t y=0; y< mapSize; y++)  
                    { 
                        window.draw(tileMap[x][y]);
                    }
                }
            window.setView(window.getDefaultView()); //this is gonna reset the view at the end of the drawing
        
            window.display();
            //////////////////////////////////////////////
            sf::Clock clock;
            sf::Time elapsed = clock.restart();
            }
            

        
        }

        //creazione dei bottoni 
        
        //creazione della griglia, con cambiamento delle celle coi 4 colori associati (nero=morti, blu=susciettibili, rosso=infettati, verde=guariti): display.hpp
  
    return 0;

}

