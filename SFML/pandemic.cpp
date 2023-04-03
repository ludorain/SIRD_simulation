#include "pandemic.hpp"

#include <cassert>

life::Pandemic::Pandemic(int& N)
    : pan_side{N},
      pan_grid(N * N, life::Person::Susceptible) { }  // inizializza all'inizio

friend bool life::Pandemic::operator==(
    life::Pandemic const& left,
    life::Pandemic const&
        right)  // utile per i testcase; cosa utile per orale=> qua si sfrutta
                // l'operatore == dei vector, per evitare di scorrere cella per
                // cella e verificare che il contenuto sia uguale
{
  return left.pan_grid == right.pan_grid;
}
bool life::Pandemic::operator!=(life::Pandemic const& left,
                                life::Pandemic const& right) {
  return left.pan_grid != right.pan_grid;
}
/*friend life::Person const& life::Pandemic::Person_cell(int r, int c) const
//accesso tramite gli indici r e c; correggi per forma toroidale
{
int r_ = (r + pan_side) % pan_side;//qua creo la struttura toroidale
int c_= (c + pan_side ) % pan_side;
assert(r_>= 0 && r_< pan_side && c_>= 0 && c_< pan_side);
int index = (r_* pan_side) + c_;//passaggio da 2 indici ad un indice per la
griglia assert(index >= 0 && index < pan_grid.size()); return pan_grid[index];

} */
friend life::Person& life::Pandemic::Person_cell(
    int r, int c)  //è necessario prima accedere alla riga r-esima e poi
                   //accedere all'elemento c-esimo
{
  int r_ =
      (r + pan_side) %
      pan_side;  // qua creo la struttura toroidale-> arrotolo il tovagliolo
  int c_ = (c + pan_side) % pan_side;  //-> cucio le estremità
  assert(r_ >= 0 && r_ < pan_side && c_ >= 0 && c_ < pan_side);
  int index = (r_ * pan_side) + c_;  // passaggio da 2 indici ad un indice per
                                     // la griglia; nonn l'ho ben capito
  assert(index >= 0 && index < pan_grid.size());
  return pan_grid[index];
}  // da controllare con assert nei TEST CASE

int const life::Pandemic::side() { return pan_side; }
void life::Pandemic::start(life::Pandemic& change,
                           int& inf)  // iniettare gli infettati iniziali
{
  int l = change.side();
  for (int j = 0; j <= inf; j++) {
    srand(time(NULL));
    int k = rand() % l;  // qua mi serve un random double
    int h = rand() % l;
    change.Pandemic::Person_cell(k, h) = life::Person::Infected;
    while (change.Person_cell(k, h) == life::Person::Infected) {
      change.Person_cell(k + 1, h + 1) = life::Person::Infected;
      k++;
      h++;
    }
  }
}
int life::Pandemic::infected_neighbours(Pandemic const& pandemic, int r,
                                        int c) {
  int contacts = 0;
  for (int i : {-1, 0, 1}) {    // vado su e giù nelle righe
    for (int j : {-1, 0, 1}) {  // vado a destra e a sinistra nelle colonne
      if (pandemic.Person_cell(r + i, c + j) == Person::Infected) contacts++;
    }
    return contacts;  // n numero dei contatti infetti
  }
}
life::Pandemic life::Pandemic::evolve(
    Pandemic const& current, float& beta, float& gamma, float& alfa1,
    float& alfa2, float& omega, float& s, float& i, float& r, float& d,
    int& const T, double& const t_m)  // ho messo le probabilità come reference
                                      // per alleggerire l'allocazione in memoria
{
  int l = current.side();  // lato della griglia dell'oggetto current
  life::Pandemic next(
      current.side());  // uso il costruttore di pandemic che riechiede come
                        // parametro solo il lato della griglia ovvero l
  assert((l * l) ==
         (s + i + r +
          d));  // l'area della griglia deve essere uguale alla popolazione
  assert((alfa1 + beta) < 100 &&
         (alfa2 + omega));  // verifica della normalizzazione delle probabilità

  for (int r = 0; r <= l; r++) {    // loop sulle righe
    for (int c = 0; c <= l; c++) {  // loop sulle celle di ogni riga
      if (current.Person_cell(r, c) ==
          life::Person::Susceptible)  // suscettibili
      {
        srand(time(NULL));
        double p1 = (float)rand();
        double b = (beta / 100) *
                   life::Pandemic::infected_neighbours(
                       current, r,
                       c);  // calcola la probabilità specitica per la cella
        if (alfa1 != 0 && 0 < p1 <= (alfa1 / 100)) {
          next.Person_cell(r, c) =
              life::Person::Recovered;  // riassegnazione dello stato nella
                                        // stessa posizione ma nella griglia
                                        // successiva
          r++;
          s--;
        } else if ((alfa1 / 100) < p1 = < (alfa1 / 100) + b) {
          next.Person_cell(r, c) = life::Person::Infected;
          i++;
          s--;
        }
      } else if (current.Person_cell(r, c) == Person::Infected) {  // infetti
        // generazione di un numero random da 0 a 1
        // std::this_thread::sleep_for(std::chrono::(100));//ipotetico tempo di
        // quarantena con la malattia
        srand(time(NULL));
        double p2 = (float)rand();
        if (p2 <= (gamma / 100))  // probabilità di guarire
        {
          next.Person_cell(r, c) = Person::Recovered;
          r++;
          i--;
        } else {
          next.Person_cell(r, c) = Person::Dead;  // probabilità di morire
          i--;
          d++;
          // sarebbe carino far passare del tempo prima di fare guarire o morire
        }

        // assegnare il valore corretto a next (r,c)
      }
    }

    return next;  // restituisce una nuova griglia con i nuovi stati
  }
}

/*void life::Pandemic::print(Pandemic const& p, int& T)
 {
   for (int i = 0; i != T; ++i)
   {
   print(p);
   p = evolve(p);
   }

 }*/
