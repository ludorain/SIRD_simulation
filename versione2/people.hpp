#ifndef PEOPLE_HPP
#define PEOPLE_HPP
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

#endif