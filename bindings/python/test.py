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
