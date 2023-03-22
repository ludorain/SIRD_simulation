#include "sird.hpp"
#include <cmath>
#include <iostream>


People::People()
{ }

void People::setSusceptible() 
{
    double s;
    std::cout<<"The number of initial Susceptible" << std::endl;
    std::cin>>s;
    while(s<0 || s>6000){
    std::cout<<"susceptible parameter out of range. Enter a new value"<<std::endl;
    std::cin>>s;}
    S=s;
    }
void People::setInfected()
{
    double i;
    std::cout<<"The number of initial Infected [range 0-stocazzo]" << std::endl;
    std::cin>>i;
    while(i<0 || i>6000){
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
    } else {std::cout<<"Parameter out of range"}
    if(s>0 && s<6000){
        R=r;
    } else {std::cout<<"Parameter out of range"}

    if(s>0 && s<6000){
        I=i;
    } else {std::cout<<"Parameter out of range"}

    if(s>0 && s<6000){
        D=d;
    } else {std::cout<<"Parameter out of range"}
}

/*void People::setPeopleR(double s, double i, double r, double d){
    S=s;
    I=i;
    R=r;
    D=d;
}*/

int People::getTotal(){
    int Tot=S+I+R+D;
    return Tot;
}

//costruttore default solo per prove
Parameters::Parameters(double a, double b, double g, double m) {};

//classe complessiva, si occupa della simulazione
sird::sird(int T_, People &people_, Parameters &parameters_, int N_):
    T(T_), people(people_), parameters(parameters_), N(N_)     
{  //controllo del parametro tempo
}

sird::simulate(){
    //(funzionerebbe implementando dei metodi get con referenza e inserendo quelli nell'algoritmo
    //non so se è il modo più intelligente di farlo)
}
/*
void sird::simulate(){
    double const S0=People::S;

for(int i=0; i<T; i++){
    People::S+=((-People::S*People::I*Parameters::beta)/N - Parameters::alfa*S0);
    People::I+=((Parameters::beta*People::S*People::I/N)-Parameters::gamma*People::I-Parameters::mu*People::I);
    People::R+=(Parameters::gamma*People::I+Parameters::alfa*S0);
    People::D+=Parameters::mu*People::I;

std::cout<< People::S << "||" << People::I << "||" << People::R << "||" << People::D << std::endl;

}
}*/
