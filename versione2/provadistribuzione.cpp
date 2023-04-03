
#include <ctime> 
#include <iostream>

int main () {

    double dado ;

    double s_resto =0.7; //fract part
    double i_resto = 0.2;
    double r_resto = 0.3;
    double d_resto = 0.1;
    
    double sommafractpart = s_resto +i_resto+r_resto+d_resto;

    //proporzione s_resto:0.13 = x:100

    int ghost = 5; // = Ntotnext - Ntot0;

    for (int i = 0; i<ghost; i++) {
        srand (time(NULL));
        dado= rand()%101; //dado è un numero tra 0 e 100 ma io lo voglio double da sistemare 
        double f = (double)rand() / RAND_MAX;
        std::cout <<f;
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