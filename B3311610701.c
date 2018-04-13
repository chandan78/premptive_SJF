#include <stdio.h>
int Queue(int t1)
{
if (t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3)
{
return 1;
}

else
{
return 2;
}

}
int main() 
{
      int arrival_time[10], burst_time[10], pid[10],t1[10],priority[10];
      int i,y,count=0,time,tnp;
      int q,ready,p1;
      double wt = 0,tat = 0, end;
      float average_wt, average_tat;
      
	  printf("\nEnter the Total Number of Processes:\t");
      scanf("%d", &tnp); 
      printf("\nEnter Details of %d Processes\n", tnp);
      for(i = 0; i<tnp; i++)
      {
      	    printf("Enter process Id:\t");
            scanf("%d", &pid[i]);
            printf("Enter Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("Enter Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            t1[i] = burst_time[i];
            
            printf("Process Priority:\t");
			scanf("%d", &priority[i]);
			printf("\n");
			p1 = priority[i];
			q = Queue(p1);
			ready = 0;
      }
      printf("\n--------------------------------------\n");
      printf("\nPROCESS DETAILS --\n");
      printf("\n  process Id  \tArrival Time \tBurst Time  \tpriority\n\n");
      for(i = 0; i<tnp; i++)
      {
      	 
      	 printf("\t%d\t\t%d\t\t%d\t\t%d",pid[i],arrival_time[i],burst_time[i],priority[i]);
      	 printf("\n");
     }
      printf("\n-----------------------------------\n");	
      burst_time[9] = 9999;  
      for(time=0;count!=tnp;time++)
      {
            y=9;
            for(i = 0;i<tnp;i++)
            {
                  if(arrival_time[i] <= time && burst_time[i] < burst_time[y] && burst_time[i] > 0)
                  {
                        y = i;
                  }
            }
            burst_time[y]--;
            if(burst_time[y] == 0)
            {
                  count++;
                  end = time + 1;
                  wt=wt+end - arrival_time[y] - t1[y];
                  tat = tat + end - arrival_time[y];
            }
      }
      printf("\nAFTER PREMPTIVE SJF :\n");
      printf("\n\n waiting Time : %lf\t TurnAround Time :%lf\n",wt,tat);
      average_wt = wt / tnp; 
      average_tat = tat /tnp;
      printf("---------------\n");
      printf("Average Waiting Time:\t%lf\n", average_wt);
      printf("Average Turnaround Time:\t%lf\n", average_tat);
      return 0;
}
