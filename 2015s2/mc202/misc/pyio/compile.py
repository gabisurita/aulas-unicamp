import numpy

def combxortransform(x):
  def com2(n):
    return n*(n-1)/2
  
  c= len(x[0])
  Nx = np.zeros(len(x)*com2(com2(c)), dtype=bool)
  Nx.shape = (len(x), com2(com2(c)))
  
  for i in np.arange(len(x)):
    print i
    Xl = np.zeros(com2(c), dtype=bool)
    for Comb, j in zip(it.combinations(x[i],2), np.arange(com2(c))):
      Xl[j] = Comb[0] ^ Comb[1]
    
    Xin = np.zeros(com2(com2(c)), dtype=bool)
    for Comb, j in zip(it.combinations(Xl,2), np.arange(com2(com2(c)))):
      Xin[j] = Comb[0] ^ Comb[1]
      
    Nx[i] = Xin

