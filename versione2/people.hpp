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