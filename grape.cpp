#include <stdio.h>
#include<queue>
#include <stdlib.h>
using namespace std;
int cnt(int* cases,int* input, int n) {
  if(n < 0)
    return 0;
  if(cases[n] != 0)
    return cases[n];
  int max=0;
  int case_ = cnt(cases,input,n-1);
  if(max < case_)
    max = case_;
  case_ = cnt(cases,input,n-2) + input[n];
  if(max < case_)
    max = case_;
  case_ = cnt(cases,input,n-3) + input[n]+input[n-1];
  if(max < case_)
    max = case_;
  cases[n] = max;
  return max;
}

  
int main () {
  int n;
  scanf("%d",&n);
  int* cases = (int *)calloc(n,sizeof(int));
  int* inputs =(int *)calloc(n,sizeof(int));
  int input;
  for(int i=0;i<n;i++) {
    scanf("%d",&input);
    inputs[i] = input;
  }

  cases[0] = (int)inputs[0];
  cases[1] = (int)inputs[0] + inputs[1];
  printf("%d",cnt(cases,inputs,n-1));
}
