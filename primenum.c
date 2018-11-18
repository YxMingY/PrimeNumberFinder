#include <stdio.h>
#include <stdlib.h>
typedef struct prinum{
  unsigned int num;
  struct prinum* next;
}prinum;
int divisible(unsigned int num,unsigned int by);
void clear(prinum* pri);
int main()
{
  unsigned int base = 2;
  prinum pri;
  prinum *next = &pri;
  next->next = NULL;
  pri.num = base;
  for(;base < 10000;base++)
  {
    //printf("开始%d\n",base);
    while(1){
      if(divisible(base,next->num))
      {
        //printf("%d是合数\n",base);
        next = &pri;
        break;
      }
      else if(next->next == NULL)
      {
        prinum *newpri = (prinum*)malloc(sizeof(prinum));
        //printf("%d\n",newpri);
        newpri->num = base;
        next->next = newpri;
        printf("%d ",base);
        newpri->next = NULL;
        next = &pri;
        newpri = NULL;
        break;
      }
      else
      {
        //printf("用%d检查%d中\n",next->num,base);
        next = next->next;
      }
      //putchar('\n');
    }
    //putchar('\n');
    //sleep(1);
  }
  putchar('\n');
  clear(next);
  return 0;
}
int divisible(unsigned int num,unsigned int by)
{
  //printf("%d  %d=%d\n",num,by,num%by);
  return (num%by == 0);
}
void clear(prinum* pri)
{
  prinum *temp;
  pri = pri->next;
  while(pri->next != NULL)
  {
    temp = pri;
    pri = pri->next;
    free(temp);
  }
}
