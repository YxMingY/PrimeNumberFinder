#include <stdio.h>
#include <stdlib.h>
#define true '1'
#define false NULL
void primenum(unsigned int max)
{
  char *p = (char*)malloc(sizeof(char)*max);
  unsigned int i,j;
  /*
  for(i=2;i<=max;i++)
  {
    p[i]=true;
  }
  */
  memset(p,true,max);
  for(i=2;i<=max;i++)
  {
    if(p[i])
    {
      printf("%d ",i);
      for(j=i*2;j<=max;j+=i)
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
