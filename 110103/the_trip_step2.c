#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
double student[N];

double with_one_cent(double money) {
	return (int)(money*100)*0.01;
}
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
	average=with_one_cent(average);
    double transaction=0.0;
    for(i=0; i<n; i++) {
        if(student[i]<average) transaction+=(average-student[i]);
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
