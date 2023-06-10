#include<stdio.h>
#include<conio.h>
void main()
{
   int m,n,i,j,k,key;
   int arr[100];
   printf("Enter the hash table size");
   scanf("%d",&m);
   printf("Enter the number of elements");
   scanf("%d",&n);

   for(j=0;j<m;j++)
   {
     arr[j]=-1;
   }

   for(i=0;i<n;i++)
   {  
      int h;
      printf("Enter element");
      scanf("%d",&key);
      h=key%m;
      while(arr[h]!=-1)
      {
        h=(++h)%m;
      }
      arr[h]=key;
   }  

    for(k=0;k<m;k++)
   {
     printf("%d\t",arr[k]);
   }
}