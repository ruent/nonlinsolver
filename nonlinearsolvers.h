//take a function f and solve for x in f(x) = 0
//on the interval [a,b] where f(a) and f(b) has opposite signs
#include <iostream>
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