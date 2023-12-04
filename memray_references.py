import gc
import sys

from example import get_ranges, set_ranges

if __name__ == "__main__":
    for _ in range(10_000):
        gc.collect()
        a = sys.gettotalrefcount()
        result2 = get_ranges("a")
        my_string = "my_string"
        set_ranges(my_string, result2)
        gc.collect()
        print(sys.gettotalrefcount() - a)
