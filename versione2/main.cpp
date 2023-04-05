
#include <cmath>
#include <cstring>  //mi serve  per line
#include <ctime>    // ci serve per la funzione time che sta dentro al random
#include <fstream>  //serve per usare ifs
#include <iostream>
#include <typeinfo>
#include <limits>

#include "parameters.hpp"
#include "people.hpp"
#include "pandemic.hpp"
#include "ini.h"

// random generation prototype function
double fRand(double, double);

bool readInt(int &x) {
  std::cin >> x;
  if(std::cin.fail() || std::cin.bad())
  //if (!std::cin.good()) 
  {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return false;
  }
  return true;
}

int main() {
  int s, i, r, d;
  int Num;
  double a, b, g, m;
  int t;
  People p;
  Parameters ps;
  char data;
  char vax;
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
    s = std::stoi(ini.get("PEOPLE").get("Susceptibles"));
    i = std::stoi(ini.get("PEOPLE").get("Infected"));
    r = std::stoi(ini.get("PEOPLE").get("Recovered"));
    d = std::stoi(ini.get("PEOPLE").get("Dead"));
    a = std::stod(ini.get("PARAMETERS").get("alfa"));
    b = std::stod(ini.get("PARAMETERS").get("beta"));
    g = std::stod(ini.get("PARAMETERS").get("gamma"));       
    m = std::stod(ini.get("PARAMETERS").get("mu"));
    t = std::stoi(ini.get("PARAMETERS").get("time"));      
    

    control = p.set_S(s);

    if (control == false) {
      std::cout << "Susceptible value out of range, initialized to default (60000). \n";
    }

    control = p.set_I(i);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (40). \n";
    }

    p.control_SI();

    control = p.set_R(r);

    if (control == false) {
      std::cout << "Recovered value out of range, initialized to default (0). \n";
    }

    control = p.set_D(d);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (0). \n";
    }


    if(a==0){
      ps.set_Zero();
    } else {
    control = ps.set_Alfa(a);

      if (control == false){
        std::cout << "Vaccination parameter out of range, initialized to default (0.001). \n";
      } 
    }
    

    control = ps.set_Beta(b);

    if (control == false){
      std::cout << "Infectivity parameter out of range, initialized to default (0.85). \n";
    }

    control = ps.set_Gamma(g);

    if (control == false){
      std::cout << "Recovery parameter out of range, initialized to default (0.2). \n";
    }


    control = ps.set_Mu(m);
    
    if (control == false){
      std::cout << "Death parameter out of range, initialized to default (0.2). \n";
    }

    ps.control_R0();

    //Pandemic oggetto(p, ps, t);
    Pandemic oggetto;
    control = oggetto.set_Pandemic(p, ps, t);

    if (control == false){
      std::cout << "Time out of range, initialized to default (50 days). \n";
    }

    oggetto.simulate();
    oggetto.print();


  //INGRESSO DA STANDARD INPUT
  } else if (data == 'S') { 
  
    std::cout << "Great, you've choosen Standard Input, please insert: \n";
    std::cout << "The number of initial  \n";
    std::cout << "Susceptible [range 0-60000]: ";
    //std::cin >> s;
    //readInt(s, 60000);

    /*control1=readInt(s);
    if (control1) {
      control = p.set_S(s); */
      
    if (readInt(s)) {
      control = p.set_S(s);

      if (control == false) {
        std::cout << "Susceptible value out of range, initialized to default (60000). \n";
      } 
    } else {
      std::cout << "You entered a non-integer value, susceptible value initialized to default (60000). \n";
    }

    std::cout << "Infected [range 0-6000]: ";
    std::cin >> i;
    control = p.set_I(i);

    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (40). \n";
    }

    p.control_SI();

    std::cout << "Recovered [range 0-6000]: ";
    std::cin >> r;
    control = p.set_R(r);

    if (control == false) {
      std::cout << "Recovered value out of range, initialized to default (0). \n";
    }

    std::cout << "Deaths [range 0-6000]: ";
    std::cin >> d;
    control = p.set_D(d);
    if (control == false) {
      std::cout << "Infected value out of range, initialized to default (0). \n";
    }

    std::cout << "Do you want vaccination? [y/n] \n";
    std::cin >> vax;

    while (vax != 'y' && vax != 'n') {
    std::cout << "Invalid char, try again. \n";
    std::cin >> vax;  }

    if (vax == 'y') {
      std::cout << "Rate vaccination [range 0.001-0.01]: ";
      std::cin >> a;
      
      control = ps.set_Alfa(a);
      if (control == false){
        std::cout << "Vaccination parameter out of range, initialized to default (0.001). \n";
      } 
    } else { ps.set_Zero();}

    std::cout << "Infection probability [range 0-1]: ";
    std::cin >> b;
    control = ps.set_Beta(b);
    if (control == false){
      std::cout << "Infection parameter out of range, initialized to default (0.85). \n";
    }

    std::cout << "Recovery probability [range 0-0.5]: ";
    std::cin >> g;
    control = ps.set_Gamma(g);
    if (control == false){
      std::cout << "Recovery parameter out of range, initialized to default (0.2). \n";
    }

    std::cout << "Death probability [range 0-0.5]: ";
    std::cin >> m;
    control = ps.set_Mu(m);
    if (control == false){
      std::cout << "Death parameter out of range, initialized to default (0.2). \n";
    }

    ps.control_R0();

    std::cout << "Simulation time \n";
    std::cin >> t;

    Pandemic oggetto;
    control = oggetto.set_Pandemic(p, ps, t);

    if (control == false){
      std::cout << "Time out of range, initialized to default (50 days). \n";
    }
    oggetto.simulate();
    oggetto.print();


  } else if (data == 'R') {
    
    People p;
    Parameters ps;
    std::cout
        << "Great, you've choosen Random generation, here's your datas: \n ";

    // Generate random seed for rand()
    std::srand(time(NULL));

    // Time elapse
    t = 30 + (std::rand() % 101);

    // Generate people for simulation
    s = std::rand() % 500 + 5501;  // suscettibili tra 500 e 6000   5000-10000
    i = std::rand() % 101;         // infetti tra 0 e 100
    r = std::rand() % 501;         // resuscitati tra 0 e 500
    d = std::rand() % 101;         // deceduti tra 0 e 100

    // Generate parameters for simulation    
    a = fRand(0.000, 0.01);  // between 0.00 e 0.01
    b = fRand(0.400, 0.900);  // between 0.1 e 0.9
    g = fRand(0.001, 0.200);  //
    m = fRand(0.001, 0.100);

    // Assign random values to class object and print them
    p.set_People(s, i, r, d);    
    ps.set_Parameters(a, b, g, m);
    Num = p.getTotal();

    std::cout << "The initial persons are: \n";
    std::cout << "Susceptible = " << s << '\n' << "Infected = " << i << '\n';
    std::cout << "Recovered = " << r << '\n' << "Dead = " << d << '\n';
    std::cout << "Total people =" << Num << '\n';

    std::cout << "The initial parameters are: \n";
    std::cout << "alfa = " << a << '\n' << "beta = " << b << '\n';
    std::cout << "gamma = " << g << '\n' << "mu = " << m << '\n';
    std::cout << "Simulation time= " << t << '\n';

    // Starting proper simulation
    
    Pandemic oggetto;
    control = oggetto.set_Pandemic(p, ps, t);

     
    oggetto.simulate();
    oggetto.print();
  }
}


double fRand(double fMin, double fMax) 
{
  
  double f = static_cast<double>(std::rand()) / RAND_MAX;
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
