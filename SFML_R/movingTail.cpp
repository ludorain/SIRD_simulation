#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
//#include <SFML/Time.hpp>
//#include <SFML/Clock.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main (){

    //Init game
    const int mapSize = 20;
    float gridSizeF = 680/mapSize;
    float dt = 0.f;
    sf::Clock dtClock;
  
    //Input values
        //Messi costanti temporaneamente, finchè non troviamo il modo
        //di prendere dallo schermo
    int S0=390;
    int I0=10;
    int R0=0;
    int D0=0;


    //Init window     
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Pandemic evolution");
    //window.setFramerateLimit(120);

    //Init view
        //probabilmente qui non serve a niente
        /*
    sf::View view;
    view.setSize(1200, 900);
    view.setCenter(window.getSize().x/2.f, window.getSize().y/2.f);
    float viewSpeed = 200.f;*/
    

    //Init game elemets
    sf::RectangleShape shape(sf::Vector2f(gridSizeF, gridSizeF));

    

    //Questa scrittura creerebbe un oggetto static sullo stack, che supporta solo piccole dimensioni
    //sf::RectangleShape tileMap[mapSize][mapSize];

    //Meglio usare l'allocazione dinamica sullo heap per avere più manovra
    
    std::vector<std::vector <sf::RectangleShape>> tileMap;
    tileMap.resize(mapSize, std::vector<sf::RectangleShape>());

    //Initialized map with all susceptible (color Blue)

    for(size_t x=0; x< mapSize; x++)
    {   
        tileMap[x].resize(mapSize, sf::RectangleShape());

        for(size_t y=0; y< mapSize; y++)
        {   
            tileMap[x][y].setSize(sf::Vector2f(gridSizeF, gridSizeF));
            tileMap[x][y].setFillColor(sf::Color::Blue);
            tileMap[x][y].setOutlineThickness(1.f);
            tileMap[x][y].setOutlineColor(sf::Color::White);
            tileMap[x][y].setPosition(x*gridSizeF, y*gridSizeF);
        }
    }

    
    //std::cout<<tileMap[k][h].getFillColor();

    //Add I0 infected
   for (int j=0;j <= 10; j++)
  {
    srand(time(NULL));
    int k = rand() % mapSize;
    int h = rand() % mapSize;
     /*while (tileMap[k][h].getFillColor() == sf::Color::Red)
    {
      tileMap[k+1][h+1].setFillColor(sf::Color::Red);
      k++;
      h++;
    }*/
    tileMap[k][h].setFillColor(sf::Color::Red);
      
  }
    while (window.isOpen())
    {

        //QUI CI VA L'oggetto bottone, che se premuto consente di avviare i metodi


        //update dt
        dt = dtClock.restart().asSeconds();               
        window.setView(window.getDefaultView());       
               
        //Events

        sf::Event event;
        while (window.pollEvent(event))// finchè è vero continua il loop; pollEvent intervista gli eventi e se sono in sospeso ritorna true
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //Reder game elements
             
        window.draw(shape);       
        

        for(size_t x=0; x< mapSize; x++)
        {
            for(size_t y=0; y< mapSize; y++)
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
