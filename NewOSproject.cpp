#include<stdio.h>
#include<stdlib.h>
#include<String.h>

struct process
{
	int bt,at,rbt;
	int pid;
};

struct process *ptr1;
int a=0,i=0,n,quantum;
void calculation(void )
{
	int count,remain,flag=0,wt=0,trt=0,time=0;
	remain=a;
	
	printf("\n\nQuery\t| Queries handling time| Waiting time\n\n");
	for(time=0,count=0;remain!=0;)
	{
		if(((ptr1+count)->rbt <= quantum)&&((ptr1+count)->rbt >0))
		{
			time=time+ (ptr1+count)->rbt;
			(ptr1+count)->rbt=0;
			flag=1;
		}
		else if((ptr1+count)->rbt >0)
		{
			(ptr1+count)->rbt -=quantum;
			time=time+quantum;
		}
		if((ptr1+count)->rbt ==0 && flag==1)
		{
			remain--;
			printf("P%d\t |\t %d\t |\t %d \n",(ptr1+count)->pid,time-((ptr1+count)->at),time-((ptr1+count)->at)-((ptr1+count)->bt));
			wt=wt+time-((ptr1+count)->at)-((ptr1+count)->bt);
			trt=trt +time-((ptr1+count)->at);
			flag=0;
		}
		if(count==a-1)
		    count=0;
		else if((ptr1+count+1)->at <=time)
		    count++;
		else
		    count=0;
	}
	printf("\n\n\tAverage waiting time = %f\n",wt*1.0/a);
	printf("\tAverage queries time = %f\n",trt*1.0/a);
}
int main()
{
	int k,j,temp;
	
	printf("\n\tEnter total number of queries :\t");
	scanf("%d",&n);
	printf("\n\t Enter time quantum :\t");
	scanf("%d",&quantum);
	ptr1=(struct process *)malloc(n*sizeof(struct process));
	
	for(;i<n;)
	{
            printf("\n\n");
            printf("****ENTER DETAIL OF P%d PROCESS****",i+1); 
			printf("\n\tEnter Arrival time :\t");
			scanf("%d",&(ptr1+a)->at);
			
			printf("\tEnter resolving time  :\t");
			scanf("%d",&(ptr1+a)->bt);
			(ptr1+a)->rbt=(ptr1+a)->bt;
			(ptr1+a)->pid=a+1;
			a++;
		i++;	
		}
	
	
	//-----------------------------------------------------------------

	
	      for(k=0;k<n;k++)
	      {
	      	for(j=k+1;j<n;j++)
	      	{
			  
			  if((ptr1+k)->bt > (ptr1+j)->bt)
			  {
			  	 temp=(ptr1+k)->bt;
			  	 (ptr1+k)->bt=(ptr1+j)->bt;
			  	 (ptr1+j)->bt=temp;
			  	
			  	
			  	
			  	 temp=(ptr1+k)->at;
			  	 (ptr1+k)->at=(ptr1+j)->at;
			  	 (ptr1+j)->at=temp;
			  	 
			  	 
			  	 
			  	 temp=(ptr1+k)->rbt;
			  	 (ptr1+k)->rbt=(ptr1+j)->rbt;
			  	 (ptr1+j)->rbt=temp;
			  	 
			  	 
			  	 temp=(ptr1+k)->pid;
			  	 (ptr1+k)->pid=(ptr1+j)->pid;
			  	 (ptr1+j)->pid=temp;
			  }
		    }
	      }
	
    ----------------------------------------------------------------	
		
		
		calculation();
}
