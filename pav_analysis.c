#include <math.h>
#include "pav_analysis.h"
#include <stdio.h>


float compute_power(const float *x, unsigned int N) {
    float sum = 1e-12, res;
    for(unsigned int i = 0; i<N; i++){
        sum = sum + (x[i])*(x[i]);
    }
    res = 10*log10(sum/N);
    return res;
}

float compute_am(const float *x, unsigned int N) {
    
    float sum = 1e-12;
    for(unsigned int i = 0; i<N; i++){
        sum = sum + x[i];
    }
    return sum/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    float sum=1e-12;
    int amp_cons = fm/(2*(N-1));
    for(unsigned int i = 0; i<N-1; i++){
        if((x[i]>=0 && x[i+1]<0) || x[i]<0 && x[i+1]>=0){
            sum++;
        }
    

    }
    return amp_cons*sum;;
}

float compute_power_window(const float *x, unsigned int N, const float *ventana){
    
    float sum = 0;
    float den = 0;
    for(int i = 0; i<N; i++){
       
        sum = sum + ((x[i]*ventana[i])*(x[i]*ventana[i]));
        den = den + (ventana[i] * ventana[i]);
        
    }   
    return 10*log10(sum/den);   


}

