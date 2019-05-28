def compute_strategy(dices):
    assert all(len(dice) == 6 for dice in dices)
    best_index=0
    MMax=0
    strategy = dict()
    strategy["choose_first"] = True
    strategy["first_dice"] = 0
    l=find_the_best_dice(dices)
    if  l!=-1:
      strategy["first_dice"] = l
      
    else:
      for i in dices:
        for j in dices:
          if i==j:
            continue
          l=find_the_best_dice(dices[i],dices[j])
          m=l[1]-l[0]
          if m >MMax:
            MMax=m
            best_index=j
        strategy[i]=best_index
            
      
      
   
    
    return strategy
