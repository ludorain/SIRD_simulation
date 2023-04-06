#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "people.hpp"
#include "parameters.hpp"
#include "pandemic.hpp"

TEST_CASE("testing the default constructor") {

    People p;
    Parameters ps;
    Pandemic oggetto;
    oggetto.simulate();


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

TEST_CASE("Setter class Parameters"){

  Parameters ps;
  
  SUBCASE("Calling setter with correct values")
  
 
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