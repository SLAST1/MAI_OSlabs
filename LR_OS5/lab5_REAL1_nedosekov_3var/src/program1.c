#include <stdio.h>
#include "program1.h"
#include <stdlib.h>


int main(){

    char comand;
    while( scanf( "%c", &comand ) > 0 ){
        if ( comand == '1' ){
            float A,B,e;
            scanf( "%f%f%f", &A, &B, &e );
            printf( "Integral = %f\n", SinIntegral( A, B, e) );
        } else if ( comand == '2' ){
            int A,B;
            scanf( "%d%d", &A, &B );
            printf( "GCD = %d\n", GCF( A, B ) );
        }else if ( comand == EOF  ){
            exit(0);
        }else if ( comand == 'q' ){
            exit(0);
        }else if ( comand == '\n' || comand == '\t' || comand == ' ' ){
            continue;
        }else{
            printf("Wrong format\n");
        }
    }
}