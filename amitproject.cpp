#include<stdio.h>
#include<stdlib.h>
#include<String.h>

int main()
{
      int direction=0,count,total,temp,i,j,k=0,n;
     int current,previous;
	 // int queue[]={86,143,1470,913,1774,948,1509,1022,1750,130};   	 
       int queue[50];
         // int n=sizeof(queue)/sizeof(int);
           int seq[50];
         printf("\n\t Enter number of cylinder :\t");
         scanf("%d",&n);
         printf("\n\t Enter postions of cylinders :\n");
         for(i=0;i<n;i++)
         {    printf("\t\t\t");
         	scanf("%d",&queue[i]);
		 }
        printf("\n\t Enter current head position :\t");
        scanf("%d",&current);
        printf("\n\t Enter previous position :\t");
        scanf("%d",&previous);
        for(i=0;i<n;i++)
        {
        	for(j=i+1;j<n;j++)
        	{
        		if(queue[i]>queue[j])
        		{
        			temp=queue[i];
        			queue[i]=queue[j];
        			queue[j]=temp;
				} 
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(queue[i]==current)
			{
				count=i;
				break;
			}
		}
	
		if(previous < current)
	    {
	       direction=0;
	         } 
	   else{
	   	  direction=1;
	            }
	   
	   
	   
	  if(direction==0){
	  
	   	 total=(4999-queue[count])+4999+queue[count-1];
	   	 for(i=count;i<n;i++)
	   	 {
	   	 	seq[k]=queue[i];
	   	 	k++;
			}
			
		 for(i=0;i<count;i++)
		 {
		 	
	   	 	seq[k]=queue[i];
	   	 	k++;
			 }	
	   }
	   else
	   {
	   	
	   	     total=queue[count]+4999+(4999-queue[count+1]);
	   	     for(i=count;i>=0;i--)
	   	     {
	   	     	seq[k]=queue[i];
	   	     	 k++;
				}
			 for(i=n-1;i>count;i--)
			 {
			 	seq[k]=queue[i];
			 	k++;
			 }
	   }
	   
	   printf("\n\t\tThe total distance that the disk arm move :%d\n",total);
	   for(i=0;i<n;i++)
	   {
	   	 printf("%d ",seq[i]);
	   }
}

