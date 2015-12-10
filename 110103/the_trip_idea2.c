#include<stdio.h>
#include<stdlib.h>
#define N 1000
int n;
int student[N];

void get_data() {
    int i;
    for(i=0; i<n; i++) {
        double data;
        scanf("%lf",&data);
        student[i]=(int)(data*100);
    }
}
void print_data() {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",student[i]);
    }
    printf("\n");
}
void deal_data() {
    long long sum=0;
    int i;
    for(i=0; i<n; i++) {
        sum+=student[i];
    }
    long long average=sum/n;
    /*printf("average = %lld\n",average);*/
    long long transaction=0;
    for(i=0; i<n; i++) {
        if(student[i]<average) {
            /*这是多退少补的意思？*/
            transaction+=(average-student[i]);
            /*printf("+(%lld)",average-student[i]);*/
        }
    }
    /*printf("\n");*/
    printf("%lld.%02lld\n",transaction/100,transaction%100);
}
int main() {

    while(1) {
        scanf("%d",&n);
        if(n==0) break;
        get_data();
        /*print_data() ;*/
        printf("$");
        deal_data();
    }
    return 0;
}
