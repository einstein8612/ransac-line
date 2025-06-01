# ransac-line

This is a repository containing the code for fast line fitting, meant to be used by my [VLP](https://github.com/einstein8612/VLP) project. As such it's highly optimised for this specific case and will not change, unless it improves performance for that case. The API might be a bit weird as a consequence. An important feature here, is that it always only returns the slope, as the fit I am aiming for personally is `y = ax`. This can be easily changed and you are welcome to do so yourself.

## Tests
```bash
$ ./test_all.sh --clean
```

## Usage
In order to use it in C you can use the following example.

```c
#include "ransac_line.h" // Find some way to link it

#include <stdio.h>

int main(void) {
    float xs[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float ys[] = {2.0, 3.0, 5.0, 7.0, 11.0};
    int num_points = 5;
    float threshold = 1.0;
    int max_iterations = 25;

    float slope = fit(xs, ys, num_points, threshold, max_iterations);
    printf("The slope is an estimated %f\n", slope)
    return 0;
}
```

## Python Bindings

Python bindings are also provided. You can use the following commands to generate them and use them.

*Note*: using a virtual environment is recommended.

First install the requirements, if you don't already have them:
```bash
$ apt install python3-dev
$ pip install cffi setuptools numpy
```

Then generate the bindings:
```bash
$ cd bindings/python/ransac_line
$ python build_ffi.py
```

Test and install them:
```bash
$ cd ..
$ python test.py
$ pip install -e .
```

### Example

```py
import numpy as np
from ransac_line import fit

from time import time

# 1. Your input data (NumPy arrays)
xs_np = np.array([1.0, 2.0, 3.0, 4.0], dtype=np.float32)
ys_np = np.array([1.1, 2.1, 3.1, 3.9], dtype=np.float32)

# 3. Call the C function
threshold = 0.5
max_iters = 100
now = time()
slope = fit(xs_np, ys_np, threshold, max_iters)

# 4. Use the result
print("Best slope:", slope)
```