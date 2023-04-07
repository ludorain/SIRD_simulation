#include "pandemic.hpp"
#include <cassert>
#include <iostream>
#include <random>

using namespace life;

Pandemic::Pandemic(int& N) : 
  pan_side {N},
  pan_grid (N * N)     //, Person::Susceptible)
{} 


// inizializza all'inizio 

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
  //assert(r_>= 0 && r_< pan_side && c_>= 0 && c_< pan_side);
  int index = (r_* pan_side) + c_;//passaggio da 2 indici ad un indice per la griglia 
  //assert(index >= 0 && index < pan_grid.size());
  return pan_grid[index];

} 


Person& Pandemic::Writing_cell(int r, int c)//è necessario prima accedere alla riga r-esima e poi accedere all'elemento c-esimo
{ 
  //int l = grid.side();
  int r_ = (r + pan_side ) % pan_side;//qua creo la struttura toroidale-> arrotolo il tovagliolo 
  int c_= (c + pan_side ) % pan_side;//-> cucio le estremità
  //assert(r_>= 0 && r_< pan_side && c_>= 0 && c_< pan_side);
  int index = (r_* pan_side) + c_;//passaggio da 2 indici ad un indice per la griglia; nonn l'ho ben capito  
  //assert(index >= 0 && index < pan_grid.size());
  return pan_grid[index];   
}//da controllare con assert nei TEST CASE

int const Pandemic::side (){
  return  pan_side;
}

Grid Pandemic::grid(){
  return pan_grid;
}


Pandemic Pandemic::start(Pandemic& clear,int& inf )       //iniettare gli infettati iniziali
{
  int l = clear.pan_side;
  std::default_random_engine eng{std::random_device{}()};
  std::uniform_int_distribution<int> dist{0, l - 1};
  //copia dell'oggetto
  Pandemic set(l);

  for (int j=0;j < inf; j++)
  {
    int k = dist(eng);
    int h = dist(eng);
    
    while (set.Reading_cell(k,h) == Person::Infected)
    {
      k++;
      h++;
    }

    set.Writing_cell(k,h) = Person::Infected;
  }
  return set;
}


int Pandemic::infected_neighbours(Pandemic& pandemic, int r, int c)
{
  int contacts = 0;
  for (int i : {-1, 0, 1}) //vado su e giù nelle righe 
  {
    for (int j : {-1, 0, 1}) //vado a destra e a sinistra nelle colonne 
    {
      if (pandemic.Reading_cell( r+i, c+j) == Person::Infected) {
        contacts++;
      }
    }
  }

  return contacts;//n numero dei contatti infetti}
}



Pandemic Pandemic::evolve(Pandemic& current, Probability& prob, Count& count) //ho messo le probabilità come reference per alleggerire l'allocazione in memoria
{
  int l = current.pan_side; //lato della griglia dell'oggetto current
  Pandemic next (l); // uso il costruttore di pandemic che riechiede come parametro solo il lato della griglia ovvero l 

  next=current;

  assert ((l*l) == (count.s + count.i + count.r + count.d)); //l'area della griglia deve essere uguale alla popolazione  
  assert ((prob.alfa + prob.beta) < 100); //verifica della normalizzazione delle probabilità

  std::default_random_engine eng{std::random_device{}()};//settaggio del seme random della libreria std
  std::uniform_real_distribution <float> dis(0.0, 1.0); //dichiarazione della distribuzione uniforme di numeri float 

  for (int r = 0 ; r < l ; r++ )    // loop sulle righe   //NOTA DELLA SOFIA: la sofi crede che qui ci vada < e non <= perchè parte da 0, quindi fa l cicli quando arriva a l-1
  {
    for (int c = 0 ; c < l ; c++)  // loop sulle celle di ogni riga
    {
      if (current.Reading_cell(r,c) == Person::Susceptible )  //suscettibili
      {
        float p1 = dis (eng);//da verificare per estrazione tra 0 e 1
        double b = (prob.beta/100)*current.infected_neighbours(current, r, c);// calcola la probabilità specifica per la cella 
           
           if (prob.alfa != 0 && p1 <= (prob.alfa/100) )
            {
              next.Writing_cell(r,c) = Person::Recovered;       //riassegnazione dello stato nella stessa posizione ma nella griglia successiva 
              count.r++;
              count.s--;

            } else  if ( p1 <= ((prob.alfa/100)+ b)) {

              next.Writing_cell(r,c) = Person::Infected;
              count.i++; 
              count.s--; 
                  
            } else {
              // qui rimane suscettibile -> non serve sto else lo metto solo per capire
            }

      } else if (current.Reading_cell(r,c) == Person::Infected) {                   //infetti
        //generazione di un numero random da 0 a 1 
        //std::this_thread::sleep_for(std::chrono::(t_m));//ipotetico tempo di quarantena con la malattia  
        double p2 = dis(eng);
        if (p2<=(prob.gamma/100))                         //probabilità di guarire
        {
          next.Writing_cell(r,c) = Person::Recovered;
          count.r++;
          count.i--;                                      
        } else {if ((prob.gamma/100) < p1 <= ((prob.gamma+prob.omega)/100)){
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


void life::Pandemic::check_number(int& n ,int& lato)
{ 
  if ( lato > 50){
    std::cout<< "the value insered  for the grid side is too much big "<< '\n' << "It will be asigned a value by default"<<'\n';//molto improvvisato il testo è da riguardare , c'ho provato
    pan_side = 50;
    lato = 50 ;
  }
  double limit = (lato * lato ) *0.02;
  int lim = (int)limit;
 
     if ((limit -lim)>=0.5) lim++;
     
  if (n > lim ) {
    std::cout<< "the value insered  for the initial number of infected is ...... "<< '\n' << "It will be asigned a value by default"<<'\n';//molto improvvisato il testo è da riguardare , c'ho provato
    n = lim;
  }
}
