def timeConversion(s):
    if s[0:2]=="12" and s[-2:]=="AM":
        return "00"+s[2:8]
    elif s[-2:]=="AM":
        return s[0:-2]
    elif s[-2:]=='PM'and s[:2]=="12":
        return s[:8]
    else:
        return str(12 + int(s[:2]))+ s[2:8]
