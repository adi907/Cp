if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    list1=[i for i in arr]
    for i in range(len(list1)):
        for k in range(len(list1)-1):
            if list1[k]>list1[k+1]:
                list1[k],list1[k+1]=list1[k+1],list1[k]
    final_list=[]
    for m in list1:
        if m not in final_list:
            final_list.append(m)
    count=0
    for l in final_list:
        count+=1
    res=final_list[count-2]
    print(res)
