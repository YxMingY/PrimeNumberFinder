#include <stdio.h>
#include <stdlib.h>
void prime(int max)
{
  int* p=(int*)malloc(sizeof(int)*(unsigned int)max);
  int i,n,j;
  for(i=2;i<=max;i++)
  {
    p[i]=1;
  }
  for(n=2;n<=max;n++)
  {
    if(p[n])
    {
      printf("%d\n",n);
      j=n+n;
      while(j<=max)
      {
        p[j]=0;
        j+=n;
      }
    }
  }
  free(p);
  p=NULL;
}
int main()
{
  prime(100000000);
  return 0;
}
