//take a function f and solve for x in f(x) = 0
//on the interval [a,b] where f(a) and f(b) has opposite signs

//in the main cpp, when I wrote includes like
// <<<#include "nonlinsolver/methods.h", <<<#include "lgmarkov/model.h"
// pragma once did not stop a redifinition error for these i line functions below
//howvere old style ifndef here solved the issue
//but still a little discipline in the "#include"s, a clear head about
//their hierarchy is good I think

//but pragma once works too!!!
//At the moment I will be explicit about hierarchy
//and turn them both off


//#pragma once
//#ifndef METHODS_H
//#define METHODS_H 
template<typename F>
double inline bisectionMethod(const F& f, double a, double b, double tol)
{
    double left  = a, right = b;
    double mid = (left+right)/2;
    double yleft = f(left);
    double ymid = f(mid);
    while(right- left> tol)
    {
        if((yleft >0 && ymid>0) || (yleft <0 && ymid<0) )
        {
            left = mid;
            yleft = ymid;
        }
        else
        {
            right = mid;
        }
        mid = (left+right)/2;
        ymid  = f(mid);
        //cout<< "x: "<<mid<<"value: "<<ymid<<"\n";
        
    }
    return mid;
}

struct example
{
    double a = 1;
    double operator()(double x) const
    {
        return x*x-2;
    }
};
//quick test for bisection
//example f;
//double res = bisectionMethod(f, 0,2,0.0001);
//#endif