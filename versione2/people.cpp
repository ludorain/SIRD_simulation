
#include "people.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

People::People() {
  this->S_ = 60000;
  this->I_ = 40;
  this->R_ = 0;
  this->D_ = 0;
}


// Setter class People

//Setter with control
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


//Setter without control
void People::set_People(int s, int i, int r, int d) {
  S_ = s;
  I_ = i;
  R_ = r;
  D_ = d;
}


// getter class People
int People::get_Total() {
  int Tot = S_ + I_ + R_ + D_;
  return Tot;
}

int People::get_Susceptible() { return S_; };
int People::get_Infected() { return I_; };
int People::get_Recovered() { return R_; };
int People::get_Deads() { return D_; };