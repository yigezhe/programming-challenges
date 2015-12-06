#include<stdio.h>
int cycle_length(int n) {
    int count=0;
    while(1) {
        if(n==1) break;
        else {
            if(n%2==0) n=n/2;
            else n=3*n+1;
            count++;
        }
    }
    return count+1;
}
int find(int i,int j) {
    int max=0;
    int k;
    /*我这里的代码假设i比j小，但是这里题目没有做出这种要求！*/
    for(k=i; k<=j; k++) {
        int k_cycle_length=cycle_length(k);
        if(k_cycle_length>max) max=k_cycle_length;
    }
    return max;
}
int main() {
    int i,j;
    /*printf("cycle length %d = %d\n",22,cycle_length(22));*/
    while(scanf("%d%d",&i,&j)!=EOF) {
	    int tmp_i=i;
	    int tmp_j=j;
        if(i>j) {
            //swap i,j
            int tmp=tmp_i;
            tmp_i=tmp_j;
            tmp_j=tmp;
        }
        int max=find(tmp_i,tmp_j);
        printf("%d %d %d\n",i,j,max);
    }
    return 0;
}
