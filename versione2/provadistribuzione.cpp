
#include <ctime> 
#include <iostream>
#include <cmath>

int main () {

    double dado;
    double s,i,r,d;

    double fract_s, int_s;
    fract_s = std::modf(s, &int_s);
    double fract_i, int_i;
    fract_i = std::modf(i, &int_i);
    double fract_r, int_r;
    fract_r = std::modf(r, &int_r);
    double fract_d, int_d;
    fract_d = std::modf(d, &int_d);

    
    double sumfract = fract_s + fract_i + fract_r + fract_d;

    int ghost = 5; // = Ntotnext - Ntot0;
        std::srand(time(NULL));
    for (int i = 0; i<ghost; i++) {
        dado = static_cast<double>(std::rand()) / RAND_MAX;
        std::cout <<dado;
    //qui non va bene 
        if (0<=dado<s_resto ) {
                //incrementa s di 1
        }else if (dado<s_resto+i_resto) {
                //incrementa i di 1
        }else if (dado<s_resto+i_resto+r_resto) {
                //incrementa r di 1
        }else {
                //incementra d di 1
        }

    }
}

// in sostanza castro i numeri a cazzo poi conto quanti ne ho ghostati e faccio u nfor con cui li aggiungo con distribuzione di probabilità