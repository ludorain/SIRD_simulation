#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP
#include "people.hpp"
#include "parameters.hpp"
#include <vector>

class Pandemic {

    public:

        //default constructor
        Pandemic();

        //Class setter
        bool set_Pandemic(People, Parameters, int);

        //Function for simulation
        void simulate();

        //Standard output function
        void print();

        //Getter
        Parameters getPar();
        std::vector<People> getPopulation();
        int getTime();

    private:

        Parameters Par_;
        std::vector<People> Population_;  //vector containing pandemic evolution
        int Time_;

};


/*
VECCHIA CLASSE
class Sird{

public:
Sird(int T_, People people_, Parameters parameters_, int N_);
void simulate();

private:

//People people;
//Time, total people, probability of infection, probability of recovery, probability
int T;
People people;
Parameters parameters;
int N;
};*/
#endif

