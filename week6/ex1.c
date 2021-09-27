#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int AT;
    int BT;
    int number;
    int CT;
    int TAT;
    int WT;
    int complete;
} process_info;

void sortProcesses(process_info* processes, int n){
    int minPosition;
    process_info tmp;

    for (int i = 0; i < n; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < n; j++)
            if (processes[minPosition].AT > processes[j].AT)
                minPosition = j;
        tmp = processes[minPosition];
        processes[minPosition] = processes[i];
        processes[i] = tmp;
    }

}

int main() {
    int n;
    printf("Enter the number of processes\n");
    scanf("%d", &n);
    process_info processes[n];

    for (int i = 0; i < n; i++){
        printf("Enter the arrival and burst time\n");
        scanf ("%d %d", &processes[i].AT, &processes[i].BT);
        processes[i].number = i;
        processes[i].CT=0;
        processes[i].WT=0;
        processes[i].TAT=0;
        processes[i].complete=0;
    }

    sortProcesses(processes, n);

    processes[0].WT = 0;
    int BT = processes[0].BT;
    processes[0].CT=processes[0].BT;
    int sumTAT = 0;
    int sumWT = 0;

    for (int i = 1; i < n; i++){
        processes[i].WT = processes[0].AT + BT - processes[i].AT;
        BT += processes[i].BT;
    }

    for (int i = 0; i < n; i++) {
        processes[i].TAT = processes[i].BT + processes[i].WT;
        processes[i].CT = processes[i].TAT + processes[i].AT;
        sumTAT+=processes[i].TAT;
        sumWT+=processes[i].WT;
    }

    printf("No   AT   BT   WT   CT   TAT\n");


    for (int i = 0; i < n; i++){
        printf("%d    %d    %d    %d    %d    %d\n", processes[i].number, processes[i].AT, processes[i].BT, processes[i].WT,
               processes[i].CT, processes[i].TAT);
    }


    printf("Average turnaround time is %f\n", ((float )sumTAT/(float) n));
    printf("Average waiting time is %f\n", ((float )sumWT/(float) n));



    exit(EXIT_SUCCESS);
}