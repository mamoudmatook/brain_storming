def count_wins(dice1, dice2):
    import itertools
    assert len(dice1) == 6 and len(dice2) == 6
    dice1_wins, dice2_wins = 0, 0
    for i in itertools.product(dice1,dice2):
      if i[0]>i[1]:
        dice1_wins+=1
      elif i[1]>i[0]:
        dice2_wins+=1
      else:
        continue
          
    
    # write your code here

    return (dice1_wins, dice2_wins)
def find_the_best_dice(dices):
    assert all(len(dice) == 6 for dice in dices)
    best_index=-1
    for i in range(len(dices)):
      better=1
      for j in range(len(dices)):
        if i==j:
          continue
        wins=count_wins(dices[i], dices[j])
        if wins[1]>wins[0]:
          better=0
          break
      if better==1:
        best_index=i
        break
    return best_index



def compute_strategy(dices):
    assert all(len(dice) == 6 for dice in dices)
    best_index=0
    strategy = dict()
    strategy["choose_first"] = True
    l=find_the_best_dice(dices)
    if  l!=-1:
      strategy["first_dice"] = l
      

      
    else:
      strategy["choose_first"] = False
      

      for i in range(len(dices)):

        MMax=0
        for j in range(len(dices)):
          if i==j:
            continue
          l=count_wins(dices[i],dices[j])
          print(l)
          m=l[1]-l[0]
          if m >MMax:
            MMax=m
            best_index=j
        strategy[i]=best_index
            
      
      
   
    
    return strategy
dices=[[4, 4, 4, 4, 0, 0], [7, 7, 3, 3, 3, 3], [6, 6, 2, 2, 2, 2], [5, 5, 5, 1, 1, 1]]
dices2= [[1, 1, 4, 6, 7, 8], [2, 2, 2, 6, 7, 7], [3, 3, 3, 5, 5, 8]]
dice3=[[1, 2, 5, 6, 7, 8], [2, 2, 4, 5, 8, 9], [2, 3, 4, 5, 6, 10]]
print(compute_strategy(dices2))

print(find_the_best_dice(dices2))
