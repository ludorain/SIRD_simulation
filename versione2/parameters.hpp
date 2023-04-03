#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

class Parameters{ 

public:
//costruttore default
Parameters();

//funzioni set
bool set_Alfa(double);
bool set_Beta(double);
bool set_Gamma(double);
bool set_Mu(double);
void control_R0();
void set_Zero();


//void setParameters(double, double, double, double);
void setParametersR(double, double, double, double);

//funzioni get
double getAlfa();
double getBeta();
double getGamma();
double getMu();

private:

    double Alfa_;
    double Beta_;
    double Gamma_;
    double Mu_;
};

#endif