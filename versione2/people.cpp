
#include "people.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

People::People() {
  this->S_ = 100;
}


// Setter class People


bool People::set_S(int s){
  if (s >= 0 && s < 60000) {
    S_ = s;
    return true;
  } else {
    return false;
  }
}

bool People::set_I(int i){
  if (i >= 0 && i < 6000) {
    I_ = i;
    return true;
  } else {
    return false;
  }
}

void People::control_SI(){
  if(S_==0 && I_==0){
    throw std::runtime_error{"The simulation won't do anything. Program interrupted. '\n'"};
  }
}

bool People::set_R(int r){
  if (r >= 0 && r < 6000) {
    R_ = r;
    return true;
  } else {
    return false;
  }
}

bool People::set_D(int d){
  if (d >= 0 && d < 6000) {
    D_ = d;
    return true;
  } else {
    return false;
  }
}


// function for random input
void People::set_People(int s, int i, int r, int d) {
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