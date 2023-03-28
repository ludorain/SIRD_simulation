
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
  S = s;
}
void People::setInfected() {
  int i;
  std::cout << "The number of initial Infected [range 0-6000] \n";
  std::cin >> i;
  while (i < 1 || i > 6000 || typeid(i).name() != "i") {
    std::cout << "Infected parameter out of range. Enter a new value \n";
    std::cin >> i;
  }
  I = i;
}
void People::setRecovered() {
  int r;
  std::cout << "The number of initial Recovered [range 0-6000]" << std::endl;
  std::cin >> r;
  while (r < 0 || r > 6000 || typeid(r).name() != "i") {
    std::cout << "Recovered parameter out of range. Enter a new value: \n";
    std::cin >> r;
  }
  R = r;
}
void People::setDeads() {
  double d, fractPart, intPart;
  std::cout << "The number of initial Deads [range 0-6000]" << std::endl;
  std::cin >> d;
  fractPart = modf(d, &intPart);
  while (d < 0 || d > 6000 || (typeid(d).name() != "i" && fractPart != 0.00)) {
    std::cout << "susceptible parameter out of range. Enter a new value"
              << std::endl;
    std::cin >> d;
  }
  D = d;
}

void People::setPeople() {
  setSusceptible();
  setInfected();
  setRecovered();
  setDeads();
}
// setPeople() function overloading

// function for file input
void People::setPeople(double s, double i, double r, double d) {
  double fractPart, intPart;
  // susceptible control
  fractPart = modf(s, &intPart);
  if (s > 0 && s < 6000 && (typeid(s).name() != "i" || fractPart != 0.00)) {
    S = s;
  } else {
    std::cout << "S Parameter out of range, initialized to default value";
  }

  // infected control
  fractPart = modf(i, &intPart);
  if (i > 0 && i < 6000 && (typeid(i).name() != "i" || fractPart != 0.00)) {
    I = i;
  } else {
    std::cout << "I Parameter out of range, initialized to default value";
  }

  // recovered control
  fractPart = modf(r, &intPart);
  if (r > 0 && r < 6000 && (typeid(r).name() != "i" || fractPart != 0.00)) {
    R = r;
  } else {
    std::cout << "R Parameter out of range, initialized to default value";
  }

  // deaths control
  fractPart = modf(d, &intPart);
  if (d > 0 && d < 6000 && (typeid(d).name() != "i" || fractPart != 0.00)) {
    D = d;
  } else {
    std::cout << "D Parameter out of range, initialized to default value";
  }
}

// function for random input
void People::setPeopleR(double s, double i, double r, double d) {
  S = s;
  I = i;
  R = r;
  D = d;
}

// getter class People
int People::getTotal() {
  int Tot = S + I + R + D;
  return Tot;
}
double People::getSusceptible() { return S; };
double People::getInfected() { return I; };
double People::getRecovered() { return R; };
double People::getDeads() { return D; };