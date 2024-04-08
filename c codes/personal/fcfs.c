#include<stdio.h>
#include<stdlib.h>
struct fcfs{
    int arrival;
    int burst;
};
int main(){
    int n;
    printf("enter no of processes");
    scanf("%d",&n);
    struct fcfs *p=(struct fcfs*)malloc(n*sizeof(struct fcfs));
    printf("Enter the arrival time and process time ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].arrival);
        scanf("%d",&p[i].burst);
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(p[j].arrival<p[min].arrival){
                min=j;
            }
        }
        struct fcfs temp=p[min];
        p[min]=p[i];
        p[i]=temp;
    }
    int wt[n],tat[n],rt[n],time=0;
    for(int i=0;i<n;i++){
        wt[i]=time-p[i].arrival;
        tat[i]=wt[i]+p[i].burst;
        rt[i]=wt[i];
        time+=p[i].burst;
    }

}