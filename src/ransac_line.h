#ifndef _RANSAC_LINE_H_
#define _RANSAC_LINE_H_

float fit(float* xs, float* ys, int num_points, float threshold, int max_iterations, int seed);

#endif