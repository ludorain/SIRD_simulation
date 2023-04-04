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