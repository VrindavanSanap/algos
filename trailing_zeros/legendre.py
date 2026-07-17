from time import time
st = time()
def count_total_fives_legendre(n):
    total_5s = 0
    power_of_5 = 5
    
    while n >= power_of_5:
        total_5s += n // power_of_5
        power_of_5 *= 5
        
    return total_5s

n = 374960399
print(count_total_fives_legendre(n))
print(time() - st)
