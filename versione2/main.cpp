
#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <cmath>
#include <cstring>  //mi serve  per line
#include <ctime>    // ci serve per la funzione time che sta dentro al random
#include <fstream>  //serve per usare ifs
#include <iostream>
#include <typeinfo>



// random generation prototype function
double fRand(double, double);


int main() {

  
  std::cout << "Would you like to insert data from file, from standard input "
               "or run a random simulation? [F,S,R] \n";
  char data;
  std::cin >> data;

  while (data != 'F' && data != 'S' && data != 'R') {
    std::cout << "Invalid character, try again. \n";
    std::cin >> data;
  }



  if (data == 'F') {
    std::cout << "You've choosen data from file. \n";
    //Qui ci va il codice della Sofi
    //Quello vecchio è stato incollato e commentato al fondo
    

  } else if (data == 'S') {
    std::cout << "Great, you've choosen Standard Input, please insert: \n";

    std::cout << "The number of initial Susceptible [range 0-60000]" << std::endl;
    std::cin >> s;

    bool control;
    control=p.controlS(s);

    while(control==false){
    std::cout << "susceptible parameter out of range. Enter a new value: \n";
    std::cin >> s;
    control=p.controlS(s);
    }




    // Costructor calls
    People p;
    p.setPeople();
    int Num = p.getTotal();

    Parameters ps;
    ps.setParameters();

    int Time = controlTime();

    Sird oggetto(Time, p, ps, Num);
    oggetto.simulate();

  } else if (data == 'R') {
    std::cout << "Great, you've choosen Random generation, here's your datas: \n ";

    // Generate random seed for rand()
    srand(time(NULL));

    // Creating objects
    People p;
    Parameters ps;

    // Time elapse
    int Time = 30 + (rand() % 101);

    // Generate people for simulation
    double s = rand() % 500 + 5501;  // suscettibili tra 500 e 6000   5000-10000
    double i = rand() % 101;         // infetti tra 0 e 100
    double r = rand() % 501;         // resuscitati tra 0 e 500
    double d = rand() % 101;         // deceduti tra 0 e 100

    // Generate parameters for simulation
    char f;
    std::cout << "Do you want vaccination? [y/n]";
    std::cin >> f;
    while (f != 'y' && f != 'n') {
      std::cout << "Invalid char, try again.";
      std::cin >> f;
    }
    double a;

    if (f == 'y') {
      a = fRand(0.001, 0.01);  // between 0.001 e 0.01

    } else {
      a = 0;
    }

    double b = fRand(0.100, 0.900);  // between 0.1 e 0.9
    double g = fRand(0.100, 0.500);  //
    double u = fRand(0.100, 0.500);

    // Assign random values to class object and print them
    p.setPeopleR(s, i, r, d);
    int Num = p.getTotal();
    ps.setParametersR(a, b, g, u);

    std::cout << "The initial persons are: \n";
    std::cout << "Susceptible = " << s << '\n'
              << "Infected = " << i << '\n';
    std::cout << "Recovered = " << r << '\n'
              << "Dead = " << d << '\n';
    std::cout << "Total people =" << Num << '\n';

    std::cout << "The initial parameters are:";
    std::cout << "alfa = " << a << '\n' << "beta = " << b << '\n';
    std::cout << "gamma = " << g << '\n' << "mu = " << u << '\n';
    std::cout << "Simulation time= " << Time << '\n';

    // Starting proper simulation
    Sird oggetto(Time, p, ps, Num);
    oggetto.simulate();
  }
}

double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}

/*
std::string line;
    std::ifstream ifs;
    ifs.open("Data.txt");
    double s, i, r, d;
    double a, b, g, u;
    int Time;

    getline(ifs, line, '.');
    getline(ifs, line, ':');
    getline(ifs, line, '=');
    ifs >> s;
    getline(ifs, line, '=');
    ifs >> i;
    getline(ifs, line, '=');
    ifs >> r;
    getline(ifs, line, '=');
    ifs >> d;
    getline(ifs, line, ':');
    getline(ifs, line, '=');
    ifs >> a;
    getline(ifs, line, '=');
    ifs >> b;
    getline(ifs, line, '=');
    ifs >> g;
    getline(ifs, line, '=');
    ifs >> u;
    getline(ifs, line, '=');
    ifs >> Time;

    std::cout << a << '\n'
              << b << '\n'
              << g << '\n'
              << u << '\n';

    People p;
    Parameters ps;
    p.setPeople(s, i, r, d);
    int Num = p.getTotal();
    ps.setParameters(a, b, g, u);

    Sird oggetto(Time, p, ps, Num);
    oggetto.simulate();  */// DATO CHE L'OGGETTO SIMULATE è UGUALE PER TUTTI NON
                         // POSSIAMO CHIAMARLO FUORI DALL'IF? SE HA SENSO PER ME
                         // POTREMMO CHIAMARE FUORI DALL'IF TUTTO CIò CHE SI
                         // CHIAMA NELLO STESSO MODO E CHE è INDIPENDENTE DALLA
                         // SCELTA INZIIALE SUI DATI 