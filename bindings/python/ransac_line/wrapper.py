import numpy as np
import numpy.typing as npt

from .ransac_line_ffi import lib, ffi

def fit(xs: npt.NDArray, ys: npt.NDArray, threshold: float = 1.0, max_iters: int = 100) -> float:
    if not isinstance(xs, np.ndarray) or not isinstance(ys, np.ndarray):
        raise TypeError("xs and ys must be NumPy arrays")

    if xs.dtype != np.float32 or ys.dtype != np.float32:
        raise TypeError("xs and ys must be float32 arrays (use .astype(np.float32))")

    if xs.shape != ys.shape:
        raise ValueError("xs and ys must have the same shape")

    n = xs.shape[0]
    xs_c = ffi.cast("float*", ffi.from_buffer(xs))
    ys_c = ffi.cast("float*", ffi.from_buffer(ys))

    return lib.fit(xs_c, ys_c, n, threshold, max_iters)