#include <random> 
#include "doctest.h"
#include "pandemic.hpp"

TEST_CASE("Testing state cell")//
{   //Test degli stati 
  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{0, 100 - 1};
  int l = dist(eng);
  Pandemic  block(l);
  Probability prob_test  = {2,35,8,3}; //sarà da togliere 
  Count count;
  CHECK(block.Reading_cell(1,1) == Person::Susceptible); // check iniziale
  block.Writing_cell(1,1) = Infected;
  CHECK(block.Reading_cell(1,1) == Person::Infected);
  block.Writing_cell(1,3) = Person::Recovered;//provax
  CHECK(block.Reading_cell(1,1) == Person::Recovered); 
  block.Writing_cell(1,1) = Person::Dead;
  CHECK(block.Reading_cell(1,1) == Person::Dead);
}


TEST_CASE ("Testing initial situation")
{ // testing the start member function
  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{0, 100 - 1};

  int l = dist(eng);
  Pandemic first(l);
  int inf = dist(eng);

  first = Pandemic::start(first, inf);
  int check = 0;

  //va avanti finchè non controllo tutte le celle

    for (int r = 0 ; r < l ; r++ ){   // loop sulle righe   //NOTA DELLA SOFIA: la sofi crede che qui ci vada < e non <= perchè parte da 0, quindi fa l cicli quando arriva a l-1
   
       for (int c = 0 ; c < l ; c++){

        if (first.Reading_cell(r,c) == Person::Infected) check++;
       }
    }
  
  /*CHECK(check == inf);
  int lato = 51;
  int n = 55;
  life::Pandemic::check_number(n,lato);
  CHECK(lato == 50 && n == 52);*/
}


TEST_CASE("Testing evolution")
{

  int l = 11; 
  Probability prob_test = {2,35,8,3};
  Count count_test;
  Pandemic evolving(l);
  evolving.Writing_cell(4,6) = Person::Infected;
  evolving.Writing_cell(3,5) = Person::Recovered;
  evolving.Writing_cell(5,3) = Person::Dead;
  evolving.Writing_cell(6,2) = Person::Recovered;
  evolving = Pandemic::evolve(evolving, prob_test,count_test);
  CHECK(evolving.Reading_cell(4,6) != Person::Susceptible);
  CHECK(evolving.Reading_cell(3,5) != Person::Susceptible && evolving.Reading_cell(3,5) != Person::Dead);
  CHECK(evolving.Reading_cell(5,3) != Person::Susceptible && evolving.Reading_cell(3,5) != Person::Recovered);
  CHECK(evolving.Reading_cell(6,2) != Person::Susceptible && evolving.Reading_cell(3,5) != Person::Infected);
  CHECK(evolving.Reading_cell(4,4) != Person::Dead);
}
