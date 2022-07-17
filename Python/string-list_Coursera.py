#Ques.: Open the file romeo.txt and read it line by line. For each line, split the line into a list of words using the split() method. The program should build a list 
#of words. For each word on each line check to see if the word is already in the list and if not append it to the list. When the program completes, sort and print the 
#resulting words in alphabetical order. You can download the sample data at http://www.py4e.com/code3/romeo.txt

#sol:

fname = input("Enter file name: ")
fh = open(fname)
new_list=list()

for line in fh:
     line=line.rstrip()
     pieces=line.split()
     for i in pieces:
            if i in new_list:
                continue
            else:
                new_list.append(i)
ans1=new_list.sort()
print(new_list)
