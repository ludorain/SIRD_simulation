#ifndef SIRD_HPP
#define SIRD_HPP
#include "people.hpp"
#include "parameters.hpp"

class Pandemic{

public:

Pandemic(People, Parameters, int);
void controlTime(int);
void simulate();

private:

Parameters Par_;
std::vector<People> Pop_;  //vector containing pandemic evolution
int T_;

}


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

