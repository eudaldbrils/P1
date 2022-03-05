#include <stdio.h>
#include "fic_wave.h"

FILE    *abre_wave(const char *ficWave, float *fm) {
    FILE  *fpWave;
    unsigned int buff[1];
    
    if ((fpWave = fopen(ficWave, "r")) == NULL) return NULL;
    if (fseek(fpWave, 44, SEEK_SET) < 0) return NULL;
    fseek(fpWave,24, SEEK_SET);
    fread(buff, sizeof(unsigned int), 1, fpWave);
    //printf("%x", buff[0]);
    *fm = buff[0];

    return fpWave;
}

size_t   lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave) {
    return fread(x, size, nmemb, fpWave);
}

void    cierra_wave(FILE *fpWave) {
    fclose(fpWave);
}

unsigned int mono_channel(FILE *file_wav){
    
    unsigned int buff[1];
    fseek(file_wav,22, SEEK_SET);
    fread(buff, sizeof(unsigned int)/2, 1, file_wav);
    return buff[0];
}

unsigned int bits_per_sample(FILE *file_wav){
    
    unsigned int buff[1];
    fseek(file_wav,34, SEEK_SET);
    fread(buff, sizeof(unsigned int)/2, 1, file_wav);
    return buff[0];
}
