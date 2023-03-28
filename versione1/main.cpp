#include "sird.hpp"
#include <iostream>
#include <ctime> // ci serve per la funzione time che sta dentro al random
#include <cmath> 
#include <cstring> //mi serve  per line
#include <fstream> //serve per usare ifs
#include <typeinfo>


//random generation prototype function
double fRand(double, double);
double controlTime();

int main () {

std:: cout << "Would you like to insert data from file, from standard input or run a random simulation? [F,S,R]" << std::endl; 
char data;
std:: cin >> data;

while (data!='F' && data!='S' && data!='R') {
std:: cout << "Invalid character, try again." << std:: endl;
std:: cin >> data; 
}
    
if (data == 'F') {

    std::cout << "Great, you've choosen ..."<< std::endl;
    
    std::string line;
    std::ifstream ifs;
    ifs.open("Data.txt");
    double s,i,r,d;
    double a,b,g,u;
    int Time; 

    getline (ifs,line,'.');
    getline (ifs,line, ':');
    getline (ifs,line,' ');
    ifs >> s;
    getline (ifs,line,' ');
    ifs >> i;
    getline (ifs,line,' ');
    ifs >> r,
    getline (ifs,line,' ');
    ifs >> d;
    getline (ifs,line,':');
    getline (ifs,line,' ');
    ifs >> a;
    getline (ifs,line,' ');
    ifs >> b;
    getline (ifs,line,' ');
    ifs >> g,
    getline (ifs,line,' ');
    ifs >> u;
    getline (ifs,line,' ');
    ifs >> Time;

    std:: cout << a << std:: endl << b << std:: endl << g << std:: endl << u << std:: endl;
    
    People p;
    Parameters ps;
    p.setPeople(s, i, r, d);
    int Num=p.getTotal();
    ps.setParameters(a,b,g,u); 

    sird oggetto(Time, p, ps, Num);
    oggetto.simulate(); //DATO CHE L'OGGETTO SIMULATE è UGUALE PER TUTTI NON POSSIAMO CHIAMARLO FUORI DALL'IF? SE HA SENSO PER ME POTREMMO CHIAMARE FUORI DALL'IF TUTTO CIò CHE SI CHIAMA NELLO STESSO MODO E CHE è INDIPENDENTE DALLA SCELTA INZIIALE SUI DATI

} else if (data == 'S') {

    std::cout << "Great, you've choosen Standard Input, please insert " << std::endl;
    
    //Costructor calls
    People p;
    p.setPeople();
    int Num=p.getTotal();

    Parameters ps;
    ps.setParameters();

    int Time=controlTime();    
    
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
    int Time = 30+ (rand() % 101);

    //Generate people for simulation
    double s=rand() % 500 + 5501; //suscettibili tra 500 e 6000   5000-10000
    double i=rand() % 101; //infetti tra 0 e 100
    double r=rand() % 501;  //resuscitati tra 0 e 500
    double d=rand() % 101; //deceduti tra 0 e 100

    //Generate parameters for simulation
    char f;
    std::cout<<"Do you want vaccination? [y/n]";
    std::cin>>f;
    while(f!='y' && f!='n'){
    std::cout<<"Invalid char, try again.";
    std::cin>>f; }
    double a;

    if(f=='y')
    { a= fRand(0.001, 0.01); //between 0.001 e 0.01
    
    } else {a=0;}
    
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

double controlTime(){

double t;
double fractPart, intPart;
    
    std::cout << "Insert time simulation"<<std::endl;
    std::cin>>t;
   
    fractPart = modf(t, &intPart);
    while(t<1 || (typeid(t).name()!="i" && fractPart!=0.00)){
    std::cout<<"Time parameter out of range. Enter a new value"<<std::endl;
    std::cin>>t;}
    
    return t;
}
