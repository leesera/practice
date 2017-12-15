cacheSize = 0 # number 0 =< size =< 30
cities = ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"] # array of characters, maximum value = 100000, only characters

time = 0
cache = []
for city in cities:
    if (city in cache):
        #hit
        time += 1
        if(len(cache) < cacheSize - 1):
            cache.append(city)
        else:
            cache = [city] + cache.remove(city)
    else :
        time += 5
        if(len(cache) < cacheSize - 1):
            cache.append(city)
        else:
            cache = [city] + cache[:-1]
print(time)




