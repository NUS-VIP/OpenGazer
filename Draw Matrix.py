import numpy
import matplotlib.pylab as plt
m = "The matix got from several attemps"
matrix = numpy.matrix(m)
fig = plt.figure()
ax = fig.add_subplot(1,1,1)
ax.set_aspect('equal')
plt.imshow(matrix, interpolation='nearest', cmap=plt.cm.ocean)
plt.colorbar()
plt.show()
