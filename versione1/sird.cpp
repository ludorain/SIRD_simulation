#include "people.hpp"
#include "parameters.hpp"
#include "sird.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

// classe complessiva, si occupa della simulazione
Sird::Sird(int T_, People people_, Parameters parameters_, int N_)
    : T(T_),
      people(people_),
      parameters(parameters_),
      N(N_) {  // controllo del parametro tempo
}

void Sird::simulate() {
  double const S0 = people.getSusceptible();

  double s = people.getSusceptible();
  double i = people.getInfected();
  double r = people.getRecovered();
  double d = people.getDeads();

  double s_= s;
  double i_= i;
  double r_= r;
  double d_= d;

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
}
