import os
import sys
import time

for i in range(1,11):
  os.popen("./a.out < arq0%s.in > arq0%s.out" % (i, i))

for i in range(1,11):
  print "Teste %s:" %i
  print os.popen("diff arq0%s.out arq0%s.res" % (i,i)).read()
