input = "1D2S3T*"
mapping = {"S":1,"D":2,"T":3}
prev = 0
total = 0
while input != "" :
    if(input[1] == "0"):
        num = 10
        cnt = mapping[input[2]] 
        idx = 3 
    else:
        num = int(input[0])
        cnt = mapping[input[1]] 
        idx = 2
    tmp = num ** cnt
    if(len(input) > idx):
        opt = input[idx]
        if opt == "*":
            total += prev + 2 * tmp
            prev = 2 * tmp
            input = input[idx+1:]
        elif opt == "#":
            prev = -1 * tmp
            total -= tmp
            input = input[idx+1:]
        else:
            total += tmp
            input = input[idx:]
            prev = tmp
    else:
        total += tmp
        input = input[idx:]
        prev = tmp
print(total)

    
    
