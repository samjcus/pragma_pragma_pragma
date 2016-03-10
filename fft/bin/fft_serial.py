from __future__ import print_function
import numpy as np
from numpy.fft import fft

if __name__ == '__main__':
    inarr = np.array([1,1,1,1,0,0,0,0],dtype=np.float)
    out = fft(inarr)
    
    print('inarr =',inarr)
    print('ftt(inarr) =',out)
    print('|fft(inarr)| =',np.abs(out))
