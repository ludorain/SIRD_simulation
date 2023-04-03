#include "parameters.hpp"
#include <iostream>
#
// costruttore
Parameters::Parameters() {}

// setter della classe Parameters

// Setter per lo standard input
bool Parameters::set_Alfa(double a) {
    
   if (a >= 0.001 && a <= 0.01) {
      Alfa_ = a;
      return true;
    } else {return false;}   
}

void Parameters::set_Zero(){
  Alfa_=0;
}

bool Parameters::set_Beta(double b) {
  if(b>0&&b<1){
    Beta_ = b;
    return true;
  } else {return false;}
  }

bool Parameters::set_Gamma(double g) {
  
  if (g > 0 && g < 0.5) {
    Gamma_=g;
    return true;
  } else {return false;}
}

bool Parameters::set_Mu(double m) {
  if (m > 0 && m < 0.5) {
    Mu_=m;
    return true;
  } else {return false;}
}  
 
 void Parameters::control_R0(){
  //migliorare l'
  if(Gamma_==0.5 && Mu_==0.5){
    throw std::runtime_error("Unrealistic situation, program terminated. \n");
  } 

  if (Gamma_+Mu_>Beta_){
    throw std::runtime_error("The epidemy won't start, program terminated. \n");
  }
 }

// function for random input
void Parameters::set_Parameters(double a, double b, double g, double u) {
  Alfa_ = a;
  Beta_ = b;
  Gamma_ = g;
  Mu_ = u;
}

// getter della classe Parameters
double Parameters::getAlfa() { return Alfa_; };
double Parameters::getBeta() { return Beta_; };
double Parameters::getGamma() { return Gamma_; };
double Parameters::getMu() { return Mu_; };