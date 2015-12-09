#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
double student[N];

void get_data() {
    int i;
    for(i=0; i<n; i++) {
        scanf("%lf",&student[i]);
    }
}
void deal_data() {
    double sum=0.0;
    int i;
    for(i=0; i<n; i++) {
        sum+=student[i];
    }
    double average=sum/n;
    double transaction=0.0;
    for(i=0; i<n; i++) {
        if(student[i]>average) transaction+=(student[i]-average);
    }
    printf("%.2lf\n",transaction);
}
int main() {

    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        get_data();
        printf("$");
        deal_data();
    }
    return 0;
}
