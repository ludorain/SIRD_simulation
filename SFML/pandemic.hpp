//automa cellulare 
#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP
#include <random>
#include <iostream>
#include <cassert>
namespace life {
 enum Person {Susceptible = 0 ,Infected , Recovered, Dead}; //tipo enumeratore; tipo oggeto stato della cella 
 struct Probability 
 {
    float beta;//infettare un suscettibile
    float alfa;//vaccinare un suscettibile
    float gamma;//guarire un infetto
    float omega;//morte di un infetto 
 };
 struct Count 
 {
    int s;
    int i;
    int r;
    int d;
 };
// futura associazione di colore per ogni stato
using Grid  = std::vector<Person>;//rinominazione di una variabile scomoda
 class Pandemic
{
   private: 
   //creazione della griglia 
    Grid pan_grid;
    int pan_side;//il lato della griglia

   public:
    //Cotruisce una griglia bidimensionale (agent x agent)
    Pandemic(int&);
    void start (Pandemic& , int&);
    //Accesso alla persona quindi al suo stato  
    Person const& Reading_cell(int r, int c) ;//solo lettura
    // get a mutable reference to the Person at position (r,c)
    Person& Writing_cell(int r, int c);//anche scrittura
    friend bool operator==(Pandemic const& left, Pandemic const& right){
        return left.pan_grid == right.pan_grid;
    }
    friend bool operator!=(Pandemic const& left, Pandemic const& right)
    {
        return left.pan_grid != right.pan_grid;
    }
    int infected_neighbours(Pandemic& pandemic, int r, int c);
    Pandemic evolve(Pandemic& current, Probability& prob, Count& count); //ho messo le probabilità come reference per alleggerire l'allocazione in memoria
    int const side ();
    void check_number(Count& );
    // Grid grid();
    //void print(Pandemic& p, Probability& prob, Count& count,int& T);
};
}
 



#endif
