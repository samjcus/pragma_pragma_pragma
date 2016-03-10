from __future__ import print_function,division
import numpy as np
import time

def calc_pi():
    """A crude (even for python) implentation of monte pi
    """
    Nsample=100000000
    x = np.random.rand(Nsample)
    y = np.random.rand(Nsample)
    count = np.sum(np.sqrt(x**2+y**2)<1)
    return 4*count/Nsample
    
if __name__ == '__main__':
    start_t=time.clock()
    pi = calc_pi()
    end_t=time.clock()
    print('pi =',pi)
    print('Time elapsed =',end_t-start_t)

