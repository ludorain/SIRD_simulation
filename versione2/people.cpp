
#include "people.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

People::People() {}


// Setter class People

void People::setPeople(int s, int i, int r, int d) {
  // susceptible control
  if (s > 0 && s < 6000 && typeid(s).name() != "i" ) {
    S_ = s;
  } else {
    std::cout << "S Parameter out of range, initialized to default value. '\n'";
  }

  // infected control
  if (i > 0 && i < 6000 && typeid(i).name() != "i") {
    I_ = i;
  } else {
    std::cout << "I Parameter out of range, initialized to default value. '\n'";
  }

  // recovered control
 
  if (r > 0 && r < 6000 && typeid(r).name() != "i") {
    R_ = r;
  } else {
    std::cout << "R Parameter out of range, initialized to default value. '\n'";
  }

  // deaths control

  if (d > 0 && d < 6000 && typeid(d).name() != "i") {
    D_ = d;
  } else {
    std::cout << "D Parameter out of range, initialized to default value. '\n' ";
  }
}

// function for random input
void People::setPeopleR(int s, int i, int r, int d) {
  S_ = s;
  I_ = i;
  R_ = r;
  D_ = d;
}

// getter class People
int People::getTotal() {
  int Tot = S_ + I_ + R_ + D_;
  return Tot;
}
int People::getSusceptible() { return S_; };
int People::getInfected() { return I_; };
int People::getRecovered() { return R_; };
int People::getDeads() { return D_; };