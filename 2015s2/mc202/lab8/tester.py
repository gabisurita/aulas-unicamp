import os
import sys
import time

for i in range(1,11):
  os.popen("./a.out < abertos/arq0%s.in > abertos/arq0%s.out" % (i, i))

for i in range(1,11):
  print "Teste %s:" %i
  print os.popen("diff abertos/arq0%s.out abertos/arq0%s.res" % (i,i)).read()
