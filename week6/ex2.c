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
            if (processes[minPosition].BT > processes[j].BT)
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

    int time = 0;
    int complete_processes = 0;
    int sumTAT = 0;
    int sumWT = 0;
    int cycle = 0;


    while (complete_processes<n){
        for (int i = 0; i < n; i++){
            if (processes[i].AT<=time && !processes[i].complete && !cycle){
                time+=processes[i].BT;
                processes[i].CT = time;
                processes[i].TAT = processes[i].CT - processes[i].AT;
                processes[i].WT = processes[i].TAT - processes[i].BT;
                processes[i].complete = 1;
                complete_processes++;
                cycle = 1;
            }
        }
        cycle = 0;
    }

    for (int i = 0; i < n; i++) {
        sumTAT+=processes[i].TAT;
        sumWT+=processes[i].WT;
    }

    printf("No   AT   BT   WT   CT   TAT\n");


    for (int i = 0; i < n; i++){
        printf("%d    %d    %d    %d    %d    %d\n", processes[i].number, processes[i].AT, processes[i].BT, processes[i].WT, processes[i].CT, processes[i].TAT);
    }


    printf("Average turnaround time is %f\n", ((float )sumTAT/(float) n));
    printf("Average waiting time is %f\n", ((float )sumWT/(float) n));



    exit(EXIT_SUCCESS);
}