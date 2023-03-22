#include "sird.hpp"
#include <iostream>
#include <cstring>  //PER ME NON CI SERVE PIù PERCHE HO CAVATO LA STRINGA CONTROL
#include <ctime> // ci serve per la funzione time che sta dentro al random

int main () {
    std:: cout << "Would you like to insert data from file, from standard input or run a random simulation? [F,S,R]" << std::endl; 
    char data;
    std:: cin >> data;
    while (data!='F' && data!='S' && data!='R') {
        std:: cout << "Invalid character, try again." << std:: endl;
        std:: cin >> data;
    }
    
    switch (data) {
        case 'F' : 
            std::cout << "Qui ci andrà la simulazione da file, non l'ho ancora implementata XD"<< std::endl;
            break;

        case 'S' :
            std::cout << "Siamo in S" << std::endl;
            People p;
            p.setPeople();
            Parameters ps;
    
            int Time;
            int Num=p.getTotal();
            std::cout << "Insert time simulation"<<std::endl;
            std::cin>>Time;
            sird oggetto(Time, p, ps, Num);
            oggetto.simulate(); 
            break;

        case 'R' :
            std::cout << "Siamo in R" << std::endl;
          
            //Random simulation elapse
            int Time = 10+ (rand() % 100);
            
            //setting people
            People p;
            double s, i, r, d;
            //Inizializzo il generatore di numeri random e rendo casuale il seme
            srand(time(NULL));
            s= rand() % 5501 + 500; //suscettibili tra 500 e 6000  
            i= rand() % 101; //infetti tra 0 e 100
            r=rand() % 501;  //resuscitati tra 0 e 500
            d=rand() % 201; //deceduti tra 0 e 200
            std:: cout << "Your random values are:" << std:: endl <<
                "Susceptible = " << s << std::endl << "Infected = " << i << std::endl << 
                "Recovered = " << r << std::endl << "Dead = " << d << std::endl; 
            p.setPeople(s, i, r, d);
            int Num=p.getTotal();
        
            Parameters ps;

            sird oggetto(Time, p, ps, Num);
            oggetto.simulate(); 
            break;

        // default: std:: cout << "Invalid character.";  NON PENSO SERVA XKE NON DOVREBBE MAI ARRIVARE QUI
    }
}




