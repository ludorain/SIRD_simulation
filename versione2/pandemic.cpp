#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <cmath>
#include <iostream>
#include <typeinfo>

//Default constructor
Pandemic::Pandemic() {

  People p;
  Parameters ps;

  Population_.push_back(p);
  this->Par_ = ps;
  this->Time_ = 50;
  
}

//Class setter
bool Pandemic::set_Pandemic(People p, Parameters ps, int t){
  
  Population_[0] = p;
  this->Par_ = ps;
  if(t<0){
    return false;
  } else { 
    Time_ = t;
    return true;
  }
}

//Class getter
Parameters Pandemic::getPar()
{
  return Par_;
}

std::vector<People> Pandemic::getPopulation()
{
return Population_;
}

int Pandemic::getTime()
{
  return Time_;
}

//prima prova simulate
void Pandemic::simulate(){

  People now = Population_[0];
  People next = now; //double
  double S0= now.S_;
  double a = Par_.getAlfa();
  double b = Par_.getBeta();
  double g = Par_.getGamma();
  double m = Par_.getMu();

  double t = Time_;
  int const N = now.getTotal();

  double s = now.S_;
  double i = now.I_;
  double r = now.R_;
  double d = now.D_;
  
  for (int j = 0; j < t; j++) {
    
    s += ((-now.S_ * now.I_ * b) / N - a * S0);
    next.S_ = s; //ne abbiamo tolti 28 (38 abbiamo settiamo a 0)

    d += m * now.I_;
    next.D_ = d;
    
  // now 28
    if (next.S_ >  0) {
      r += (g * now.I_ + a * S0);
      next.R_ = r;
      i += ((b * now.S_ * now.I_ )/ N - g * now.I_ - m * now.I_);
      next.I_ = i; //ne  aggiungiamo 38


      //next.R_ += (g * now.I_ + a * S0);
    } else { 

      i += ((b * now.S_ * now.I_ )/ N - g * now.I_ - m * now.I_) + next.S_ ;
      next.I_ = i; //ne  aggiungiamo 38

      r += g * now.I_ + now.S_ ;  //-(s2-s1)
      next.R_ = r;
      next.S_= 0; 
      s=0;
      S0 = 0;
      // next.R_ += g * now.I_ + now.S_;  //-(s2-s1)
    }

    double dado;
    double fract_s, int_s;
    fract_s = std::modf(s, &int_s);
    double fract_i, int_i;
    fract_i = std::modf(i, &int_i);
    double fract_r, int_r;
    fract_r = std::modf(r, &int_r);
    double fract_d, int_d;
    fract_d = std::modf(d, &int_d);
    double sum = fract_s + fract_i + fract_r + fract_d;


    int ghost = N-next.getTotal();
        std::srand(time(NULL));

    for (int i = 0; i<ghost; i++) {
        dado = static_cast<double>(std::rand()) / RAND_MAX;
        if (dado>=0 && dado<fract_s/sum)
        {
            next.S_+=1 ; 
        } else if (dado<(fract_s+ fract_i)/sum) {
            next.I_+=1 ; 
        } else if (dado<(fract_s+ fract_i+fract_r)/sum) { 
            next.R_+=1 ;
        } else { 
          next.D_+=1 ; 
        }
    }

    Population_.push_back(next);
    now=next;

    if(next.S_ == 0 && next.I_ == 0){ 
      std::cout<< "Vediamo cosa mettere qui \n";
      std::cout << "Forse ci va un try catch, ma non so fare \n";
      break;
      
    }    

  }
} 

void Pandemic::print(){
    auto it=Population_.begin();
    int Size=Population_.size();
    
    std::cout << "Time    " << "S       " << "I     " << "R     " << "D   " << "Total \n" ;
    for (int j=0; j<Size; j++){

      std::cout<< "Day " << j << ": " << (*it).S_ << " || " << (*it).I_ << " || " << (*it).R_ << " || " << (*it).D_ << " || " << (*it).S_ + (*it).I_ + (*it).R_ + (*it).D_ <<'\n';
      it++;
    }
  }
  





/*
int const S0 = population_[0].getSusceptible();
  int const N = population_[0].getSusceptible()+population_[0].getInfected()+population_[0].getRecovered()+population_[0].getDeads();
*/





/*
VECCHIO PROTOTIPO DELLA CLASSE
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
}*/



/*
//seconda prova simulate
void Pandemic::simulate(){
  
  //Population_.push_back(Population_[0]);
  double const S0= Population_[0].getSusceptible();
  double a = Par_.getAlfa();
  double b = Par_.getBeta();
  double g = Par_.getGamma();
  double m = Par_.getMu();

  double t = Time_;
  int const N = (Population_[0].getSusceptible()+Population_[0].getInfected()+
                  Population_[0].getRecovered()+Population_[0].getDeads());

  double s = Population_[0].getSusceptible();
  double i = Population_[0].getInfected();
  double r = Population_[0].getRecovered();
  double d = Population_[0].getDeads();
  
  for (int j = 0; j < t; j++) {
    
     s = Population_[j].getSusceptible() + ((Population_[j].getSusceptible()*Population_[j].getInfected())/N-a*S0);
    i = Population_[j].getInfected() + ((b * Population_[j].getSusceptible() * Population_[j].getInfected() )/ N - g * Population_[j].getInfected() - m * Population_[j].getInfected());
    d = Population_[j].getDeads() + m * Population_[j].getInfected();
    

    //s += ((Population_[j].S_*Population_[j].I_)/N-a*S0);
    //i += ((b * Population_[j].S_ * Population_[j].I_ )/ N - g * Population_[j].I_ - m * Population_[j].I_);
    //d += m * Population_[j].I_;
    Population_[j+1].S_= std::round(s);
    Population_[j+1].I_ = std::round(i);
    Population_[j+1].D_ = std::round(d);
    
    /*next.S_ += ((-now.S_ * now.I_ * b) / N - a * S0);
    next.I_ += ((b * now.S_ * now.I_ )/ N - g * now.I_ - m * now.I_);
    next.D_ += m * now.I_;*/
    /*
    if (Population_[j+1].getSusceptible() >= 0) {

      r= Population_[j].getRecovered() + (g * Population_[j].getInfected() + a * S0);
      Population_[j+1].R_ = std::round(r);
      //r += (g * Population_[j].I_ + a * S0);
      //Population_[j+1].R_ = std::round(r);

      //next.R_ += (g * now.I_ + a * S0);
    } else {

      Population_[j+1].S_= 0;
      r = Population_[j].getRecovered() + g * Population_[j].getInfected() + Population_[j].getSusceptible();
      //r += g * Population_[j].I_ + Population_[j].S_;  //-(s2-s1)
      Population_[j+1].R_ = std::round(r);

      // next.R_ += g * now.I_ + now.S_;  //-(s2-s1)
    }

    if(Population_[j].S_ == 0 && Population_[j].I_ == 0){ std::cout<< "Vediamo cosa mettere qui \n";

    }
    /* std::cout<< next.S_ << "||" << next.R_ << "||" << next.I_ << "||" << next.D_ << "||" 
    << next.S_ + next.I_ + next.R_ + next.D_ <<'\n'; */
    /*
    Population_.push_back( Population_[j+1]);

  } 
}

*/

//    std::cout << fract_s << "||" << fract_i << "||" << fract_r << "||" << fract_d << "||"  << sum << '\n' ;