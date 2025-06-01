# build_ffi.py
from cffi import FFI

ffibuilder = FFI()

# 1. Declare the C functions we want to use
ffibuilder.cdef("""
    float fit(float* xs, float* ys, int num_points, float threshold, int max_iterations, int seed);
""")

# 2. Link to the actual implementation
ffibuilder.set_source(
    "ransac_line_ffi",
    '#include "ransac_line.h"',
    sources=["../../../src/ransac_line.c"],       # adjust this if needed
    include_dirs=["../../../src"],                # 👈 tells the compiler where to find ransac_line.h
)

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
