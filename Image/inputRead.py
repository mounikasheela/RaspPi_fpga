from scipy import misc
import serial
import time
import numpy as np
import matplotlib.cm as cm
import matplotlib.pyplot as plt
import re
import sys
sys.stdout.flush()

f=misc.imread('sample.bmp')
f1=np.array(f)
f2=np.zeros((np.shape(f1)[0],np.shape(f1)[1]))

for row in range(np.shape(f1)[0]):
    for col in range(0,np.shape(f1)[1]):
        for i in range(3):
          print(f1[row][col][i]);
print(-1)
print(-1)
print(-1)
