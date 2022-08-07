def sockMerchant(n, ar):
    list1=[]
    dict1={}
    count=0
    for i in ar:
        dict1[i]=dict1.get(i,0)+1
    for j in dict1:
        list1.append(dict1[j])
    for k in range(len(list1)):
        if list1[k]/2>=1:
            count+=int(list1[k]/2)
        else:
            count+=0
    return count
