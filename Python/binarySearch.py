def binary_search(arr,key,start,end):
    mid=int((start+end)/2)
    if a[mid]>key:
        return binary_search(a,key,start,mid-1)
    elif a[mid]<key:
        return binary_search(a,key,mid+1,end)
    else:
        return mid
