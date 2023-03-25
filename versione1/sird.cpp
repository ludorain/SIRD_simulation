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
    S=s;
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
//questa funzione serve nel caso non voglimo fare doppiio controllo sui parametripresi da random
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

//costruttore
Parameters::Parameters()
{ }

//setter della classe Parameters
void Parameters::setAlfa() 
{
    double a;
    std::cout<<" percentuale vaccinati" << std::endl;
    std::cin>>a;
    while(a<0 || a>1){
    std::cout<<"out of range. Enter a new value"<<std::endl;
    std::cin>>a;}
    alfa=a;
    }

void Parameters::setBeta()
{
    double b;
    std::cout<<"probabilità infez" << std::endl;
    std::cin>>b;
    while(b<0 || b>1){
    std::cout<<" out of range. Enter a new value"<<std::endl;
    std::cin>>b;}
    beta=b;
    }
void Parameters::setGamma()
{
    double g;
    std::cout<<"prob guarire??? non sono sicura" << std::endl;
    std::cin>>g;
    while(g<0||g>1){
    std::cout<<"out of range. Enter a new value"<<std::endl;
    std::cin>>g;}
    gamma=g;
    }
void Parameters::setMu()
{
    double u;
    std::cout<<"The number of initial Deads" << std::endl;
    std::cin>>u;
    while(u>1 || u<0){
    std::cout<<"susceptible parameter out of range. Enter a new value"<<std::endl;
    std::cin>>u;}
    mu=u;
    }

void Parameters::setParameters(){
    setAlfa();
    setBeta();
    setGamma();
    setMu();
}
//function overloading per la funzione set People, 
//serve per la presa dati da file e per la generazione random (x la quale non servirebbe il controllo)
void Parameters::setParameters(double a, double b, double g, double u){
    if(a>0&&a<1){
        alfa=a;
    } else {std::cout<<"Parameter out of range";}
    if(b>0&&b<1){
        beta=b;
    } else {std::cout<<"Parameter out of range";}

    if(g>0&&g<1){
        gamma=g;
    } else {std::cout<<"Parameter out of range";}

    if(u>0&&u<1){
        mu=u;
    } else {std::cout<<"Parameter out of range";}
}
//questa funzione serve nel caso non voglimo fare doppiio controllo sui parametripresi da random
/*void Parammeters::setParameters(double s, double i, double r, double d){
    alfa=a;
    beta=b;
    gamma=g;
    mu=u;
}*/

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

    for(int j=0; j<t; j++){
        
        
        i+=((b*s*i/((double)N))-g*i-m*i);
        s+=((-s*i*b)/((double)N) - a*S0);
        d+=m*i;
        // s=-9, i=0, a*so+s 
        if (s>0) {
            r+=(g*i+a*S0);
        } else {
            s=0;
            r+=g*i//-(s2-s1);
        }

        
        if (i==0) {
            std::cout << "fuck" << std::endl;
            //break;
        }
        
        std::cout<< static_cast<int>(s) << "||" << static_cast<int>(i) << "||" << static_cast<int>(r) << "||" << static_cast<int>(d) << std::endl;

    }
}




