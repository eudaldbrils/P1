#ifndef FIC_WAVE_H
#define FIC_WAVE_H

FILE   *abre_wave(const char *ficWave, float *fm);
size_t lee_wave(void *x, size_t size, size_t nmemb, FILE *fpWave);
void   cierra_wave(FILE *fpWave);
unsigned int mono_channel(FILE *ficWave);
unsigned int bits_per_sample(FILE *ficWave);


#endif	/* FIC_WAV_H	*/
