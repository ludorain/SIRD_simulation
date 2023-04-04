
#include <ctime> 
#include <iostream>
#include <cmath>

int main () {

    double dado;
    double s=1.1,i=2.5,r=1.3,d=1.3;

    double fract_s, int_s;
    fract_s = std::modf(s, &int_s);
    double fract_i, int_i;
    fract_i = std::modf(i, &int_i);
    double fract_r, int_r;
    fract_r = std::modf(r, &int_r);
    double fract_d, int_d;
    fract_d = std::modf(d, &int_d);

    
    double sum = fract_s + fract_i + fract_r + fract_d;

    int ghost = 3;
        std::srand(time(NULL));
    for (int i = 0; i<ghost; i++) {
        dado = static_cast<double>(std::rand()) / RAND_MAX;
        
        if (0<=dado<fract_s/sum ) {
            s+=1;
        } else if (dado<(fract_s+ fract_i)/sum) {
            i+=1;
        } else if (dado<(fract_s+ fract_i+fract_r)/sum) { 
            r+=1;
        } else { d+=1; }
    }

    std::cout <<s<< '\n' << i << '\n'<<r << '\n' << d  ;
}
