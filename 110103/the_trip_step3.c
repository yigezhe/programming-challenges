#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
double student[N];

double base(double money) {
    return (int)(money*100)*0.01;
}
double one_cent(double money) {
    if(money>base(money))return 0.01;
    else if(money>base(money)) return -0.01;
    else return 0.0;
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
    double more=0.0;
    double less=0.0;
    for(i=0; i<n; i++) {
        if(student[i]<average) {
		less+=base(average-student[i])+one_cent(average-student[i]);
	}
	else if(student[i]>average) {
		more+=base(student[i]-average)+one_cent(student[i]-average);
	}
    }
    if(more<less) {
	    printf("%.2lf\n",more);
    } else {
	    printf("%.2lf\n",less);
    }

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
