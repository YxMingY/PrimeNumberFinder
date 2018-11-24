#include <stdio.h>
#include <stdlib.h>
#define true '1'
#define false '\0'
void primenum(unsigned int max)
{
  char *p = (char*)malloc(sizeof(char)*max);
  unsigned int i,j;
  memset(p,true,max);//效果似乎一样啊
  for(i=2;i<=max;i++)
  {
    if(p[i])
    {
      printf("%d ",i);
      for(j=i*i;j<=max;j+=i)
      {
        p[j]=false;
      }
    }
  }
  free(p);
  p=NULL;
}
int main()
{
  primenum(100000000);
  return 0;
}
