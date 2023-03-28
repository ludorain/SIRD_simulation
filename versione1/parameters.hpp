#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

class Parameters{ 

public:
//costruttore default
Parameters();

//funzioni set
void setAlfa();
void setBeta();
void setGamma();
void setMu();

void setParameters();
void setParameters(double, double, double, double);
void setParametersR(double, double, double, double);

//funzioni get
double getAlfa();
double getBeta();
double getGamma();
double getMu();

private:

    double alfa;
    double beta;
    double gamma;
    double mu;
};

#endif