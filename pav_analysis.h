#ifndef PAV_ANALYSIS_H
#define PAV_ANALYSIS_H

float compute_power(const float *x, unsigned int N);
float compute_am(const float *x, unsigned int N);
float compute_zcr(const float *x, unsigned int N, float fm);
float compute_power_window(const float *x, unsigned int N, const float *ventana);

#endif	/* PAV_ANALYSIS_H	*/
