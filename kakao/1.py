arr1 =[]
arr2 =[]
n = 0
ans = []
for idx in range(n):
    ans.append(arr1[idx] & arr2[idx])

def print_ans(arr):
    ret = []
    for e in arr:
        tmp = format(e,"b")
        tmp = tmp.replace("1","#").replace("0"," ")
        ret.append(tmp)

print_ans(ans)

