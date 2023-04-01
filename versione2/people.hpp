#ifndef PEOPLE_HPP
#define PEOPLE_HPP
class People{
   
public:
//costruttore default
People();
//funzioni set
bool set_S(int);
bool set_I(int);
void control_SI();
bool set_R(int);
bool set_D(int);


void setPeople();
void setPeople(int, int, int, int);
void setPeopleR(int,int,int,int);

//funzioni get
int getTotal();
int getSusceptible();
int getInfected();
int getRecovered();
int getDeads();

private:

    int S_;
    int I_;
    int R_;
    int D_;
    };

#endif