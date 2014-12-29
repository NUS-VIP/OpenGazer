import math
import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab

framesperpoint = 40
totalframe=1960
targetframe=20
f=open('target.txt')
l=f.readlines()
j=0
v=0
point=49

for i in range(targetframe,totalframe,framesperpoint):
    n=l[i].split()
    k=[float(x) for x in n]
    a=(k[0]-k[2])*(k[0]-k[2])
    b=(k[1]-k[3])*(k[1]-k[3])
    s=math.sqrt(a+b)
    j=j+s

mean=j/point
for i in range(targetframe,totalframe,framesperpoint):
    n=l[i].split()
    k=[float(x) for x in n]
    a=(k[0]-k[2])*(k[0]-k[2])
    b=(k[1]-k[3])*(k[1]-k[3])
    s=math.sqrt(a+b)
    v=v+(s-mean)*(s-mean)

variance=v/(point-1)
sigma=math.sqrt(variance)

x = np.linspace(-300,700,1000)
plt.plot(x,mlab.normpdf(x,mean,sigma))
plt.grid()

plt.show()
