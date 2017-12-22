def count(arr, e):
    tmp = 0
    for el in arr:
        if(el == e):
            tmp += 1

    return tmp

def remove(arr,e):
    return list(filter(lambda a: a != e, arr))
def split2 (string):
    if(len(string) < 2):
        return [string]
    ret = []
    tmp = string
    while(len(tmp) > 1):
        ret.append((tmp[:2]).lower())
        tmp = tmp[1:]
    return ret


def isvalid(string):
    ret = True
    for s in list(string):
        if(ord("a") <= ord(s) <= ord("z")):
            ret &= True
        else:
            ret &= False
    return ret



def same (arr1, arr2):
    ret = 0 
    tmp_arr1 = list(arr1)
    tmp_arr2 = list(arr2)
    while(len(tmp_arr1) != 0):
        target = tmp_arr1[0]
        cnt1 = count(tmp_arr1,target)
        cnt2 = count(tmp_arr2,target)
        
        tmp_arr1 = remove(tmp_arr1,target)
        if(cnt2 == 0):
            next
        else:
            ret += min(cnt1,cnt2)
    return ret

def all (arr1,arr2):
    ret = 0 
    tmp_arr1 = list(arr1)
    tmp_arr2 = list(arr2)
    while(len(tmp_arr1) != 0):
        target = tmp_arr1[0]
        cnt1 = count(tmp_arr1,target)
        cnt2 = count(tmp_arr2,target)
        if(cnt2 == 0):
            ret += cnt1
        else:
            ret += max(cnt1,cnt2)
        tmp_arr1 =remove(tmp_arr1,target)
        tmp_arr2 = remove(tmp_arr2,target)
    ret += len(tmp_arr2) 
    return ret


str1 = "FRANCE"
str2 = "french"

arr1 = list(filter(lambda x: isvalid(x),split2(str1)))
arr2 = list(filter(lambda x: isvalid(x),split2(str2))) 
print(arr1)
print(arr2)
s = same(arr1,arr2)
print(s)
a = all(arr1,arr2)
print(a)
print(int( float(same(arr1,arr2)) / float(all(arr1,arr2)) * 65536 ))



