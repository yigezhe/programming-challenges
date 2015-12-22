/*这个问题对数学相关问题讲得很清楚！*/
/*interface*/
/*interface implementation*/
#include<stdio.h>
int cycle_length(int n) {
    int length=0;
    while(1) {
        length++;
        /*printf("%d\n",n);*/
        if(n==1) {
            break;
        } else if(n%2==1) {
            n=3*n+1;
        } else {
            n=n/2;
        }
    }
    return length;
}
void test_cycle_length() {
    int n=22;
    printf("cycle length = %d\n",cycle_length(n));
}
/*client*/
#include<stdio.h>
int main() {
    /*不考虑优化，先实现整个过程！*/
    int i,j;
    while(scanf("%d%d",&i,&j)==2) {
        int max_cycle_length=0;
        int k;
        for(k=i; k<=j; k++) {
            if(cycle_length(k)>max_cycle_length)
                max_cycle_length=cycle_length(k);
        }
        printf("%d %d %d\n",i,j,max_cycle_length);
    }
    /*test_cycle_length();*/
    return 0;
}
