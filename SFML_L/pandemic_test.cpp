#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "parameters.hpp"
#include "pandemic.hpp"

#include <vector>
#include <random> 


TEST_CASE("Setters class Parameters.") {

  Parameters ps;
  Parameters ps1;
  
  SUBCASE("Calling setters with correct values & checking getters.")
 
  CHECK(ps.set_Beta(0.1) == true);
  CHECK(ps.set_Beta(0.998) == true);
  CHECK(ps.set_Beta(0.7) == true);
  
  CHECK(ps.set_Gamma(0.1) == true);
  CHECK(ps.set_Gamma(0.3) == true);
  CHECK(ps.set_Gamma(0.5) == true);

  CHECK(ps.set_Mu(0.1) == true);
  CHECK(ps.set_Mu(0.3) == true);
  CHECK(ps.set_Mu(0.5) == true);

  CHECK(ps.get_Alfa() == 0.001);
  CHECK(ps.get_Beta() == 0.7);
  CHECK(ps.get_Gamma() == 0.5);
  CHECK(ps.get_Mu() == 0.5);
  

  SUBCASE("Checking default constructor.")
  
  CHECK(ps1.get_Alfa() == 0.001);
  CHECK(ps1.get_Beta() == 0.85);
  CHECK(ps1.get_Gamma() == 0.2);
  CHECK(ps1.get_Mu() == 0.2);


  SUBCASE("Calling setters with wrong values.")
 
  CHECK(ps.set_Beta(0) == false);
  CHECK(ps.set_Beta(0.999) == false);
  CHECK(ps.set_Beta(-0.2) == false);

  CHECK(ps.set_Gamma(0) == false);
  CHECK(ps.set_Gamma(-0.2) == false);
  CHECK(ps.set_Gamma(1) == false);

  CHECK(ps.set_Mu(0) == false);
  CHECK(ps.set_Mu(-0.2) == false);
  CHECK(ps.set_Mu(1) == false);

}



/*
TEST_CASE( "Testing state cell") {

  Parameters ps;
  Pandemic evolving;

  SUBCASE ("Reading and changing person's state");

  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{10, 50};
  int l = dist(eng);

  evolving.set_Side(l); 

  
  CHECK(evolving.Reading_cell(1,1) == Person::Susceptible); 
  evolving.Writing_cell(1,1) = Infected;
  CHECK(evolving.Reading_cell(1,1) == Person::Infected);

  evolving.Writing_cell(1,3) = Person::Recovered;
  CHECK(evolving.Reading_cell(1,3) == Person::Recovered); 

  evolving.Writing_cell(5,1) = Person::Dead;
  CHECK(evolving.Reading_cell(5,1) == Person::Dead);
  

  SUBCASE("Testing evolution");

  l = 11;
  evolving.Writing_cell(4,6) = Person::Infected;
  evolving.Writing_cell(3,5) = Person::Recovered;
  evolving.Writing_cell(5,3) = Person::Dead;


  evolving = Pandemic::evolve(evolving, ps);

  CHECK(evolving.Reading_cell(4,6) != Person::Susceptible);

  CHECK(evolving.Reading_cell(3,5) != Person::Susceptible);
  CHECK(evolving.Reading_cell(3,5) != Person::Infected);
  CHECK(evolving.Reading_cell(3,5) != Person::Dead);

  CHECK(evolving.Reading_cell(5,3) != Person::Susceptible);
  CHECK(evolving.Reading_cell(5,3) != Person::Recovered);
  CHECK(evolving.Reading_cell(5,3) != Person::Infected);

} */

/*

TEST_CASE ("Testing initial situation")
{ // testing the start member function

SUBCASE("Setting the initial grid by calling the member function start()");
  
  // Creating a pandemic object
  int l = 50;
  Pandemic first;
  first.set_Side(l);
  int inf = 90;
  //calling start()
  first = Pandemic::start(first, inf);
  
  int check = 0;

    for (int r = 0 ; r < l ; r++ ){   
   
       for (int c = 0 ; c < l ; c++){

        if (first.Reading_cell(r,c) == Person::Infected) check++;
       }
    }
  
  CHECK(check == inf);

  /*int lato = 51;
  int n = 55;
  life::Pandemic::check_number(n,lato);
  CHECK(lato == 50 && n == 52);*/
  
//} 

/*
TEST_CASE("Testing the counting of the infected neighbours")
{
  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{7, 100 - 1};
  int l = dist(eng);

  Pandemic neighbours(l);
  Probability pneighbours  = {2,35,8,3};  
  Count cneighbours;
  neighbours.Writing_cell(4,6) = Person::Infected;
  neighbours.Writing_cell(2,5) = Person::Susceptible;
  neighbours.Writing_cell(3,2) = Person::Infected;
  neighbours.Writing_cell(2,3) = Person::Susceptible;
  //evolving states 5 times
  for (int i = 0; i < 5;i++ ){
    Pandemic::evolve(neighbours,pneighbours,cneighbours);
  }
  CHECK(neighbours.Reading_cell(4,6)<=8);
  CHECK(neighbours.Reading_cell(2,5)<=8);
  CHECK(neighbours.Reading_cell(3,2)<=8);
  CHECK(neighbours.Reading_cell(2,3)<=8);
}



*/
