#Ques: Write a program to read through the mbox-short.txt and figure out the distribution by hour of the day for each of the messages. 
#You can pull the hour out from the 'From ' line by finding the time and then splitting the string a second time using a colon. 
#From stephen.marquard@uct.ac.za Sat Jan 5 09:14:16 2008 Once you have accumulated the counts for each hour, print out the counts, sorted by hour as shown below.

# Sol:

fname = input("Enter file:")
fhand = open(fname)
d= dict()
for lines in fhand:
    if lines.startswith("From"):
        if not lines.startswith("From:"):
             words=lines.split()
             x=words[-2]
             hours=x.split(":")
             d[hours[0]]= d.get(hours[0],0) + 1
                
list1=list()
for a,b in d.items():
     list1.append((a,b))
     list1.sort()
for hours,counts in list1:
    print(hours,counts)
