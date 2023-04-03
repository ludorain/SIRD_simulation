// automa cellulare
#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP
#include <cassert>
#include <iostream>
#include <random>

namespace life {
enum Person {
  Susceptible = 0,
  Infected,
  Recovered,
  Dead
}; // tipo enumeratore; tipo oggeto stato della cella

// futura associazione di colore per ogni stato
using Grid = std::vector<Person>; // rinominazione di una variabile scomoda
class Pandemic {
private:
  // creazione della griglia
  Grid pan_grid;
  int pan_side; // il lato della griglia

public:
  // Cotruisce una griglia bidimensionale (agent x agent)
  Pandemic(int &);
  void start(Pandemic &, int &);
  // Accesso alla persona quindi al suo stato
  // friend Person const& Person_cell(int r, int c) ;//solo lettura
  // get a mutable reference to the Person at position (r,c)
  Person &Person_cell(int r, int c); // anche scrittura
  friend bool operator==(Pandemic const &left, Pandemic const &right);
  friend bool operator!=(Pandemic const &left, Pandemic const &right);

  int infected_neighbours(Pandemic &pandemic, int r, int c);
  Pandemic evolve(Pandemic &current, float &beta, float &gamma, float &alfa1,
                  float &alfa2, float &omega, float &s, float &i, float &r,
                  float &d, int const &T, double const &t_m);

  int side() const;
  // void print(Pandemic const& p) ;
};
} // namespace life

#endif

