#ifndef SIRD_HPP
#define SIRD_HPP
#include "people.hpp"
#include "parameters.hpp"

class Sird{

public:
Sird( Parameters parameters_, People people_, int T_);
void simulate();
void print();

private:

//People people;
//Time, total people, probability of infection, probability of recovery, probability
int T;
People people;
Parameters parameters;
int N;
};
#endif