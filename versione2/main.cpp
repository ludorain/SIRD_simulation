
#include <cmath>
#include <cstring>  //mi serve  per line
#include <ctime>    // ci serve per la funzione time che sta dentro al random
#include <fstream>  //serve per usare ifs
#include <iostream>
#include <typeinfo>

//#include "pandemic.hpp"
#include "parameters.hpp"
#include "people.hpp"
#include "sird.hpp"
#include "ini.h"

// random generation prototype function
double fRand(double, double);

int main() {
  int s, i, r, d;
  int Num;
  double a, b, g, m;
  int t;

  char data;
  char f;
  bool control, control1; 

  std::cout << "Would you like to insert data from file, from standard input "
               "or run a random simulation? [F,S,R] \n";
  std::cin >> data;

  while (data != 'F' && data != 'S' && data != 'R') {
    std::cout << "Invalid character, try again. \n";
    std::cin >> data;
  }

  if (data == 'F') {
    std::cout << "You've choosen data from file. \n";
    
    // Create a file instance & create a structure that will hold data
    mINI::INIFile file("data.ini");
    mINI::INIStructure ini;

    // Read the file
    file.read(ini);
    
    // read values ini.get("section").get("key")
    // il metodo stoi() = string to int
    s = stoi (ini.get("PEOPLE").get("Susceptibles"));
    i = stoi (ini.get("PEOPLE").get("Infected"));
    r = stoi (ini.get("PEOPLE").get("Recovered"));
    d = stoi (ini.get("PEOPLE").get("Dead"));
    a = std::stod(ini.get("PARAMETERS").get("alfa"));
    b = std::stod(ini.get("PARAMETERS").get("beta"));
    g = std::stod(ini.get("PARAMETERS").get("gamma"));       
    m = std::stod(ini.get("PARAMETERS").get("mu"));
        
    //COMMENTI: stod funziona sia con std:: sia senza, non so se mettercelo o no
    // PROVE DI STAMPA A VIDEO PER VEDERE SE FUNZIONA
    std:: cout << s << '\n' << i << '\n' << r << '\n' << d << '\n'
    << a << '\n' << b << '\n'<< g << '\n' << m << '\n';
    
    std::cout << s+i+r+d << '\n';
    std::cout << a+b+g+m <<'\n';

    //aggiungere assegnazione e simulazione

  //INGRESSO DA STANDARD INPUT
  } else if (data == 'S') { 
  
    People p;
    Parameters ps;

    std::cout << "Great, you've choosen Standard Input, please insert: \n";
    std::cout << "The number of initial  \n";

    std::cout << "Susceptible [range 0-60000]: ";
    std::cin >> s;
    control = p.set_S(s);

    if (control == false) {
      std::cout << "Susceptible value out of range, initialized to default. \n";
    }

    std::cout << "Infected [range 0-6000]: ";
    std::cin >> i;
    control = p.set_I(i);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default. \n";
    }

    p.control_SI();

    std::cout << "Recovered [range 0-6000]: ";
    std::cin >> r;
    control = p.set_R(r);

    if (control == false) {
      std::cout << "Recovered value out of range, initialized to default. \n";
    }

    std::cout << "Deaths [range 0-6000]: ";
    std::cin >> d;
    control = p.set_D(d);
    if (control == false) {
      std::cout << "Infected value out of range, initialized to default. \n";
    }

    int Num = p.getTotal();

    std::cout << "Do you want vaccination? [y/n] \n";
    std::cin >> f;

    while (f != 'y' && f != 'n') {
    std::cout << "Invalid char, try again. \n";
    std::cin >> f;  }

    if (f == 'y') {
      std::cout << "Rate vaccination [range 0.001-0.01]: ";
      std::cin >> a;
      
      control = ps.set_Alfa(a);
      if (control == false){
        std::cout << "Parameter out of range, initialized to default. \n";
      } else { ps.set_Zero();}
    }

    std::cout << "Infection probability [range 0-1]: ";
    std::cin >> b;
    control = ps.set_Beta(b);
    if (control == false){
      std::cout << "Parameter out of range, initialized to default. \n";
    }

    std::cout << "Recovery probability [range 0-0.5]: ";
    std::cin >> g;
    control = ps.set_Gamma(g);
    if (control == false){
      std::cout << "Parameter out of range, initialized to default. \n";
    }

    std::cout << "Death probability [range 0-0.5]: ";
    std::cin >> m;
    control = ps.set_Mu(m);
    if (control == false){
      std::cout << "Parameter out of range, initialized to default. \n";
    }

    ps.control_R0();

    std::cout << "Simulation time \n";
    std::cin >> t;

    //Pandemic oggetto(ps, p, t);
    Sird oggetto(ps, p, t);
    oggetto.simulate();
    oggetto.print();


  } else if (data == 'R') {
    //int s, i, r, d;   GIA DICHIARATI FUORI
    //double a, b, g, m; UGUALE A SOPRA
    People p;
    Parameters ps;
    std::cout
        << "Great, you've choosen Random generation, here's your datas: \n ";

    // Generate random seed for rand()
    srand(time(NULL));

    // Time elapse
    t = 30 + (rand() % 101);

    // Generate people for simulation
    s = rand() % 500 + 5501;  // suscettibili tra 500 e 6000   5000-10000
    i = rand() % 101;         // infetti tra 0 e 100
    r = rand() % 501;         // resuscitati tra 0 e 500
    d = rand() % 101;         // deceduti tra 0 e 100

    // Generate parameters for simulation    
    a = fRand(0.001, 0.01);  // between 0.001 e 0.01
    b = fRand(0.100, 0.900);  // between 0.1 e 0.9
    g = fRand(0.001, 0.400);  //
    m = fRand(0.001, 0.400);

    // Assign random values to class object and print them
    p.set_People(s, i, r, d);    
    ps.setParametersR(a, b, g, m);
    Num = p.getTotal();

    std::cout << "The initial persons are: \n";
    std::cout << "Susceptible = " << s << '\n' << "Infected = " << i << '\n';
    std::cout << "Recovered = " << r << '\n' << "Dead = " << d << '\n';
    std::cout << "Total people =" << Num << '\n';

    std::cout << "The initial parameters are:";
    std::cout << "alfa = " << a << '\n' << "beta = " << b << '\n';
    std::cout << "gamma = " << g << '\n' << "mu = " << m << '\n';
    std::cout << "Simulation time= " << t << '\n';

    // Starting proper simulation
    Sird oggetto(ps, p, t);
    oggetto.simulate();
    //oggetto.print();
  }
}


double fRand(double fMin, double fMax) 
{
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
