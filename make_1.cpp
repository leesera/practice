#include <stdio.h>
#include <stdlib.h>
#if defined __GNUC__ || defined __APPLE__
#include <ext/hash_map>
using namespace __gnu_cxx;
#else
#include <hash_map>
using namespace stdext;
#endif





//hash_map<int,int> cache;
int* cache;

int count(int n,int cnt){
  if(n<=1)
    return cnt;
  if(cache[n] != 0)
    return cache[n];
  int add=0;
  int ret=0;
  if((n % 3) == 0){
    add = 1 + count(n/3,cnt);
  }
  if((n % 2) == 0){
    ret = 1 + count(n/2,cnt);
    if(add != 0) {
      if(ret < add)
        add = ret;
    } else {
    //if add ==0
      add = ret;
    }
  }
  ret = 1 + count(n-1,cnt);
  if(add != 0) {
    if(ret < add)
      add = ret;
  } else{
    add = ret;
  }
  cache[n] = add;

  return add;
}
int main() {
  int n;
  scanf("%d",&n);
  cache = (int *) calloc(n + 1, sizeof(int));
  int ret = count(n,0);
  printf("%d\n",ret);
}
