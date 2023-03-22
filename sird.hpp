#ifndef SIRD_CPP
#define SIRD_CPP

/*IDEA PROGRAMMA
struct People
struct Parametri

costruttore con dati default

setter parametri con verifica range

getter parametri

funzione simulate (può essere messa nel main, che vantaggi?)
*/


class People{
friend class sird;    
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
friend class sird;
//costruttore non attuale, è solo per fare delle prove
public:
Parameters(double=0.0001, double=0.7, double=0.3, double=0.1);

//getter dei parametri

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

//mancano  i metodi

private:

//People people;
//Time, total people, probability of infection, probability of recovery, probability
int T;
People people;
Parameters parameters;
int N;
};
#endif
