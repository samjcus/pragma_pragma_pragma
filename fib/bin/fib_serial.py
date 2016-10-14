#!/usr/bin/python
from __future__ import print_function
import time


class fibonacci(object):
    """
    object containing method to compute elements of the Fibonacci sequence.
    This implementation utilises a memory to reduce repeated calculation.
    """
    def __init__(self):
        self.memory = {0: 0, 1: 1}

    def fib(self, N):
        if N not in self.memory:
            self.memory[N] = self.fib(N-1) + self.fib(N-2)
        return self.memory[N]


def main():
    for i in range(100, 1000, 100):
        t0 = time.time()
        obj = fibonacci()
        result = obj.fib(i)
        print('iteration {}, time taken = {}s'.format(i, time.time() - t0))

if __name__ == '__main__':
    main()
