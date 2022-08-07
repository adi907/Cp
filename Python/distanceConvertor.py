print("Welcome to distance convertor")
print("A)Convert km to miles")
print("B)Convvert miles to km")
x=input("Choose A) or B):")

if x=="A":
    k=float(input("Enter distance in km:"))
    #1km=1mile/1.6093
    m=round(k/1.6093,2)
    if m==1:
        print(k,"km=",m,"mile")
    else:
        print(k,"km=",m,"miles")
else:
    m1=float(input("Enter distance in miles:"))
    #1mile=1km*1.6093
    k1=1.6093*m1
    if m1==1:
        print(m1,"mile=",k1,"km")
    else:
        print(m1,"miles=",k1,"km")
