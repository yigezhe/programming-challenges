#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
double student[N];

double base(double money) {
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
    printf("sum = %lf\n",sum);
    double average=sum/n;
    printf("average = %lf\n",average);
    printf("base average = %lf\n",base(average));

    double transaction1=0.0;
    double transaction2=0.0;
    double transaction3=0.0;
    double transaction4=0.0;
    for(i=0; i<n; i++) {
        if(student[i]<average) {
            transaction1+=base(average-student[i]);
            transaction2+=average-student[i];
        }else if(student[i]>average) {
            transaction3+=base(student[i]-average);
            transaction4+=student[i]-average;
	}

    }
    printf("less %lf\n",transaction1);
    printf("base less %lf\n",transaction2);
    printf("more %lf\n",transaction3);
    printf("base more %lf\n",transaction4);
    printf("\n");
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
