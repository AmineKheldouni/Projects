
#include "koolplot.h"
#include "math.h"
#include <iostream>

// Constantes
const double alpha = 3.;  // Taux de reproduction des proies
const double beta = 2.;   // taux de mortalité des proies dû aux prédateurs
const double delta = 1.;  // taux de reproduction des prédateurs en fonction des proies mangées
const double gamma = 4.;  // Taux de mortalité des prédateurs

const double x0 = 5;    // Nombre initial de chèvres
const double y0 = 3;     // Nombre initial de loups
const double t0 = 0.;
const double tf = 10.0;
const int N = 1000;
const float pas = (tf-t0)/N;

// Fonctions de variation de la population des proies puis celle des prédateurs
double var_proie(double t, double x, double y)
{
    return x*(alpha-beta*y);
}

double var_pred(double t, double x, double y)
{
    return -y*(gamma-delta*x);
}


void Euler2(Plotdata& t, Plotdata& X, Plotdata& Y, Plotdata& X_var, Plotdata& Y_var)
{
    point(t,t0);
    point(X,x0);
    point(Y,y0);
    point(X_var,var_proie(t0,x0,y0));
    point(Y_var,var_pred(t0,x0,y0));
    float a,b,c;
    a = x0;
    b = y0;
    c = t0;

    for(int i=0;i<N+1;i++)
        {  a = a+pas*var_proie(c,a,b);
           b = b+pas*var_pred(c,a,b);
           c = c+pas;
           point(t,c);
           point(X,a);
           point(Y,b);
           point(X_var,var_proie(c,a,b));
           point(Y_var,var_pred(c,a,b));
        }
}

// Fonction principale
int main()
{
    Plotdata t,X,Y,var_proie,var_pred;
    const int N = t.size();
    double h = (t.max()-t.min())/N;
    Euler2(t,X,Y,var_proie,var_pred);
    Plotdata proie = X;
    Plotdata pred = Y;
    setColor(t,X,GREEN);
    t << t;
    X << Y;
    while(X.size() != t.size())
        breakplot(X,Y);
    plot(t,X,BLUE);
    breakplot(proie,var_proie);
    breakplot(pred,var_pred);

    plot(proie,var_proie,DODGERBLUE);
    plot(pred,var_pred,REDRED);

    // Portraits de phase :
    setColor(X,var_proie,DODGERBLUE);
    var_proie << var_pred;
    while(X.size() != var_proie.size())
        breakplot(var_pred,var_proie);

    breakplot(var_pred,var_proie);
    breakplot(X,var_proie);
    plot(X,var_proie,REDRED);

   return 0;
}
