#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 算法优化:
      运用大佬规律: 大于6的质数与6的倍数相邻
      运用百度规律: 只需用2-根号去除就可以
*/
typedef struct prinum{
  unsigned int num;
  struct prinum* next;
}prinum;
int divisible(unsigned int num,unsigned int by);
void clear(prinum* pri);
inline void addnum(prinum* pir,unsigned int num);
int main()
{
  unsigned int base = 6;
  prinum pri;
  prinum *next = &pri;
  next->next = NULL;
  pri.num = 2;
  addnum(next,3);
  //next = next->next;
  //addnum(next,5);
  next = &pri;
  char fb = '-';
  for(;base < 1000000;base += 6)
  {
    if(fb == '-'){
      base --;
    }
    //printf("开始%d\n",base);
    while(1){
      if(divisible(base,next->num))
      {
        //printf("%d是合数\n",base);
        next = &pri;
        if(fb == '-'){
          base += 2;
          fb = '+';
        }else{
          fb = '-';
          base --;
          break;
        }
      }
      else if(next->num > sqrt(base))
      {
        prinum *newpri = (prinum*)malloc(sizeof(prinum));
        //printf("%d\n",newpri);
        newpri->num = base;
        while(next->next != NULL)
        {
          next = next->next;
        }
        next->next = newpri;
        printf("%d ",base);
        newpri->next = NULL;
        next = &pri;
        newpri = NULL;
        if(fb == '-')
        {
          base +=2;
          fb = '+';
          //printf("%d -\n",base);
        }else{
          base --;
          fb = '-';
          //printf("%d +\n",base);
          break;
        }
        //break;
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
inline void addnum(prinum* pri,unsigned int num)
{
  prinum *newpri = (prinum*)malloc(sizeof(prinum));
  newpri->num = num;
  pri->next = newpri;
  newpri->next = NULL;
  newpri = NULL;
}
