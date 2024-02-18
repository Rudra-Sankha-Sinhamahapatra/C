#include <stdio.h> 

struct process { 
	int pid; 
	int at; 
	int bt;
    int remain_time;
    int wt;
    int tat;
    int rt;
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
	int short_process, short_remain_time, curr_time;
	int sum_bt = 0;

	for (i = 0; i < n; i++) { 
		printf("Enter AT and BT for P%d: ", i+1); 
		scanf("%d %d", &a[i].at, &a[i].bt);
		sum_bt += a[i].bt;
		a[i].pid = i+1; 
		a[i].remain_time = a[i].bt;
		a[i].rt = -1;
	}

	for (curr_time = 0; curr_time < sum_bt; curr_time++){
		short_process = -1;
		short_remain_time = 10000;
		for (j = 0; j < n; j++){
			if ((a[j].at <= curr_time) && (a[j].remain_time < short_remain_time) && (a[j].remain_time > 0)){
				short_process = j;
				short_remain_time = a[j].remain_time;
			}
		}
		if (short_process != -1){
			a[short_process].remain_time--;

			// Response Time Calculation
			if(a[short_process].rt==-1){
				a[short_process].rt = curr_time - a[short_process].at;
			}

			// Waiting Time Calculation
			for (int k = 0; k < n; k++){
				if(k!=short_process && a[k].at<=curr_time && a[k].remain_time!=0){
					a[k].wt++;
				}
			}
		}
	}

	// Turn Around Time Calculation
    for (i = 0; i < 5; i++){
        a[i].tat = a[i].wt + a[i].bt;
    }

	display();

	return 0; 
}