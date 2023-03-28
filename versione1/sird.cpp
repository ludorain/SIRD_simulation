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
  std::cout << "                S " << "I " << "R " << "D " << "T " << std::endl;

  for (int j = 0; j < t; j++) {
    s_ += ((-s * i * b) / ((double)N) - a * S0);
    i_ += ((b * s * i / ((double)N)) - g * i - m * i);
    d_ += m * i;
    // s=-9, i=0, a*so+s
    if (s_ > 0) {
      r_ += (g * i + a * S0);
    } else {
      s_ = 0;
      r_ += g * i + s;  //-(s2-s1)
    }

    std::cout << "Day " << j << ": "
              << static_cast<int>(s_) << "||" << static_cast<int>(i_) << "||"
              << static_cast<int>(r_) << "||" << static_cast<int>(d_) << "||"
              << static_cast<int>(s_ + i_ + r_ + d_) << std::endl;

    s = s_;
    i = i_;
    r = r_;
    d = d_;
  }
}
