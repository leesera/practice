#include <stdio.h>
#include <stdlib.h>

int * cache0;
int * cache1;
int * cache;


int fibonacci(int n);
int check(int n, int* cache,int printable){
  int ret = 0;
  if(cache[n-1])
    ret = cache[n-1];
  else
    if(!printable)
      ret = fibonacci(n-1);
  if(cache[n-2])
    ret += cache[n-2];
  else
    if(!printable)
      ret += fibonacci(n-2);
  if(!cache[n])
    cache[n] = ret;
  return ret;
}

int fibonacci(int n) {
    if (n==0) {
        return 0;
    } else if (n==1) {
        return 1;
    } else {
      int ret;
      ret = check(n, cache,0);
      int zero = check(n,cache0,1);
      int one  = check(n,cache1,1);
      //printf("ret %d zero %d one %d n %d\n",ret,zero,one,n);
      return ret;
    }
}

int main() {
  cache0 =(int*) calloc(40,sizeof(int));
  cache1 = (int*)calloc(40,sizeof(int));
  cache =(int*) calloc(40,sizeof(int));
  cache[0] = 0;
  cache[1] = 1;
  cache0[0] = 1;
  cache0[1] = 0;
  cache1[0] = 0;
  cache1[1] = 1;
  int total;
  scanf("%d",&total);
  for(int i=0;i<total;i++){
    int n;
    scanf("%d",&n);
    fibonacci(n);
    printf("%d %d\n",cache0[n],cache1[n]);
  }
}


