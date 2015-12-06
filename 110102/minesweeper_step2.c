#include<stdio.h>
#define N 100
#define M 100
int main() {
    int n,m;
    int i,j;
    char fields[M][N];
    int mines[M][N];

    int count=1;
    while(1) {
        scanf("%d%d",&n,&m);
	/*test all input is right!
        printf("n=%d,m=%d\n",n,m);*/
        if(n==0 && m==0) break;
        if(count!=1)printf("\n");
        getchar();/*delete newline after n,m*/
        printf("Field #%d:\n",count);
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                fields[i][j]=getchar();
            }
            getchar();
        }
	/*
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                printf("%c",fields[i][j]);
            }
            printf("\n");
        }
	*/

        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                if(fields[i][j]=='*') mines[i][j]=-1;
                else {
                    mines[i][j]=0;
                    if(i+1<n && fields[i+1][j]=='*') mines[i][j]++;
                    if(j+1<n && fields[i][j+1]=='*') mines[i][j]++;
                    if(i-1>=0 && fields[i-1][j]=='*') mines[i][j]++;
                    if(j-1>=0 && fields[i][j-1]=='*') mines[i][j]++;
                    if(j-1>=0 && i-1>=0 && fields[i-1][j-1]=='*') mines[i][j]++;
                    if(j+1<n && i+1<n && fields[i+1][j+1]=='*') mines[i][j]++;
                    if(j+1<n && i-1>=0 && fields[i-1][j+1]=='*') mines[i][j]++;
                    if(j-1>=0 && i+1<n && fields[i+1][j-1]=='*') mines[i][j]++;
                }
            }
        }
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                if(mines[i][j]==-1)printf("*");
                else printf("%d",mines[i][j]);
            }
            printf("\n");
        }
        count++;
    }
    return 0;
}
