def insertion_sort(a):
    for i in range(1,len(a)):
        value_tosort=a[i]
        while i>0 and a[i-1]>value_tosort:
            a[i-1],a[i]=a[i],a[i-1]
            i=i-1
