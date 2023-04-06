 #include <SFML/Graphics.hpp>
//#include <SFML/Time.hpp>
//#include <SFML/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include "pandemic.hpp"
//#include "button.hpp"
//using namespace life;


int main (){
//Init simulation values
class Pandemic ;
//sicuramente c'è un modo per compattare righe 18-21
//ora sono stanca e non mi viene in mente
int l;
std::cout<<"lengh";
std::cin >> l;
const int mapSize = l;
//Input values
life::Count count;
std::cout<<"i \n";
std::cin >> count.i;
if(count.i>mapSize/20){
    std::cout<<"Eccessive number of initial infected, reduced to" << std::round(mapSize/20) << '\n';
    count.i=std::round(mapSize/20);
}


count.s= ;
count.r=0;
count.d=0;

int T;
std::cout<<"Time \n";
std::cin >> T;
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
life::Pandemic population(l);
life::Probability prob_={1,30,10,1};


    /*Se volessimo mettere un bottone qui ci andrebbe
    l'if(botton is pressed)*/

//Set population (Pandemic object) with initial values
population = life::Pandemic::start(population, count.i); 
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

    

    /*
    population.Writing_cell(4,3) = life::Person::Infected;
    population.Writing_cell(3,3) = life::Person::Infected;
    population.Writing_cell(5,3) = life::Person::Infected;
    population.Writing_cell(5,2) = life::Person::Infected;
    population.Writing_cell(3,2) = life::Person::Infected;
    population.Writing_cell(5,5) = life::Person::Infected;
    */
    
    

    return 0;
  
}
