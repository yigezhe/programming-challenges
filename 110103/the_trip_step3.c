#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
double student[N];

double cent(double money) {
    return (int)(money*100)*0.01;
}
void get_data() {
    int i;
    for(i=0; i<n; i++) {
        scanf("%lf",&student[i]);
    /*fprintf(stderr,"  %lf",student[i]);*/
    }
    /*fprintf(stderr,"\n");*/
}
void deal_data() {
    double sum=0.0;
    int i;
    for(i=0; i<n; i++) {
        sum+=student[i];
    }
    double average=sum/n;
    /*fprintf(stderr,"average = %lf\n",average);*/
    double transaction=0.0;
    double transaction2=0.0;
    int count=0;
    for(i=0; i<n; i++) {
        if(student[i]>average) transaction+=cent(student[i]-average);
	else if(student[i]<average) {
		transaction2+=cent(average-student[i]);
		count++;
	}
	    /*fprintf(stderr,"  %lf",average-student[i]);*/
    }
    /*fprintf(stderr,"\n");*/
    if(count==1) {
		    printf("%.2lf\n",transaction2);
    } else {
		    printf("%.2lf\n",transaction);
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
