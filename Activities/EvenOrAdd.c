#include<stdio.h>
int main()
{
  int no1, no2;
  printf("Insert two numbers:");
  scanf("%d %d",&no1, &no2);
      
 
  if(no1 > no2)
     printf("%d is greatest",no1);
	
 
  else if(no2 > no1)
    printf("%d is greatest",no2);	
 
  else
     printf("%d and %d are equal", no1, no2);

  return 0;
}