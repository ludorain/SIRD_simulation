#include "sird.hpp"
#include <cmath>
#include <iostream>


People::People()
{ }

//setter della classe People
void People::setSusceptible() 
{
    double s;
    std::cout<<"The number of initial Susceptible" << std::endl;
    std::cin>>s;
    while(s<1 || s>6000){
    std::cout<<"susceptible parameter out of range. Enter a new value"<<std::endl;
    std::cin>>s;}
    People::S=s;
    }
void People::setInfected()
{
    double i;
    std::cout<<"The number of initial Infected [range 0-stocazzo]" << std::endl;
    std::cin>>i;
    while(i<1 || i>6000){
    std::cout<<"Infected parameter out of range. Enter a new value"<<std::endl;
    std::cin>>i;}
    I=i;
    }
void People::setRecovered()
{
    double r;
    std::cout<<"The number of initial Recovered" << std::endl;
    std::cin>>r;
    while(r<0 || r>6000){
    std::cout<<"Recovered parameter out of range. Enter a new value"<<std::endl;
    std::cin>>r;}
    R=r;
    }
void People::setDeads()
{
    double d;
    std::cout<<"The number of initial Deads" << std::endl;
    std::cin>>d;
    while(d<0 || d>6000){
    std::cout<<"susceptible parameter out of range. Enter a new value"<<std::endl;
    std::cin>>d;}
    D=d;
    }
void People::setPeople(){
    setSusceptible();
    setInfected();
    setRecovered();
    setDeads();
}
//function overloading per la funzione set People, 
//serve per la generazione random e per la presa dati da file
void People::setPeople(double s, double i, double r, double d){
    if(s>0 && s<6000){
        S=s;
    } else {std::cout<<"Parameter out of range";}
    if(s>0 && s<6000){
        R=r;
    } else {std::cout<<"Parameter out of range";}

    if(s>0 && s<6000){
        I=i;
    } else {std::cout<<"Parameter out of range";}

    if(s>0 && s<6000){
        D=d;
    } else {std::cout<<"Parameter out of range";}
}

/*void People::setPeopleR(double s, double i, double r, double d){
    S=s;
    I=i;
    R=r;
    D=d;
}*/

//getter della classe People
int People::getTotal(){
    int Tot=S+I+R+D;
    return Tot;
}
double People::getSusceptible(){
    return S;
};
double People::getInfected(){
    return I;
};
double People::getRecovered(){
    return R;
};
double People::getDeads(){
    return D;
};

//costruttore default solo per prove
Parameters::Parameters(double a, double b, double g, double m) {};

//setter della classe Parameters

//getter della classe Parameters
double Parameters::getAlfa(){
    return alfa;
};
double Parameters::getBeta(){
    return beta;
};
double Parameters::getGamma(){
    return gamma;
};
double Parameters::getMu(){
    return mu;
};



//classe complessiva, si occupa della simulazione
sird::sird(int T_, People people_, Parameters parameters_, int N_):
    T(T_), people(people_), parameters(parameters_), N(N_)     
{  //controllo del parametro tempo
}


void sird::simulate(){
    double const S0=people.getSusceptible();
    
    double s= people.getSusceptible();
    double i= people.getInfected();
    double r= people.getRecovered();
    double d= people.getDeads();

    double a= parameters.getAlfa();
    double b= parameters.getBeta();
    double g= parameters.getGamma();
    double m= parameters.getMu();

    double t=T;
    std::cout << N;

    for(int j=0; j<t; j++){
        std::cout << s*i*b << '\n';
        std::cout << a << '\n';

        s+=((-s*i*b)/((double)N) - a*S0);
        i+=((b*s*i/((double)N))-g*i-m*i);
        r+=(g*i+a*S0);
        d+=m*i;


        std::cout<< s << "||" << i << "||" << r << "||" << d << std::endl;

    }
}


