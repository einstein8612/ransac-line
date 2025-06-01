#include "ransac_line.h"

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

static inline bool is_inlier_fast(float a, float x, float actual_y, float threshold) {
    return fabs(a*x - actual_y) < threshold;
}

static inline int get_random_index(int num_points) {
    return rand() % num_points;
}

static inline int calculate_inliers(float a, float* xs, float* ys, int num_points, float threshold) {
    int inliers_count = 0;
    for (int i = 0; i < num_points; i++) {
        if (is_inlier_fast(a, xs[i], ys[i], threshold)) {
            inliers_count++;
        }
    }
    return inliers_count;
}

static inline float line_basic(float* xs, float* ys, int num_points) {
    // Randomly select two points
    int idx1 = get_random_index(num_points);
    int idx2 = get_random_index(num_points);

    // Ensure idx1 and idx2 are different
    while (idx2 == idx1) {
        idx2 = get_random_index(num_points);
    }

    // Do the line fitting
    float x1 = xs[idx1];
    float y1 = ys[idx1];
    float x2 = xs[idx2];
    float y2 = ys[idx2];
    float slope = (y2 - y1) / (x2 - x1);

    return slope;
}

float ransac_line(float* xs, float* ys, int num_points, float threshold, int max_iterations) {
    // Seed the random number generator with the current time
    srand((unsigned int) time(NULL));

    int best_inliers = 0;
    float best_slope = 0.0f;
    for (int i = 0; i < max_iterations; i++) {
        float slope = line_basic(xs, ys, num_points);

        // Count inliers
        int inliers_count = calculate_inliers(slope, xs, ys, num_points, threshold);

        // Update the best model if this one has more inliers
        if (inliers_count > best_inliers) {
            best_inliers = inliers_count;
            best_slope = slope;
        }
    }

    return best_slope;
}
