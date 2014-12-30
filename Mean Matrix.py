import math
f=open('target.txt')
l=f.readlines()
file=open('Mean.txt','w')
k=0
for i in range(0,1960,40):
     for j in range(0,40):
             n=l[i+j].split()
             s=[float(x) for x in n]
             a=(s[0]-s[2])*(s[0]-s[2])
             b=(s[1]-s[3])*(s[1]-s[3])
             c=math.sqrt(a+b)
             k=c+k
     mean=k/40
     file.write(str(mean))
     file.write("\n")
     k=0

file.close()
