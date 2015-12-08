#include<stdio.h>
#define N 100
#define M 100
int n,m;
char fields[M][N];
int mines[M][N];
/*竞赛题目适合建立全局变量！*/
/*我觉得整个程序必须建立一个好的结构！*/

void get_data() {
    getchar();/*delete newline after n,m*/
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            fields[i][j]=getchar();
        }
        getchar();
    }
}
void print_data() {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",fields[i][j]);
        }
        printf("\n");
    }
}
void deal_data() {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            mines[i][j]=0;
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            /*如果fields[i][j]=="*"那么它周围的点都可以统计出一个雷，
             * 我就直接加加来处理！*/
            if(fields[i][j]=='*') {
		    /*这里就是j必须在m范围内而不是在n的范围内！*/
                if(i+1<n) mines[i+1][j]++;
                if(j+1<m) mines[i][j+1]++;
                if(i-1>=0) mines[i-1][j]++;
                if(j-1>=0) mines[i][j-1]++;
                if(j-1>=0 && i-1>=0) mines[i-1][j-1]++;
                if(j+1<m && i+1<n) mines[i+1][j+1]++;
                if(j+1<m && i-1>=0) mines[i-1][j+1]++;
                if(j-1>=0 && i+1<n) mines[i+1][j-1]++;
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(fields[i][j]=='*')printf("*");
            else printf("%d",mines[i][j]);
        }
        printf("\n");
    }
}



int main() {

    int count=1;
    while(1) {
        scanf("%d%d",&n,&m);
        /*test all input is right!
            printf("n=%d,m=%d\n",n,m);*/
        if(n==0 && m==0) break;
        get_data();
        /*print_data();*/
        if(count!=1)printf("\n");
        printf("Field #%d:\n",count);
        deal_data();
        count++;
    }
    return 0;
}
