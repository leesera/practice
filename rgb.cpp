#include <stdio.h>
#include <stdlib.h>
#define R 0
#define G 1
#define B 2
int * cache; 
int ** color;
int cost(int n, int prev) {
  if(n < 0)
    return 0;
  int tmp,ret;
  int r=color[n][0];
  int g=color[n][1];
  int b=color[n][2];

  switch(prev){
    case R:
      ret = cost(n-1,G)+g;
      tmp = cost(n-1,B)+b;
      if(tmp < ret)
        ret = tmp;
      break;
    case G:
      ret = cost(n-1,R)+r;
      tmp = cost(n-1,B)+b;
      if(tmp < ret)
        ret = tmp;
      break;
    case B:
      ret = cost(n-1,G)+g;
      tmp = cost(n-1,R)+r;
      if(tmp < ret)
        ret = tmp;
      break;
    default:
      ret = cost(n-1,G)+g;
      tmp = cost(n-1,R)+r;
      if(tmp < ret)
        ret = tmp;
      tmp = cost(n-1,B)+b;
      if(tmp < ret)
        ret = tmp;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d",&n);
  int r,g,b;
  int ret=0,tmp;
  color = (int**) calloc(n,sizeof(int*));

  for(int i=0;i<n;i++){
    color[i] = (int*) calloc(3,sizeof(int));
    scanf("%d %d %d",&color[i][0],&color[i][1],&color[i][2]);
  }
  ret = cost(n-1,-1);
  printf("%d\n",ret); 
}
