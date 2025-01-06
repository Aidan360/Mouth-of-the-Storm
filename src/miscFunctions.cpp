#include "initalize.hpp"

double abso(double x) {
    return(sqrt(pow(x,2)));
} 
double sgn(double x) { 
    if (x == 0) {
        return(0);
    }
    else if (x > 0) { 
        return (1);
    }
    else {
        return(-1);
    }
}
