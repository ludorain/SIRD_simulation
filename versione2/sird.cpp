#include "people.hpp"
#include "parameters.hpp"
#include "sird.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

// classe complessiva, si occupa della simulazione
Sird::Sird(Parameters parameters, People people, int time )
    : parameters_{parameters},
    time_{time}
{ population_.push_back(people);}

void Sird::simulate() {
  People now = population_[0];
  People next = population_[0];
  double const S0 = now.S;
  double a = parameters_.getAlfa();
  double b = parameters_.getBeta();
  double g = parameters_.getGamma();
  double m = parameters_.getMu();
  
  double t = time_;
  int N=(now.S+now.I+now.R+now.D);

  

  


  for (int j = 0; j < t; j++) {
    next.S += ((-now.S * now.I * b) / N - a * S0);
    next.I += ((b * now.S * now.I )/ N - g * now.I - m * now.I);
    next.D+= m * now.I;
 
    if (next.S > 0) {
     next.R += (g * now.I + a * S0);
    } else {
      next.S= 0;
      next.R+= g * now.I + now.S;  //-(s2-s1)
    }

    population_.push_back(next);
    now=next;

  } 
  }

  void Sird::print(){
    
    auto it=population_.begin();
    for (int j=0; j<population_.size(); j++){
      
      /*std::cout << "Day " << j << ": "
              << static_cast<int>((*it).S )<< "||" << static_cast<int>((*it).I) << "||"
              << static_cast<int>((*it).R) << "||" << static_cast<int>((*it).D) << "||"
              << static_cast<int>((*it).S + (*it).I + (*it).R + (*it).D) << '\n';*/

      std::cout<< (*it).S << "||" << (*it).R << "||" << (*it).I << "||" << (*it).D << "||" << (*it).S + (*it).I + (*it).R + (*it).D <<'\n';
      it++;
    }
}
