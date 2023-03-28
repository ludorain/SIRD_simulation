#ifndef SIRD_HPP
#define SIRD_HPP

class People{
   
public:
//costruttore default
People();
//funzioni set
void setSusceptible();
void setInfected();
void setRecovered();
void setDeads();
void setPeople();
void setPeople(double, double, double, double);
void setPeopleR(double,double,double,double);

//funzioni get
int getTotal();
double getSusceptible();
double getInfected();
double getRecovered();
double getDeads();

private:

    double S;
    double I;
    double R;
    double D;
};

class Parameters{ 

public:
//costruttore default
Parameters();

//funzioni set
void setAlfa();
void setBeta();
void setGamma();
void setMu();

void setParameters();
void setParameters(double, double, double, double);
void setParametersR(double, double, double, double);

//funzioni get
double getAlfa();
double getBeta();
double getGamma();
double getMu();

private:

    double alfa;
    double beta;
    double gamma;
    double mu;
};

class sird{

public:
sird(int T_, People people_, Parameters parameters_, int N_);
void simulate();

private:

//People people;
//Time, total people, probability of infection, probability of recovery, probability
int T;
People people;
Parameters parameters;
int N;
};
#endif

