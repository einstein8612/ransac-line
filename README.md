# ransac-line

This is a repository containing the code for fast line fitting, meant to be used by my [VLP](https://github.com/einstein8612/VLP) project. As such it's highly optimised for this specific case and will not change, unless it improves performance for that case. The API might be a bit weird as a consequence.

# Tests
```bash
$ ./test_all.sh --clean
```

# Usage
```c
#include "ransac_line.h" // Find some way to link it

#include <stdio.h>

int main(void) {
    float xs[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float ys[] = {2.0, 3.0, 5.0, 7.0, 11.0};
    int num_points = 5;
    float threshold = 1.0;
    int max_iterations = 25;

    float slope = ransac_line(xs, ys, num_points, threshold, max_iterations);
    printf("The slope is an estimated %f\n", slope)
    return 0;
}
```