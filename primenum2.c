#include <stdio.h>
#include <stdlib.h>
/* 算法优化:
      运用大佬规律: 大于6的质数与6的倍数相邻
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
  for(;base < 100;base += 6)
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
