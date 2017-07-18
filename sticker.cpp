#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define ALL 2
#define BTM 1
#define TOP 0

int take_sticker(short** cases, int** input,int n, int type) {
  int val;
  if(n < 1)
    return 0;
//  printf("[*] here %d %d %d\n",n,type,(cases[n][type]));
  if(cases[n][type]) {
    return cases[n][type];
  }
  switch(type){
    case BTM:{
               int max = take_sticker(cases,input,n-1,TOP) + input[1][n-1]; // taking
               val = take_sticker(cases, input, n-2, TOP)+input[1][n-2];
               if(max<val)
                 max = val;
               cases[n][BTM] = max;
               return max;
             }
   case TOP: {
               int max = take_sticker(cases,input,n-1,BTM) + input[0][n-1]; // taking
               val = take_sticker(cases, input, n-2, BTM)+input[0][n-2];
               if(max<val)
                 max = val;
               cases[n][TOP] = max;
               return max;
             }
  }
}
int main() {
  int cnt;
  scanf("%d",&cnt);
  for(int i=0;i<cnt;i++){
    int n;
    scanf("%d",&n);
    int** inputs = (int**)malloc(2*sizeof(int*));
    for(int k=0;k<2;k++){
      inputs[k] = (int*) malloc((n+1)*sizeof(int));
      for(int j=0;j<n;j++){
        int number;
        std::cin >> number;
        inputs[k][j] = number;
//        printf("[*] input %d %d %d\n",k,j,number);
      }
    }
    short** cases =  (short**)malloc((n+2)*sizeof(short*));
    for(int k = 0;k < n+2;k++){
      cases[k] = (short*)calloc(2,sizeof(short));
    }
    cases[1][BTM]=inputs[1][0];
    cases[1][TOP]=inputs[0][0];
    inputs[0][n] = 0;
    inputs[1][n] = 0;
    int max = take_sticker((short**)cases,(int**)inputs,(int)n+1,(int)TOP);
    printf("%d\n",max);
  }
}
