
#include "people.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

People::People() {}

// setter class People
void People::setSusceptible() {
  int s;
  std::cout << "The number of initial Susceptible [range 0-60000]" << std::endl;
  std::cin >> s;
  while (s < 1 || s > 60000 || typeid(s).name() != "i" ) {
    std::cout << "susceptible parameter out of range. Enter a new value: \n";
    std::cin >> s;
  }
  S_ = s;
}
void People::setInfected() {
  int i;
  std::cout << "The number of initial Infected [range 0-6000] \n";
  std::cin >> i;
  while (i < 1 || i > 6000 || typeid(i).name() != "i") {
    std::cout << "Infected parameter out of range. Enter a new value \n";
    std::cin >> i;
  }
  I_ = i;
}
void People::setRecovered() {
  int r;
  std::cout << "The number of initial Recovered [range 0-6000]" << std::endl;
  std::cin >> r;
  while (r < 0 || r > 6000 || typeid(r).name() != "i") {
    std::cout << "Recovered parameter out of range. Enter a new value: \n";
    std::cin >> r;
  }
  R_ = r;
}
void People::setDeads() {
  int d;
  std::cout << "The number of initial Deads [range 0-6000]" << std::endl;
  std::cin >> d;
  while (d < 0 || d > 6000 || typeid(d).name() != "i") {
    std::cout << "susceptible parameter out of range. Enter a new value"
              << std::endl;
    std::cin >> d;
  }
  D_ = d;
}

void People::setPeople() {
  setSusceptible();
  setInfected();
  setRecovered();
  setDeads();
}
// setPeople() function overloading

// function for file input
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