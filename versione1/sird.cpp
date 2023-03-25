#include "sird.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

People::People()
{ }

//setter class People
void People::setSusceptible() 
{
    double s, fractPart, intPart;
    std::cout<<"The number of initial Susceptible" << std::endl;
    std::cin>>s;
    fractPart = modf(s, &intPart);
    while(s<1 || s>6000 || (typeid(s).name()!="i" && fractPart!=0.00)){
    std::cout<<"susceptible parameter out of range. Enter a new value"<<std::endl;
    std::cin>>s;}
    S=s;
    }
void People::setInfected()
{
    double i, fractPart, intPart;
    std::cout<<"The number of initial Infected [range 0-stocazzo]" << std::endl;
    std::cin>>i;
    fractPart = modf(i, &intPart);
    while(i<1 || i>6000 || (typeid(i).name()!="i" && fractPart!=0.00)){
    std::cout<<"Infected parameter out of range. Enter a new value"<<std::endl;
    std::cin>>i;}
    I=i;
    }
void People::setRecovered()
{
    double r, fractPart, intPart;
    std::cout<<"The number of initial Recovered" << std::endl;
    std::cin>>r;
    fractPart = modf(r, &intPart);
    while(r<0 || r>6000 || (typeid(r).name()!="i" && fractPart!=0.00)){
    std::cout<<"Recovered parameter out of range. Enter a new value"<<std::endl;
    std::cin>>r;}
    R=r;
    }
void People::setDeads()
{
    double d, fractPart, intPart;
    std::cout<<"The number of initial Deads" << std::endl;
    std::cin>>d;
    fractPart = modf(d, &intPart);
    while(d<0 || d>6000 || (typeid(d).name()!="i" && fractPart!=0.00)){
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
//setPeople() function overloading 

//function for file input
void People::setPeople(double s, double i, double r, double d){
double fractPart, intPart;
//susceptible control
    fractPart = modf(s, &intPart);
    if(s>0 && s<6000 && (typeid(s).name()!="i" || fractPart!=0.00)){
        S=s;
    } else {std::cout<<"S Parameter out of range, initialized to default value";}
    
//infected control
    fractPart = modf(i, &intPart);    
    if(i>0 && i<6000 && (typeid(i).name()!="i" || fractPart!=0.00)){
        I=i;
    } else {std::cout<<"I Parameter out of range, initialized to default value";}

//recovered control
    fractPart = modf(r, &intPart);
    if(r>0 && r<6000 && (typeid(r).name()!="i" || fractPart!=0.00)){
        R=r;
    } else {std::cout<<"R Parameter out of range, initialized to default value";}

//deaths control    
    fractPart = modf(d, &intPart);
    if(d>0 && d<6000 && (typeid(d).name()!="i" || fractPart!=0.00)){
        D=d;
    } else {std::cout<<"D Parameter out of range, initialized to default value";}
}

//function for random input
void People::setPeopleR(double s, double i, double r, double d){
    S=s;
    I=i;
    R=r;
    D=d;
}

//getter class People
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
    while(g<0 || g>1){
    std::cout<<"out of range. Enter a new value"<<std::endl;
    std::cin>>g;}
    gamma=g;
    }
void Parameters::setMu()
{
    double u;
    std::cout<<"The number of initial Deads" << std::endl;
    std::cin>>u;
    while(u<0 || u>1){
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
//setParameters() function overloading , 
//function for file input
void Parameters::setParameters(double a, double b, double g, double u){
    if(a>0&&a<1){
        alfa=a;
    } else {std::cout<<"Parameter out of range, initialized to default value";}
    if(b>0&&b<1){
        beta=b;
    } else {std::cout<<"Parameter out of range, initilized to default value";}

    if(g>0&&g<0.5){
        gamma=g;
    } else {std::cout<<"Parameter out of range, initialized to default value";}

    if(u>0&&u<.05){
        mu=u;
    } else {std::cout<<"Parameter out of range, initialized to default value";}
}
//function for random input
void Parameters::setParametersR(double a, double b, double g, double u){
    alfa=a;
    beta=b;
    gamma=g;
    mu=u;
}

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
    
    double s,s_= people.getSusceptible();
    double i,i_= people.getInfected();
    double r,r_= people.getRecovered();
    double d,d_= people.getDeads();

    //double s_= people.getSusceptible();
    //double i_= people.getInfected();
    //double r_= people.getRecovered();
    //double d_= people.getDeads();


    double a= parameters.getAlfa();
    double b= parameters.getBeta();
    double g= parameters.getGamma();
    double m= parameters.getMu();

    double t=T;

    for(int j=0; j<t; j++){
        
        s_+=((-s*i*b)/((double)N) - a*S0);
        i_+=((b*s*i/((double)N))-g*i-m*i);        
        d_+=m*i;
        // s=-9, i=0, a*so+s 
        if (s_>0) {
            r_+=(g*i+a*S0);
        } else {
            s_=0;
            r_+=g*i +s; //-(s2-s1)
        }
        
           
        std::cout<< static_cast<int>(s_) << "||" << static_cast<int>(i_) << "||" << static_cast<int>(r_) << "||" << static_cast<int>(d_) << "||" << static_cast<int>(s_+i_+r_+d_)<< std::endl;

        s=s_;
        i=i_;
        r=r_;
        d=d_;
    }
}








