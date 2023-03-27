#include "sird.hpp"
#include <iostream>
#include <ctime> // ci serve per la funzione time che sta dentro al random
#include <cstring> //mi serve  per line
#include <fstream> //serve per usare ifs


//random generation prototype function
double fRand(double, double);

int main () {

std:: cout << "Would you like to insert data from file, from standard input or run a random simulation? [F,S,R]" << std::endl; 
char data;
std:: cin >> data;

while (data!='F' && data!='S' && data!='R') {
std:: cout << "Invalid character, try again." << std:: endl;
std:: cin >> data; 
}
    
if (data == 'F') {

    std::cout << "Tentativo 1° simulazione file:"<< std::endl;
    
    std::string line;
    std::ifstream ifs;
    ifs.open("Data.txt");
    double s,i,r,d;
    double a,b,g,u;

    getline (ifs,line,'.');
    getline (ifs,line, ':');
    getline (ifs,line,'=');
    ifs >> s;
    getline (ifs,line,'=');
    ifs >> i;
    getline (ifs,line,'=');
    ifs >> r,
    getline (ifs,line,'=');
    ifs >> d;
    getline (ifs,line,':');
    getline (ifs,line,'=');
    ifs >> a;
    getline (ifs,line,'=');
    ifs >> b;
    getline (ifs,line,'=');
    ifs >> g,
    getline (ifs,line,'=');
    ifs >> u;

    std:: cout << s << std:: endl << i << std:: endl << r << std:: endl << d << std:: endl;

} else if (data == 'S') {

    std::cout << "Great, you've choosen Standard Input, please insert " << std::endl;
    
    //Costructor calls
    People p;
    p.setPeople();
    int Num=p.getTotal();

    Parameters ps;
    ps.setParameters();

    int Time;    
    std::cout << "Insert time simulation"<<std::endl;
    std::cin>>Time;

    sird oggetto(Time, p, ps, Num);
    oggetto.simulate(); 

} else if (data == 'R') {
    std::cout << "Great, you've choosen Random generation, here's your datas" << std::endl;
    
    //Generate random seed for rand()
    srand(time(NULL));

    //Creating objects 
    People p;
    Parameters ps;

    //Time elapse
    int Time = 30+ (rand() % 100);

    //Generate people for simulation
    double s=rand() % 500 + 5501; //suscettibili tra 500 e 6000   5000-10000
    double i=rand() % 101; //infetti tra 0 e 100
    double r=rand() % 501;  //resuscitati tra 0 e 500
    double d=rand() % 101; //deceduti tra 0 e 100

    //Generate parameters for simulation
    double a= fRand(0.001, 0.01); //between 0.001 e 0.01
    double b=fRand(0.100, 0.900); //between 0.1 e 0.9
    double g=fRand(0.100, 0.500); //
    double u=fRand(0.100, 0.500);

    // Assign random values to class object and print them
    p.setPeopleR(s, i, r, d);
    int Num=p.getTotal();
    ps.setParametersR(a,b,g,u);

    std::cout << "The initial persons are:" << std:: endl;
    std::cout << "Susceptible = " << s << std::endl << "Infected = " << i << std::endl;
    std::cout << "Recovered = " << r << std::endl << "Dead = " << d << std::endl;   
    std::cout << "Total people =" << Num << std::endl;

    std::cout << "The initial parameters are:" << std:: endl;
    std::cout << "alfa = " << a << std::endl << "beta = " << b << std::endl;
    std::cout << "gamma = " << g << std::endl << "mu = " << u << std::endl;
    std::cout << "Simulation time= " << Time <<std::endl;

    //Starting proper simulation
    sird oggetto(Time, p, ps, Num);
    oggetto.simulate();

}
}

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}



