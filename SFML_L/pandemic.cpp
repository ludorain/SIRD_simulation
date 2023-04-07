#include "pandemic.hpp"

#include <iostream>
#include <random>


Pandemic::Pandemic(int N) : 
  pan_side {N},
  pan_grid (N * N) 
{} 

bool Count::set_I(int i){
  if () {
    
    return true;
  } else {
    return false;
  }
}

bool Count::set_L(int i){
  if () {
    
    return true;
  } else {
    return false;
  }
}


//Setting initial infected
Pandemic Pandemic::start(Pandemic& clear, int& infected) {

  int l = clear.pan_side;
  Pandemic set(l);

  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{0, l - 1};

  for (int j=0; j < infected; j++) {

    int k = dist(eng);
    int h = dist(eng);
    
    while (set.Reading_cell(k,h) == Person::Infected){
      k++;
      h++;
    }

    set.Writing_cell(k,h) = Person::Infected;
  }

  return set;
}


int const Pandemic::get_Side (){
  return  pan_side;
}

Grid Pandemic::get_Grid(){
  return pan_grid;
}


//Creating toroidal structure 
Person const& Pandemic::Reading_cell(int r, int c) {

  int rr = (r + pan_side) % pan_side;
  int cc= (c + pan_side ) % pan_side;
  int index = (rr* pan_side) + cc;

  return pan_grid[index];
} 


Person& Pandemic::Writing_cell(int r, int c){

  int rr = (r + pan_side ) % pan_side;
  int cc= (c + pan_side ) % pan_side;
  int index = (rr* pan_side) + cc;

  return pan_grid[index];   
}



//Check infected number next to the cell
int Pandemic::infected_neighbours(Pandemic& pandemic, int r, int c) {

  int contacts = 0;
  for (int i : {-1, 0, 1})
  {
    for (int j : {-1, 0, 1})
    {
      if (pandemic.Reading_cell(r+i, c+j) == Person::Infected) {
        contacts++;
      }
    }
  }

  return contacts;
}


//Day evolution
Pandemic Pandemic::evolve(Pandemic& now, Probability& prob, Count& count) {

  int l = now.pan_side; 
  Pandemic next (l);

  next=now;

  std::default_random_engine eng{std::random_device{}()};
  std::uniform_real_distribution <float> dis(0.0, 1.0); 

  for (int r = 0 ; r < l ; r++ ) {

    for (int c = 0 ; c < l ; c++) {

      if (now.Reading_cell(r,c) == Person::Susceptible ) {

        float p1 = dis(eng);
        double b = prob.Beta_*now.infected_neighbours(now, r, c); 
           
        if (prob.Alfa_ != 0 && p1 <= prob.Alfa_ ){

          next.Writing_cell(r,c) = Person::Recovered; 
          count.R_+=1;
          count.S_-=1;

        } else  if ( p1 <= (prob.Alfa_+ b)) {

          next.Writing_cell(r,c) = Person::Infected;
          count.I_+=1; 
          count.S_-=1; 
              
        } else {
          //It doesn't change states
        }


      } else if (now.Reading_cell(r,c) == Person::Infected) {                 

        double p2 = dis(eng);

        if (p2<=(prob.Gamma_)) {

          next.Writing_cell(r,c) = Person::Recovered;
          count.R_+=1;
          count.I_-=1; 

        } else if ( p2 <= (prob.Gamma_+prob.Mu_)) {

          next.Writing_cell(r,c) = Person::Dead; 
          count.I_-=1;
          count.D_+=1;

        } else { 
          //Here it doesn't change state
        }
      }
    }
  }

  return next;
}























/*
void life::Pandemic::check_number(int& n ,int& lato)
{ 
  if ( lato > 50){
    std::cout<< "the value insered  for the grid side is too much big "<< '\n' << "It will be asigned a value by default"<<'\n';//molto improvvisato il testo è da riguardare , c'ho provato
    pan_side = 50;
    lato = 50 ;
  }

  double limit = (lato * lato ) * 0.02;
  int lim = (int)limit;
 
  if ((limit -lim)>=0.5) {lim++;}//limit è un double e lo devo approssimare per farlo diventare intero 
     
  if (n > lim ) {
    std::cout<< "the value insered  for the initial number of infected is ...... "<< '\n' << "It will be asigned a value by default"<<'\n';//molto improvvisato il testo è da riguardare , c'ho provato
    n = lim;
  }

} */


//std::this_thread::sleep_for(std::chrono::seconds(5));  





/////////////////////////////////////////////////////////////////
// inizializza all'inizio 

 /*bool operator==(Pandemic const& left, Pandemic const& right)//utile per i testcase; cosa utile per orale=> qua si sfrutta l'operatore == dei vector, per evitare di scorrere cella per cella e verificare che il contenuto sia uguale 
{
   return left.Pandemic::grid() == right.Pandemic::grid(); 
}
 bool operator!=(Pandemic const& left, Pandemic const& right)
{
  return left.pan_grid != right.pan_grid;
}

  assert ((l*l) == (count.s + count.i + count.r + count.d));
  assert ((prob.alfa + prob.beta) < 100);

*/