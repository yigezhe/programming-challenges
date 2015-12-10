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
    /*printf("sum = %lf\n",sum);*/
    double average=sum/n;
    /*printf("average = %lf\n",average);
    printf("base average = %lf\n",base(average));*/

    int more=0;
    int less=0;
    int equal=0;

    for(i=0; i<n; i++) {
        if(student[i]<average) {
            if(average-student[i]- base(average-student[i])>0)
                less++;

        } else if(student[i]>average) {
            if(student[i]-average- base(student[i]-average)>0)
                more++;
        }else {
		equal++;
	}

    }
    int cent=abs(more-less)-equal;
    double res1=0.0;
    double res2=0.0;
    double res=0.0;
    for(i=0;i<n;i++) {
	    if(student[i]>average) {
		    res1+=student[i]-average;
	    }else if(student[i]<average) {
		    res2+=average-student[i];
	    }
    }
    if(res1>res2) res=res2+cent*0.01;
    else  res=res1+cent*0.01;
    printf("%.2lf\n",res);
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
