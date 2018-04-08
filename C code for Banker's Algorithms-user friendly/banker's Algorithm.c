//question no.-22 
//Banker's Algorithm to find the system is in safe state or not.
#include<stdio.h>
#include<conio.h>
#include<windows.h>
int p,e;
int cal_need(int max[p][e], int all[p][e],int need[p][e])
{
	int i,j;
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			need[i][j]=max[i][j]-all[i][j];
		}
	}
	return(need[p][e]);
};
int allocation(int all[p][e])
{
	int i,j;
	int al;                                                   // elements of allocation.
	printf("Enter the Elements for allocation");
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			scanf("%d",&al);
			all[i][j]=al;
		}
	}
	return (all[p][e]);
};
int Enter_maximum(int max[p][e])
{
	int i,j;
	int al;                                                   // elements of maximum
	printf("Enter the Elements for maximum");
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			scanf("%d",&al);
			max[i][j]=al;
		}
	}
	return (max[p][e]);
};
int Enter_available(int avail[e])
{
int i;
    int al;                                                   // elements of avail
	printf("Enter the Elements for available");
	for(i=0;i<e;i++){
			scanf("%d",&al);
			avail[i]=al;
		}
	return (avail[e]);	
};
int Enter_processors(int pro[p])
{
int i;
	for(i=0;i<p;i++){
			pro[i]=1;
		}
	return (pro[p]);		
};
void process_check(int all[p][e],int need[p][e],int avail[e],int count,int pro[p])
{
	int i,j,k,l,z,cc=0,inn_count=0;
	for(z=0;z<p;z++){
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			if(pro[i]==1){
				
			    if(avail[j]>=need[i][j]){
				inn_count+=1;
		        }
		    }
			    if(inn_count==e){
			    	pro[i]=0;
				printf("\nProcess P%d executed.",i);
				count+=1;
				for(k=0;k<p;k++){
					avail[k]+=all[i][k];
					//pro[i]=0;
				}
			}
		}
		inn_count=0;
}
}
for(i=0;i<p;i++){
	 cc=cc+pro[i];
}
if(cc==0){
	printf("\n\nSystem is in safe state");
}
else{
	printf("\n\nSystem is not in safe state");
}
};
Disp_allProcess(int all[p][e],int max[p][e],int need[p][e]){
	int i,j;
	printf("Allocation\n");
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			printf("%d ",all[i][j]);
		}
		printf("\n");
	}
	printf("\nMaximum\n");
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			printf("%d ",max[i][j]);
		}
		printf("\n");
	}  
	printf("\nNeed\n");   
	for(i=0;i<p;i++){
		for(j=0;j<e;j++){
			printf("%d ",need[i][j]);
		}
		printf("\n");
	}
};
int main()
{   int i,j,count=-1;
	printf("enter the number of processors you need (size)");
	scanf("%d",&p);
	printf("enter the number of elements in one processor (size of one processor)");
	scanf("%d",&e);
	int all[p][e];
	allocation(all);
	int max[p][e];
	Enter_maximum(max);
	int avail[e];                                              //given available
    Enter_available(avail);
	int pro[p];                                           
	Enter_processors(pro);                               //check every process is executed or not an if it execute the process on sopme index then turn that index no to 0 
	int need[5][4]={0};                                               //calculate need initially it is initialised to 0.
	cal_need(max,all,need);                                     //function call to calulate need.
	Disp_allProcess(all,max,need);
	process_check(all,need,avail,count,pro);
	
	return 0;
}
