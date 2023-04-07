#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP

#include <iostream>
#include <vector>



//Possible states
enum Person {Susceptible = 0, Infected, Recovered, Dead};

class Pandemic
{
   public:

   //Default constructor
   Pandemic();

   //Setting the grid 
   void set_I (int);
   void set_Side (int);

   static Pandemic start (Pandemic& , int&);

   //Getter
   int const get_Side();
   Grid get_Grid();
   int get_I();
   


   //Reading and modifying cell
   Person const& Reading_cell(int r , int c);
   Person& Writing_cell(int r, int c);


   //Operator overloading
   friend bool operator== (Pandemic const& left, Pandemic const& right){
      return left.pan_grid == right.pan_grid;
   }

   friend bool operator!= (Pandemic const& left, Pandemic const& right){
      return left.pan_grid != right.pan_grid;
   }

   friend std::ostream& operator<< (std::ostream& output,  Pandemic& pan){ 

      for( int r = 0; r != pan.pan_side; r++ ){

         for(int c = 0; c != pan.pan_side; c++ ) {

            std::cout<< pan.Writing_cell(r,c)<< " " ;
            
         }

         std::cout << '\n';
      }

      return output;
   }



   //Check number of infected next to the cell
   int infected_neighbours(Pandemic& pandemic, int r, int c);

   //Day evolution 
   static Pandemic evolve(Pandemic& current, Probability& prob, Count& count); 


   //void check_number(int& n, int& lato);

   //void print(Pandemic& p, Probability& prob, Count& count,int& T);


   private: 

   std::vector<Person> Grid_;
   int Side_;  

   int S_;
   int I_;
   int R_;
   int D_;

};



#endif
