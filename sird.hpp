#ifndef SIRD_CPP
#define SIRD_CPP

namespace model {

struct People{
    double S{};
    double I{};
    double R{};
    double D{};
}

class sird{

People people;
//Time, total people, probability of infection, probability of recovery, probability
int T;
double N;
double beta;
double gamma;
double alfa;
double mu;

public:
sird(double T_, double alfa_, double beta_, double gamma_, double mu_, People people_ );
//getter parametri
double alfa();
double beta();
double alfa();
double mu();
int T();
int people(); //verificare


//mancano  i metodi






}

}
#endif