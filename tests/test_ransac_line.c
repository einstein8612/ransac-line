#include "ransac_line.h"   // works now because include/ is in the path

#include <assert.h>
#include <stdio.h>

int main(void) {

    // Test the ransac_line function
    float xs[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float ys[] = {2.0, 3.0, 5.0, 7.0, 11.0};
    int num_points = 5;
    float threshold = 1.0;
    int max_iterations = 10;

    float slope = ransac_line(xs, ys, num_points, threshold, max_iterations);
    printf("Estimated slope: %f\n", slope);
    return 0;
}