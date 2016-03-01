#!/usr/bin/python
from __future__ import print_function
import multiprocessing


def thread_task(num):
    """thread worker function"""
    print('Hello, World from thread', num)
    return

if __name__ == '__main__':
    jobs = []
    ncore=multiprocessing.cpu_count()
    for i in range(ncore):
        p = multiprocessing.Process(target=thread_task, args=(i,))
        jobs.append(p)
        p.start()
        p.join()
    print('There are {} threads'.format(ncore))
