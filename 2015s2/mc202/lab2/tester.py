import numpy as np


H = 200
W = 200

Out = open("test.in", "w")


Mat = [["." for i in range(W)] for j in range(W)]

Arr = np.array(Mat)

Arr[0][:] = "*"
Arr[-1][:] = "*"

for i in range(W):
  Arr[i][0] = "*"
  Arr[i][-1] = "*"


for i in range(50):
  Arr[i][i-1] = "*"



print(Arr)



Out.write("%s %s\n" % (H, W))

for Line in Arr:
  Out.write("".join(Line) + "\n")
