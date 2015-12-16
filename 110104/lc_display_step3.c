#include<stdio.h>
#include<string.h>
/*显示的大小最大为10*/
#define S 10
/*n的位数最大是8位*/
#define D 8
int main() {
    /*问题测试中还要处理007，所以n必须以字符串的形式读入！*/
    int s;
    char n[D+1];
    int i,j,k;
    char show[2*S+3][D*(S+2)+D-1];
    while(1) {
        /*s是数字显示的大小
         * n是要显示的数字！*/
        scanf("%d%s",&s,n);
	/*printf("s=%d,n=%s\n",s,n);*/
        /*printf("s=%d,n=%d\n",s,n);*/
        int nd=strlen(n);
        if(s==0 && n[0]=='0' && nd==1) {
            break;
        }
        int row=2*s+3;
        int col=(s+2)*nd+nd-1;

        /*printf("row = %d, col = %d\n",row,col);*/

        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                show[i][j]=' ';
            }
        }

        struct point {
            int x;
            int y;
        };
        struct point part[7];
        part[0].x=0;
        part[0].y=1;

        part[1].x=s+1;
        part[1].y=1;

        part[2].x=2*s+2;
        part[2].y=1;

        part[3].x=1;
        part[3].y=0;

        part[4].x=s+2;
        part[4].y=0;

        part[5].x=1;
        part[5].y=s+1;

        part[6].x=s+2;
        part[6].y=s+1;

        /* 0
         *3 5
         * 1
         *4 6
         * 2
         */
        /*
            int on[10][7];
            on[0]= {1,0,1,1,1,1,1};
            on[1]= {0,0,0,0,0,1,1};
            on[2]= {1,1,1,0,1,1,0};
            on[3]= {1,1,1,0,0,1,1};
            on[4]= {0,1,0,1,0,1,1};
            on[5]= {1,1,1,1,0,0,1};
            on[6]= {1,1,1,1,1,0,0};
            on[7]= {1,0,0,0,0,1,1};
            on[8]= {1,1,1,1,1,1,1};
            on[9]= {1,1,1,1,0,1,1};
        */
        int on[10][7];
        on[0][0]=1,on[0][1]=0,on[0][2]=1,on[0][3]=1,on[0][4]=1,on[0][5]=1,on[0][6]=1;
        on[1][0]=0,on[1][1]=0,on[1][2]=0,on[1][3]=0,on[1][4]=0,on[1][5]=1,on[1][6]=1;
        on[2][0]=1,on[2][1]=1,on[2][2]=1,on[2][3]=0,on[2][4]=1,on[2][5]=1,on[2][6]=0;
        on[3][0]=1,on[3][1]=1,on[3][2]=1,on[3][3]=0,on[3][4]=0,on[3][5]=1,on[3][6]=1;
        on[4][0]=0,on[4][1]=1,on[4][2]=0,on[4][3]=1,on[4][4]=0,on[4][5]=1,on[4][6]=1;
        on[5][0]=1,on[5][1]=1,on[5][2]=1,on[5][3]=1,on[5][4]=0,on[5][5]=0,on[5][6]=1;
        on[6][0]=1,on[6][1]=1,on[6][2]=1,on[6][3]=1,on[6][4]=1,on[6][5]=0,on[6][6]=1;
        on[7][0]=1,on[7][1]=0,on[7][2]=0,on[7][3]=0,on[7][4]=0,on[7][5]=1,on[7][6]=1;
        on[8][0]=1,on[8][1]=1,on[8][2]=1,on[8][3]=1,on[8][4]=1,on[8][5]=1,on[8][6]=1;
        on[9][0]=1,on[9][1]=1,on[9][2]=1,on[9][3]=1,on[9][4]=0,on[9][5]=1,on[9][6]=1;

        int r=2*s+3;
        int c=s+2;
        char digit[10][2*S+3][S+2];

        for(i=0; i<10; i++) {
            for(j=0; j<r; j++) {
                for(k=0; k<c; k++) {
                    digit[i][j][k]=' ';
                }
            }
        }
        for(i=0; i<10; i++) {
            /*printf("i=%d\n",i);*/
            for(j=0; j<3; j++) {
                if(on[i][j]==1) {
                    /*printf(" %d",j);*/
                    int sx=part[j].x;
                    int sy=part[j].y;
                    for(k=0; k<s; k++) {
                        digit[i][sx][sy+k]='-';
                    }
                }
            }
            for(j=3; j<7; j++) {
                if(on[i][j]==1) {
                    /*printf(" %d",j);*/
                    int sx=part[j].x;
                    int sy=part[j].y;
                    for(k=0; k<s; k++) {
                        digit[i][sx+k][sy]='|';
                    }
                }
            }
            /*printf("\n");*/
        }
        /*
            for(i=0; i<10; i++) {
                printf("i = %d\n",i);
                for(j=0; j<r; j++) {
                    for(k=0; k<c; k++) {
                        printf("%c",digit[i][j][k]);
                    }
                    printf("\n");
                }
                printf("------------\n");
            }
        */
        /*每一个数字打印都对了，接下来是如何合并！*/
        for(k=0; k<nd; k++) {
            for(i=0; i<r; i++) {
                for(j=0; j<c; j++) {
                    show[i][j+k*(s+2+1)]=digit[n[k]-'0'][i][j];
                }
            }
        }
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                printf("%c",show[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
