#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

Pandemic::Pandemic(Parameters ps, People p, int t) {
  this->Par_ = ps;
  this->Time_ = t;
  Population_.push_back(p);
}


//prima prova simulate
void Pandemic::simulate(){
  People now = Population_[0];
  People next = Population_[0];
  int const S0= now.S_;
  double a = Par_.getAlfa();
  double b = Par_.getBeta();
  double g = Par_.getGamma();
  double m = Par_.getMu();

  double t = Time_;
  int const N = (now.S_+now.I_+now.R_+now.D_);

  for (int j = 0; j < t; j++) {
    next.S_ += ((-now.S_ * now.I_ * b) / N - a * S0);
    next.I_ += ((b * now.S_ * now.I_ )/ N - g * now.I_ - m * now.I_);
    next.D_ += m * now.I_;
 
    if (next.S_ > 0) {
     next.R_ += (g * now.I_ + a * S0);
    } else {
      next.S_= 0;
      next.R_ += g * now.I_ + now.S_;  //-(s2-s1)
    }

    /* std::cout<< next.S_ << "||" << next.R_ << "||" << next.I_ << "||" << next.D_ << "||" 
    << next.S_ + next.I_ + next.R_ + next.D_ <<'\n'; */
    
    Population_.push_back(next);
    now=next;

  }
}

void Pandemic::print(){
    auto it=Population_.begin();
    int Size=Population_.size();
    for (long int j=0; j<Size; j++){
      
      /*std::cout << "Day " << j << ": "
              << static_cast<int>((*it).S )<< "||" << static_cast<int>((*it).I) << "||"
              << static_cast<int>((*it).R) << "||" << static_cast<int>((*it).D) << "||"
              << static_cast<int>((*it).S + (*it).I + (*it).R + (*it).D) << '\n';*/

      std::cout<< (*it).S_ << "||" << (*it).I_ << "||" << (*it).R_ << "||" << (*it).D_ << "||" << (*it).S_ + (*it).I_ + (*it).R_ + (*it).D_ <<'\n';
      it++;
    }
  }
  





/*
int const S0 = population_[0].getSusceptible();
  int const N = population_[0].getSusceptible()+population_[0].getInfected()+population_[0].getRecovered()+population_[0].getDeads();
*/










/*
VECCHIO PROTOTIPO DELLA CLASSE
// classe complessiva, si occupa della simulazione
Sird::Sird(int T_, People people_, Parameters parameters_, int N_)
    : T(T_),
      people(people_),
      parameters(parameters_),
      N(N_) {  // controllo del parametro tempo
}

void Sird::simulate() {
  double const S0 = people.getSusceptible();

  double s, s_ = people.getSusceptible();
  double i, i_ = people.getInfected();
  double r, r_ = people.getRecovered();
  double d, d_ = people.getDeads();

  // double s_= people.getSusceptible();
  // double i_= people.getInfected();
  // double r_= people.getRecovered();
  // double d_= people.getDeads();

  double a = parameters.getAlfa();
  double b = parameters.getBeta();
  double g = parameters.getGamma();
  double m = parameters.getMu();

  double t = T;
  std::cout << "                S " << "I " << "R " << "D " << "T \n";

  for (int j = 0; j < t; j++) {
    s_ += ((-s * i * b) / N - a * S0);
    i_ += ((b * s * i )/ N - g * i - m * i);
    d_ += m * i;
 
    if (s_ > 0) {
      r_ += (g * i + a * S0);
    } else {
      s_ = 0;
      r_ += g * i + s;  //-(s2-s1)
    }

    std::cout << "Day " << j << ": "
              << static_cast<int>(s_) << "||" << static_cast<int>(i_) << "||"
              << static_cast<int>(r_) << "||" << static_cast<int>(d_) << "||"
              << static_cast<int>(s_ + i_ + r_ + d_) << '\n';

    s = s_;
    i = i_;
    r = r_;
    d = d_;
  }
}*/
