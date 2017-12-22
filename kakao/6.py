def printMat(arrs):
    for arr in range(len(arrs)):
        for a in range(len(arrs[arr])):
            print(" %s" % (arrs[arr][a]) ),
        print
    print
def shuffle(state,arrs):
    for x in range(len(state)):
        sarr = state[x]
        earr = arrs[x]
        idx = 0
        for t in range(len(sarr)):
            if(sarr[idx] == 0):
                sarr.pop(idx)
                sarr += [-1]
                earr.pop(idx)
                earr += [" "]

            else:
                idx +=1

def isvalid(idxs,arr,m,n):
    x=idxs[0]
    y=idxs[1]
    if(x+1 >= n):
        return False
    if(y+1 >= m):
        return False
    target = arr[x][y]
    if(target == " "):
        return False
    if(target != arr[x+1][y] or target != arr[x+1][y+1] or target != arr[x][y+1]):
        return False
    return True

def remove(idxs,state):
    x=idxs[0]
    y=idxs[1]
    state[x][y] = 0
    state[x+1][y] = 0
    state[x+1][y+1] = 0
    state[x][y+1] = 0
m = 6#height
n = 6#width -> one array

state = [[1 for i in range(m)] for j in range(n)]
input_arr =    ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]
arr = [[0 for i in range(m)] for j in range(n)]
for i in range(len(input_arr)):
    a = list(input_arr[i])
    for idx in range(len(a)):
        arr[idx][len(input_arr) - 1 - i] = a[idx]
removed = None
cnt = 0
printMat(arr)
while(removed != 0):
    removed = 0
    for x in range(n):
        for y in range(m):
            if(isvalid([x,y],arr,m,n)):
                remove([x,y],state)
                removed += 1
                


    for x in range(n):
        for y in range(m):
            if(state[x][y] == 0):
                cnt += 1
    shuffle(state,arr)
    printMat(arr)

    print("[*] removed %d" % removed)
print(cnt)
