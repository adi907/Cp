import math
import os
import random
import re
import sys

def kangaroo(x1, v1, x2, v2):
    count=0
    k1=[x1+(i*v1) for i in range(100000)]
    k2=[x2+(i*v2) for i in range(100000)]
    for j in range(len(k1)):
        if k1[j]==k2[j]:
            count+=1
    else:
        count+=0
    if count>0:
        return "YES"
    else:
        return "NO"
                
              

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    x1V1X2V2 = input().split()

    x1 = int(x1V1X2V2[0])

    v1 = int(x1V1X2V2[1])

    x2 = int(x1V1X2V2[2])

    v2 = int(x1V1X2V2[3])

    result = kangaroo(x1, v1, x2, v2)

    fptr.write(result+ '\n')

    fptr.close()
