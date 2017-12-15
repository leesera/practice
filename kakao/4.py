n = 10 #total count
t = 60#batch time?
m = 45#maximum at one time
timetable = ["23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59"]

def parse_time(time):
    hour = int(time[:2])
    minutes = int(time[3:])
    return hour * 60 + minutes
def int_to_time(num):
    hour = num / 60
    minu = num % 60
    if(hour < 12):
        ret = "0"+str(hour)+":"
    else:
        ret = str(hour)+":"
    if(minu < 10):
        ret += "0"+str(minu)
    else:
        ret += str(minu)
    return ret
idx= 0
times = sorted(list(map(lambda x: parse_time(x),timetable)))
print(times)

time = parse_time("09:00")
print(times)
for iii in range(n):
    #each interval
    p = []
    while ((idx < len(timetable) and time>=times[idx]) and len(p) < m ):
        p.append(times[idx])
        idx += 1
        if( idx >= len(timetable)):
            print(idx)
            print("break")
            break
    time = time + t
if(len(p) != m):
    time = time - t
    if(time > parse_time("23:59")):
        time = parse_time("23:59")
else:
    time = sorted(p)[-1] - 1

print(int_to_time(time))





