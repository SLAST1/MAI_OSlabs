
#include <math.h>

float SinIntegral( float A, float B, float e){
    double integral = 0;

    for( float dot = A; dot < B; dot+=e ){
        integral += sin( dot ) * e;
    }
    return integral;

}