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
