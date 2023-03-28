#ifndef SIRD_HPP
#define SIRD_HPP
#include "people.hpp"
#include "parameters.hpp"

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
};
#endif

