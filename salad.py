import itertools
ll=list()

k=itertools.product(('a','b','c'),repeat=4)
for l in k:
    if not sorted(l) in ll:
        ll.append(sorted(l))
count=0
for m in ll:
    count+=1
    print(m)
print(count)

