count=0
for i in range(10):
    for j in range(10):
        for k in range(10):
            for l in range(10):
                if i>=j and j>=k and k>=l:
                    count+=1
print(count)
