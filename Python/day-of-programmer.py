#The %s operator lets you add a value into a Python string. The %s signifies that you want to add a string value into a string. Here %s signifies the part where the 
#string needs to add a variable value. And the variable is specified after the inverted commas as %year

def dayOfProgrammer(year):
    if year<1918:
        if year%4==0:
            return '12.09.%s' %year
        else:
            return '13.09.%s' %year
    elif year==1918:
        return "26.09.1918"
    else:
        if year%400==0:
            return '12.09.%s' %year
        elif year%4==0 and year%100!=0:
            return '12.09.%s' %year
        else:
            return '13.09.%s' %year
