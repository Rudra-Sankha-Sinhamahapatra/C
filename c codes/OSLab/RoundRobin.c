#include <stdio.h>

struct process { 
	int pid; 
	int at; 
	int bt;
    int remain_time;
    int wt;
    int tat;
    int rt;
	int prev;
};

struct process a[5];

void avg(){
    float avgwt = 0, avgtat = 0, avgrt = 0;
    for (int i = 0; i < 5; i++){
        avgwt += a[i].wt;
        avgtat += a[i].tat;
        avgrt += a[i].rt;
    }
    avgwt = avgwt / 5;
    avgrt = avgrt / 5;
    avgtat = avgtat / 5;
    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Response Time = %.2f", avgrt);
    printf("\nAverage Turn Around Time = %.2f", avgtat);
}

void display(){
    printf("\n\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tResponse Time\tTurn Around Time");
    for (int i = 0; i < 5;i++){
        printf("\nP%d \t\t%d \t\t%d \t\t%d \t\t%d \t\t%d", a[i].pid, a[i].at, a[i].bt, a[i].wt, a[i].rt, a[i].tat);
    }

    printf("\n");
    avg();
}

int main() { 
	int i, j, n = 5;
	int curr_time = 0;
    int slice = 5;
	int sum_bt = 0;

	for (i = 0; i < n; i++) { 
		printf("Enter AT and BT for P%d: ", i+1); 
		scanf("%d %d", &a[i].at, &a[i].bt);
		sum_bt += a[i].bt;
		a[i].pid = i+1; 
		a[i].remain_time = a[i].bt;
		a[i].rt = -1;
        a[i].wt = 0;
        a[i].prev = a[i].at;
    }

    while(curr_time < sum_bt){
    
		for (j = 0; j < n; j++){
			if ((a[j].at <= curr_time) && (a[j].remain_time > 0)){

                // Response Time Calculation
				if(a[j].rt==-1){
					a[j].rt = curr_time - a[j].at;
				}
                
				if(a[j].remain_time > slice){
					curr_time += slice;
					a[j].remain_time -= slice;
                    a[j].prev = curr_time;
                }
				else{
					curr_time += a[j].remain_time;
					a[j].remain_time = 0;
                    a[j].prev = curr_time;
                }

                // Waiting Time Calculation
                for (int k = 0; k < n; k++){
                    if(k!=j && a[k].at<=curr_time && a[k].remain_time>0){
                        a[k].wt += (curr_time - a[k].prev);
                        a[k].prev = curr_time;
                    }
                }
			}
		}
	}

    // Turn Around Time Calculation
    for (i = 0; i < n; i++)
    {
        a[i].tat = a[i].wt + a[i].bt;
    }

	display();

	return 0; 
}