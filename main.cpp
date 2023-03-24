#include "sird.hpp"
#include <iostream>
#include <ctime> // ci serve per la funzione time che sta dentro al random

int main () {
    std:: cout << "Would you like to insert data from file, from standard input or run a random simulation? [F,S,R]" << std::endl; 
    char data;
    std:: cin >> data;
    while (data!='F' && data!='S' && data!='R') {
        std:: cout << "Invalid character, try again." << std:: endl;
        std:: cin >> data;
    }
    
    if (data == 'F') {
            std::cout << "Qui ci andrà la simulazione da file, non l'ho ancora implementata XD"<< std::endl;

    } else if (data == 'S') {
            std::cout << "Siamo in S" << std::endl;
            People p;
            p.setPeople();
            Parameters ps;
            ps.setParameters();
            int Time;
            int Num=p.getTotal();
            std::cout << "Insert time simulation"<<std::endl;
            std::cin>>Time;
            sird oggetto(Time, p, ps, Num);
            oggetto.simulate(); 

     } else if (data == 'R') {
            std::cout << "Siamo in R" << std::endl;
          
            //Random simulation elapse
            int Time = 10+ (rand() % 100);
            
            //setting people
            People p;
            double s, i, r, d, a, b, g, u;
            //Inizializzo il generatore di numeri random e rendo casuale il seme
            srand(time(NULL));
            s=rand() % 5001 + 5000; //suscettibili tra 500 e 6000   5000-10000
            i=rand() % 101; //infetti tra 0 e 100
            r=rand() % 501;  //resuscitati tra 0 e 500
            d=rand() % 101; //deceduti tra 0 e 100
            std:: cout << "Your random values are:" << std:: endl <<
                "Susceptible = " << s << std::endl << "Infected = " << i << std::endl << 
                "Recovered = " << r << std::endl << "Dead = " << d << std::endl; 
            p.setPeople(s, i, r, d);
            int Num=p.getTotal();
            std:: cout << "People =" << Num << std::endl;

            a= 0.01; //tra 0.001 e 0.01 --> 1-10 
            b=(rand()%9+1)/10.; //tra 0.1 e 0.9
            g=0.2;  // non oltre 0.5
            u=0.2; //

            std:: cout << "Your random values are:" << std:: endl <<
                "alfa = " << a << std::endl << "beta = " << b << std::endl << 
                "gamma = " << g << std::endl << "mu = " << u << std::endl; 
            
            Parameters ps;
            ps.setParameters(a,b,g,u);

            std:: cout << "Simulation time= " << Time <<std::endl;
            sird oggetto(Time, p, ps, Num);
            oggetto.simulate();

        // default: std:: cout << "Invalid character.";  NON PENSO SERVA XKE NON DOVREBBE MAI ARRIVARE QUI
    }
}



