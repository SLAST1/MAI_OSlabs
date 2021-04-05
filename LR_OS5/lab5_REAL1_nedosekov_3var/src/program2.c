#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "program2.h"

#define FIRST 1
#define SECOND 2

int curRealisation = SECOND;
void* libFD;
float (*SinIntegral) ( float, float, float );
int (*GCF) ( int, int );
void (*who)();
char* err = NULL;

void swapRealisation(){
    if ( dlclose( libFD ) != 0 ){
        perror( "Cant close dl" );
        exit(1);
    }
    char* nextName;
    if ( curRealisation == SECOND ){
        curRealisation = FIRST;
        nextName = LibFisrstReal;
    }else{
        curRealisation = SECOND;
        nextName = LibSecondReal;
    }

    libFD = dlopen (nextName, RTLD_LAZY);
    if (!libFD) {
        perror("err cant swap lib" );
        exit(1);
    }
    SinIntegral = dlsym(libFD, "SinIntegral");
    if ((err = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", err);
        dlclose( libFD );
        exit(1);
    }
    GCF = dlsym(libFD, "GCF");
    if ((err = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", err);
        dlclose( libFD );
        exit(1);
    }
    who = dlsym(libFD, "who");
    if ((err = dlerror()) != NULL){
        fprintf (stderr, "%s\n", err);
        dlclose(libFD);
        exit(1);
    }
}

int main(){

    libFD = dlopen (LibFisrstReal, RTLD_LAZY);
    if (!libFD) {
        perror("err cant open standart second lib" );
        exit(1);
    }
    SinIntegral = dlsym(libFD, "SinIntegral");
    if ((err = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", err);
        dlclose( libFD );
        exit(1);
    }
    GCF = dlsym(libFD, "GCF");
    if ((err = dlerror()) != NULL)  {
        fprintf (stderr, "%s\n", err);
        dlclose( libFD );
        exit(1);
    }
    who = dlsym(libFD, "who");
    if ((err = dlerror()) != NULL){
	    fprintf(stderr,"%s\n", err);
	    dlclose( libFD);
	    exit(1);
    }


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
        } else if ( comand == '0' ){
            swapRealisation();
	} else if ( comand == '!'){
		who();
        }else if ( comand == EOF  ){
            dlclose( libFD );
            exit(0);
        }else if ( comand == 'q' ){
            dlclose( libFD );
            exit(0);
        }else if ( comand == '\n' || comand == '\t' || comand == ' ' ){
            continue;
        }else{
            printf("Wrong format\n");
        }
    }
}
