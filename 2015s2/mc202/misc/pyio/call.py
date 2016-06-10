import os

Input = "code.c"
Executable = Input.split(".")[0] + ""
SharedLibrary = Input.split(".")[0] + ".so"
StdIn

#os.popen("gcc %s -shared -fPIC -o %s" % (Input, SharedLibrary))
os.popen('clang %s -o %s' % (Input, Executable))
print os.popen('./%s "%s"' % (Executable, StdIn)).read()


