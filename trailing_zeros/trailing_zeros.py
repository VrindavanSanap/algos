from tqdm import tqdm
num_fives_dict = {}
def count_5s(n):
  if n in num_fives_dict:
    return num_fives_dict[n]
  if n == 0:
    num_fives = 0

  elif(n%5 == 0):

    num_fives = 1 + count_5s(n/5)
  else:
    num_fives = 0
  num_fives_dict[n] = num_fives
  return num_fives


total_5s = 0
n = 374960399
for i in tqdm(range(n+ 1)):
  total_5s += count_5s(i)

print(total_5s)
