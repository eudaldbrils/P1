#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "pav_analysis.h"
#include "fic_wave.h"

int main(int argc, char *argv[]) {
    float tlong = 0.020;
    float tdesp = 0.010;
    float fm;
    int   N;
    int   M;
    int   trm;
    float *x;
    short *buffer;
    float *hamming;
    float *x_i;
    FILE  *fpWave;
    FILE  *fres;
    
    

    if (argc != 2 && argc != 3) {
        fprintf(stderr, "Empleo: %s inputfile [outputfile]\n", argv[0]);
        return -1;
    }

    if ((fpWave = abre_wave(argv[1], &fm)) == NULL) {
        fprintf(stderr, "Error al abrir el fichero WAVE de entrada %s (%s)\n", argv[1], strerror(errno));
        return -1;
    }
    if ((fres = fopen(argv[2], "w"))== NULL){
        fprintf(stderr, "Error al abrir el fichero txt de entrada %s (%s)\n", argv[2], strerror(errno));
        return -1;
    }
    N = 0.01 * fm;
    M = tdesp * fm;
    if ((buffer = malloc(N * sizeof(*buffer))) == 0 ||
        (x = malloc(N * sizeof(*x))) == 0) {
        fprintf(stderr, "Error al ubicar los vectores (%s)\n", strerror(errno));
        return -1;
    }
    

   
   
   
    trm = 0;
    
    int proba, res;
    while (lee_wave(buffer, sizeof(*buffer), N, fpWave) == N) {
        for (int n = 0; n < N; n++){
            x[n] = buffer[n] / (float) (1 << 15);
            //hamming[n] = 0.53836 - (0.46164*(cos((2*3.1416*n)/(N-1))));
            //proba = (trm*M)+n;
            //printf("%d\n", proba);
            
            
        }
      
        
       

   
        
        fprintf(fres,"%d\t%f\t%f\t%f\n", trm, compute_power(x, N),
                                        compute_am(x, N),
                                        compute_zcr(x, N, fm));
               
        
        trm += 1;
        //printf("%d\n", trm);
    }
    /*int pos=0;
    int source=0;
    while(lee_wave(buffer, sizeof(*buffer), N, fpWave)==N){
        
        for(int n=0;n<N;n++){
            x[n] = buffer[n] / (float) (1 << 15);
            hamming[n] = 0.53836 - (0.46164*(cos((2*3.1416*n)/(N-1))));
        }
        fseek(fpWave,pos,source);
        pos=pos+M;
        fprintf(fres,"%d\t%f\n", trm, compute_power_window(x, N, hamming));
        trm++;
    }
    */
    unsigned int mono = mono_channel(fpWave);
    //printf("%x\n", mono);
    unsigned int bps = bits_per_sample(fpWave);
    //printf("%d\n", bps);
    if(mono != 1){
        printf("Error: no es monocanal\n");
        return -1;
    }
    else if(bps!=16){
        printf("Error: no tiene 16 bits_per sample\n");
        return -1;
    }
    else{
        printf("Es mono canal y de 16 bits_per_sample\n");
    }
    
    //unsigned int bits_sample = bits_per_sample(fpWave);
    cierra_wave(fpWave);
    fclose(fres);
    free(buffer);
    free(x);
    
    return 0;
}
