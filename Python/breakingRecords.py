def breakingRecords(scores):
    count1=scores[0]
    count2=scores[0]
    max1=0
    min1=0
    for i in range(len(scores)):
        if scores[i]>count1:
            count1=scores[i]
            max1+=1
        else:
            max1+=0

    for j in range(len(scores)):
        if scores[j]<count2:
            count2=scores[j]
            min1+=1
        else:
            min1+=0
    return max1,min1
