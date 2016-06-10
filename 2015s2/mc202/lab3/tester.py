#!/bin/python

from os import popen as call
from sys import argv

if len(argv) >= 2:
  Script = argv[2]
else:
  Script = "./a.out"

def TestC():
  for Q in range(10):
    for N in range(10):
      Resp = call("echo %s %s 0 | %s" % (Q, N, Script)).read()
      print "(%s, %s): %s" % (Q, N, Resp.split("\n")[0])

  
if __name__ == "__main__":
  TestC()
