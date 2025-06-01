#include "ransac_line.h"   // works now because include/ is in the path

#include <assert.h>
#include <stdio.h>

int main(void) {
    // Test the ransac_line function more deeply
    float xs[] = {
        0.0f, 1.0f, 2.0f, 3.0f, 4.0f,
        5.0f, 6.0f, 7.0f, 8.0f, 9.0f
    };
    float ys[] = {
        0.05254269f, 1.6581657f, 2.5178077f, 2.6110625f, 5.214929f,
        6.238758f, 8.113135f, 8.615067f, 8.464788f, 10.893084f
    };
    int num_points = 10;
    float threshold = 1.0;
    int max_iterations = 25;

    float slope = fit(xs, ys, num_points, threshold, max_iterations, 42);
    printf("Estimated slope: %f\n", slope);
    assert(slope > 1.0f && slope < 2.5f); // Expecting a slope close to 1.25...
    return 0;
}