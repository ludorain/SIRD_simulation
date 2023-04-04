#include "pandemic.hpp"
#include <cassert>
#include <iostream>
using namespace life;
Pandemic::Pandemic(int& N) : pan_side {N},pan_grid(N * N, Person::Susceptible)
{
} // inizializza all'inizio 

 /*bool operator==(Pandemic const& left, Pandemic const& right)//utile per i testcase; cosa utile per orale=> qua si sfrutta l'operatore == dei vector, per evitare di scorrere cella per cella e verificare che il contenuto sia uguale 
{
   return left.Pandemic::grid() == right.Pandemic::grid(); 
}
 bool operator!=(Pandemic const& left, Pandemic const& right)
{
  return left.pan_grid != right.pan_grid;
}*/
Person const& Pandemic::Reading_cell(int r, int c)  //accesso tramite gli indici r e c; correggi per forma toroidale 
{ 
  int r_ = (r + pan_side) % pan_side;//qua creo la struttura toroidale 
  int c_= (c + pan_side ) % pan_side;
  assert(r_>= 0 && r_< pan_side && c_>= 0 && c_< pan_side);
  int index = (r_* pan_side) + c_;//passaggio da 2 indici ad un indice per la griglia 
  assert(index >= 0 && index < pan_grid.size());
    return pan_grid[index];

} 
 Person& Pandemic::Writing_cell(int r, int c)//è necessario prima accedere alla riga r-esima e poi accedere all'elemento c-esimo
{ 
  //int l = grid.side();
  int r_ = (r + pan_side ) % pan_side;//qua creo la struttura toroidale-> arrotolo il tovagliolo 
  int c_= (c + pan_side ) % pan_side;//-> cucio le estremità
  assert(r_>= 0 && r_< pan_side && c_>= 0 && c_< pan_side);
  int index = (r_* pan_side) + c_;//passaggio da 2 indici ad un indice per la griglia; nonn l'ho ben capito  
  assert(index >= 0 && index < pan_grid.size());
    return pan_grid[index];   
}//da controllare con assert nei TEST CASE

  int const Pandemic::side (){
    return  pan_side;
}
  /*Grid Pandemic::grid(){
    return pan_grid;
  }*/
void Pandemic::start(Pandemic& change ,int& inf )//iniettare gli infettati iniziali
{
  int l = change.side();
  for (int j=0;j <= inf; j++)
  {
    srand(time(NULL));
    int k = rand() % l;//qua mi serve un random double
    int h = rand() % l;
     while (change.Writing_cell(k,h) == Person::Infected)
    {
      change.Writing_cell(k+1,h+1) = Person::Infected ;
      k++;
      h++;
    }
    change.Writing_cell(k,h) = Person::Infected;
   
    
  }
}
  int Pandemic::infected_neighbours(Pandemic& pandemic, int r, int c)
  {
    int contacts = 0;
    for (int i : {-1, 0, 1}) //vado su e giù nelle righe 
    {
      for (int j : {-1, 0, 1}) //vado a destra e a sinistra nelle colonne 
      {
         if (pandemic.Reading_cell( r+i, c+j) == Person::Infected) contacts++ ;
      }
    }
    return contacts;//n numero dei contatti infetti}
  }
  Pandemic  Pandemic::evolve(Pandemic& current, Probability& prob, Count& count) //ho messo le probabilità come reference per alleggerire l'allocazione in memoria
{

  int l = current.pan_side; //lato della griglia dell'oggetto current
  Pandemic next (l); // uso il costruttore di pandemic che riechiede come parametro solo il lato della griglia ovvero l  
  assert ((l*l) == (count.s + count.i + count.r + count.d)); //l'area della griglia deve essere uguale alla popolazione  
  assert ((prob.alfa + prob.beta) < 100 && (prob.gamma + prob.omega)); //verifica della normalizzazione delle probabilità
  
  for (int r = 0 ; r <= l ; r++  )    // loop sulle righe
  {
    for (int c = 0 ; c <= l ; c++)  // loop sulle celle di ogni riga
    {
     if (current.Reading_cell(r,c) == Person::Susceptible )  //suscettibili
     {
        srand(time(NULL));
        double p1 = (float)rand ();
        double b = (prob.beta/100)*infected_neighbours(current, r, c);// calcola la probabilità specitica per la cella 
           if (prob.alfa != 0 && 0< p1 <= (prob.alfa/100)){
              next.Writing_cell(r,c) = Person::Recovered;//riassegnazione dello stato nella stessa posizione ma nella griglia successiva 
              count.r++;
              count.s--;
              }
           else  if ((prob.alfa/100) < p1 <= (prob.alfa/100)+b )
                 {
                   next.Writing_cell(r,c) = Person::Infected;
                   count.i++; 
                   count.s--;     
                 }  
      }
     else if (current.Reading_cell(r,c) == Person::Infected){//infetti
        //generazione di un numero random da 0 a 1 
        //std::this_thread::sleep_for(std::chrono::(t_m));//ipotetico tempo di quarantena con la malattia  
        srand(time(NULL));
        double p2 = (float)rand();
             if (p2<=(prob.gamma/100)) //probabilità di guarire
              {
               next.Writing_cell(r,c) = Person::Recovered;
               count.r++;
               count.i--;                                      
              } 
             else {
               next.Writing_cell(r,c) = Person::Dead; //probabilità di morire 
               count.i--;
               count.d++; 
               //sarebbe carino far passare del tempo prima di fare guarire o morire
             }
      }
    }
  }
  return next;//restituisce una nuova griglia con i nuovi stati
}
void Pandemic::check_number(Count& c_start)
{ 
  int A = pan_side * pan_side;
  

}
 

 /*void Pandemic::print(Pandemic& p,Probability& prob, Count& count, int& T) 
  {
    for (int i = 0; i != T; ++i) 
    {
      std::cout << p.pan_grid<< std::endl;//stampa la griglia data in ingresso
      p = evolve(p, prob, count, t_m);// qua fa evolvere la griglia e verrà stampata al ciclo successivo
    }

  }*/

