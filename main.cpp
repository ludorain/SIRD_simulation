#include "sird.hpp"
#include <iostream>
#include <cstring> 

int main (void) {
    
    std::string control;
    std::string control2;

    std:: cout <<  "Do you want to insert your data or run a random simulation? (data/random)"; 
    std:: cin >> control;

    if (control == "data"){
        std:: cout <<  "Would you like to insert data from file o standard input? (file/std)"; 
        std:: cin >> control2;

        if (control2 == "file") {
        std::cout << "Qui ci andrà la simulazione da file, non l'ho ancora implementata XD";
           
        } else {
        //standard input simulation
        People p;
        p.setPeople();

        Parameters ps;
        
        int Time;
        int Num=p.getTotal();
        std::cout << "Insert time simulation"<<std::endl;
        std::cin>>Time;
        sird(Time, p, ps, Num);
        }
    } else {
        //Random simulation elapse
        int Time = 10 + rand() % 91 ; //tempo tra 0 e 100 
        
        //setting people
        People p;
        double s, i, r, d;
        s= rand() % 5501 + 500; //suscettibili tra 500 e 6000  
        i= rand() % 101; //infetti tra 0 e 100
        r=rand() % 501;  //resuscitati tra 0 e 500
        d=rand() % 201; //deceduti tra 0 e 200
        std:: cout << "Your random values are:" << std:: endl <<
               "Susceptible = " << s << std::endl << "Infected = " << i << std::endl << 
               "Recovered = " << r << std::endl << "Dead = " << d << std::endl; 
        p.setPeopleR(s, i, r, d);
        int Num=p.getTotal();

        //analogo per i parametri, da implementare
}
}
