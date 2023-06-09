#include "parameters.hpp"
#include <iostream>
#
// costruttore
Parameters::Parameters() {}

// setter della classe Parameters

// Setter per lo standard input
void Parameters::setAlfa() {
  char f;
  std::cout << "Do you want vaccination? [y/n]";
  std::cin >> f;
  while (f != 'y' && f != 'n') {
    std::cout << "Invalid char, try again.";
    std::cin >> f;
  }

  if (f == 'y') {
    double a;
    std::cout << "Rate vaccination [range 0.001-0.01]" << std::endl;
    std::cin >> a;
    while (a <= 0.001 || a >= 0.01) {
      std::cout << "out of range. Enter a new value" << std::endl;
      std::cin >> a;
    }
    alfa = a;
  } else {
    alfa = 0;
  }
}

void Parameters::setBeta() {
  double b;
  std::cout << "Infection probability [range 0-1]" << std::endl;
  std::cin >> b;
  while (b < 0 || b > 1) {
    std::cout << " out of range. Enter a new value" << std::endl;
    std::cin >> b;
  }
  beta = b;
}

void Parameters::setGamma() {
  double g;
  std::cout << "Recovery probability [range 0-0.5]" << std::endl;
  std::cin >> g;
  while (g < 0 || g > 0.5) {
    std::cout << "out of range. Enter a new value" << std::endl;
    std::cin >> g;
  }
  gamma = g;
}
void Parameters::setMu() {
  double u;
  std::cout << "Death probability [range 0-0.5]" << std::endl;
  std::cin >> u;
  while (u < 0 || u > 0.5) {
    std::cout << "susceptible parameter out of range. Enter a new value"
              << std::endl;
    std::cin >> u;
  }
  mu = u;
}

void Parameters::setParameters() {
  setAlfa();
  setBeta();
  setGamma();
  setMu();
}
// setParameters() function overloading ,
// function for file input
void Parameters::setParameters(double a, double b, double g, double u) {
  if (a >= 0 && a <= 0.01) {
    alfa = a;
  } else {
    std::cout << "Parameter out of range, initialized to default value a";
  }
  if (b > 0 && b < 1) {
    beta = b;
  } else {
    std::cout << "Parameter out of range, initilized to default value b";
  }

  if (g > 0 && g < 0.5) {
    gamma = g;
  } else {
    std::cout << "Parameter out of range, initialized to default value g";
  }

  if (u > 0 && u < 0.5) {
    mu = u;
  } else {
    std::cout << "Parameter out of range, initialized to default value u";
  }
}
// function for random input
void Parameters::setParametersR(double a, double b, double g, double u) {
  alfa = a;
  beta = b;
  gamma = g;
  mu = u;
}

// getter della classe Parameters
double Parameters::getAlfa() { return alfa; };
double Parameters::getBeta() { return beta; };
double Parameters::getGamma() { return gamma; };
double Parameters::getMu() { return mu; };