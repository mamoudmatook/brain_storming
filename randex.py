import random 
from datetime import datetime

random.seed(datetime.now())

total=0
for l in range(1000):
    sum_of_values = 0
    previous=None
    current=None
    for _ in range(20):
        current=random.choice([0,1])
        if previous==0 and current==1:
            sum_of_values +=1
        previous=current
    total+=sum_of_values
print(total/1000)
