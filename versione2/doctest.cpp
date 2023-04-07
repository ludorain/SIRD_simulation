#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"
#include <vector>

TEST_CASE("Setters class Parameters."){

  Parameters ps;
  
  SUBCASE("Calling setters with correct values & checking getters.")
 
  CHECK(ps.set_Alfa(0.001)== true); 
  CHECK(ps.set_Alfa(0.01) == true);
  CHECK(ps.set_Alfa(0.002) == true);

  CHECK(ps.set_Beta(0.4) == true);
  CHECK(ps.set_Beta(0.5) == true);
  CHECK(ps.set_Beta(0.7) == true);
  
  CHECK(ps.set_Gamma(0.1) == true);
  CHECK(ps.set_Gamma(0.3) == true);
  CHECK(ps.set_Gamma(0.5) == true);

  CHECK(ps.set_Mu(0.1) == true);
  CHECK(ps.set_Mu(0.3) == true);
  CHECK(ps.set_Mu(0.5) == true);


  CHECK(ps.getAlfa() == 0.002);
  CHECK(ps.getBeta() == 0.7);
  CHECK(ps.getGamma() == 0.5);
  CHECK(ps.getMu() == 0.5);

  ps.set_Parameters(0.003,0.3,0.4,0.6);
  CHECK(ps.getAlfa() == 0.003);
  CHECK(ps.getBeta() == 0.3);
  CHECK(ps.getGamma() == 0.4);
  CHECK(ps.getMu() == 0.6);



  SUBCASE("Calling setter with wrong values")
 
  CHECK(ps.set_Alfa(1) == false);
  CHECK(ps.set_Alfa(-3) == false);
  CHECK(ps.set_Alfa(0.02) == false);

  CHECK(ps.set_Beta(0) == false);
  CHECK(ps.set_Beta(1) == false);
  CHECK(ps.set_Beta(-0.2) == false);

  CHECK(ps.set_Gamma(0) == false);
  CHECK(ps.set_Gamma(-0.2) == false);
  CHECK(ps.set_Gamma(1) == false);

  CHECK(ps.set_Mu(0) == false);
  CHECK(ps.set_Mu(-0.2) == false);
  CHECK(ps.set_Mu(1) == false);

}


TEST_CASE("Setters & getters class People."){

  People p;
  
  SUBCASE("Calling setters with correct values & checking getters.")
  
 
  CHECK(p.set_S(0)== true); 
  CHECK(p.set_S(59999) == true);
  CHECK(p.set_S(450) == true);

  CHECK(p.set_I(0) == true);
  CHECK(p.set_I(5999) == true);
  CHECK(p.set_I(120) == true);
  
  CHECK(p.set_R(0) == true);
  CHECK(p.set_R(5999) == true);
  CHECK(p.set_R(1) == true);

  CHECK(p.set_D(0) == true);
  CHECK(p.set_D(5999) == true);
  CHECK(p.set_D(453) == true);


  CHECK(p.getSusceptible()==450);
  CHECK(p.getInfected()==120);
  CHECK(p.getRecovered()==1);
  CHECK(p.getDeads()==453);

  CHECK(p.getTotal()==1024);

  p.set_People(1,2,3,4);
  CHECK(p.getSusceptible()==1);
  CHECK(p.getInfected()==2);
  CHECK(p.getRecovered()==3);
  CHECK(p.getDeads()==4);



  SUBCASE("Calling setter with wrong values")
 
  CHECK(p.set_S(-1)== false); 
  CHECK(p.set_S(60000) == false);
  CHECK(p.set_S(-4) == false);

  CHECK(p.set_I(-1) == false);
  CHECK(p.set_I(6000) == false);
  CHECK(p.set_I(6511) == false);

  CHECK(p.set_R(-1) == false);
  CHECK(p.set_R(6000) == false);
  CHECK(p.set_R(7500) == false);

  CHECK(p.set_D(-1) == false);
  CHECK(p.set_D(6000) == false);
  CHECK(p.set_D(10000) == false);

}


TEST_CASE("Testing the pandemic default constructor.") {

  People p;
  Parameters ps;
  Pandemic oggetto;

  CHECK(p.getSusceptible() == 60000); 
  CHECK(p.getInfected() == 40);
  CHECK(p.getRecovered() == 0);
  CHECK(p.getDeads() == 0);
  
  CHECK(ps.getAlfa() == 0.001);
  CHECK(ps.getBeta() == 0.85);
  CHECK(ps.getGamma() == 0.2);
  CHECK(ps.getMu() == 0.2);

  CHECK(oggetto.getTime()==50);
}


TEST_CASE("Testing the pandemic constructor.") {

  People p;
  Parameters ps;
  Pandemic oggetto;

  p.set_People(300,4,5,6);
  ps.set_Parameters(0.003,0.3,0.4,0.6);
  
  CHECK(oggetto.set_Pandemic(p,ps,60)==true);
  CHECK(oggetto.set_Pandemic(p,ps,-40)==false);


  CHECK(oggetto.getPar().getAlfa()==0.003);
  CHECK(oggetto.getPar().getBeta()==0.3);
  CHECK(oggetto.getPar().getGamma()==0.4);
  CHECK(oggetto.getPar().getMu()==0.6);

  CHECK(oggetto.getPopulation()[0].getSusceptible()==300);
  CHECK(oggetto.getPopulation()[0].getInfected()==4);
  CHECK(oggetto.getPopulation()[0].getRecovered()==5);
  CHECK(oggetto.getPopulation()[0].getDeads()==6);

  CHECK(oggetto.getTime()==60);

}


TEST_CASE("Testing method simulate.") {

  Pandemic population;
  population.simulate();

  auto it=population.getPopulation().begin();
  int Size=population.getPopulation().size();

  bool a,b,c,d;

  for (int j=0; j<Size; j++){

    if ((*it).getSusceptible() >=0 ) {
      a = true;
    } else { a = false; }

    if ((*it).getInfected() >=0 ) {
      b = true;
    } else { b = false; }

    if ((*it).getRecovered() >=0 ) {
      c = true;
    } else { c = false; }

    if ((*it).getDeads() >=0 ) {
      d = true;
    } else { d = false; }
    

    CHECK (a == true);
    CHECK (b == true);
    CHECK (c == true);
    CHECK (d == true);

    it++;
  }
  
}




/*
TEST_CASE("Testing the class handling a floating point data sample") {
  Sample sample;

  REQUIRE(sample.size() == 0);

  SUBCASE("Calling size() with four points") {
    sample.add(1.0);
    sample.add(1.5);
    sample.add(2.0);
    sample.add(2.5);
    CHECK(sample.size() == 4);
  }

  SUBCASE("Calling statistics() with no points throws") {
    CHECK_THROWS(sample.statistics());
  }
}*/