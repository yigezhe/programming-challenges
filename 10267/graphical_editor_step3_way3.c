#include<stdio.h>
#include<stdlib.h>
#define L 20
/*udebug上数据测试的结果是，文件名应该可以是任意长度！
 * 我需要使用可以扩展的文件名！*/
#define M 250
#define N 250
char g[N][M+1];
int n,m;
char origin_color;
char color;
void fill_region(int x,int y) {
    g[y][x]=color;
    int nx=x+1;
    int ny=y;
    if(nx>=0 && nx<m && ny>=0 && ny<n && g[ny][nx]==origin_color) {
        fill_region(nx,ny);
    }
    nx=x-1;
    ny=y;
    if(nx>=0 && nx<m && ny>=0 && ny<n && g[ny][nx]==origin_color) {
        fill_region(nx,ny);
    }
    nx=x;
    ny=y-1;
    if(nx>=0 && nx<m && ny>=0 && ny<n && g[ny][nx]==origin_color) {
        fill_region(nx,ny);
    }
    nx=x;
    ny=y+1;
    if(nx>=0 && nx<m && ny>=0 && ny<n && g[ny][nx]==origin_color) {
        fill_region(nx,ny);
    }
}
int main() {
    int pass=1;
    /*int count=0;*/
    char command;
    int i,j;
    struct point {
        int x;
        int y;
    };
    while(1) {
        /*这里的问题是，我没有做边界检查！*/
        char line[L];
        int nline=0;
        while(1) {
            char c=getchar();
            if(c==EOF) {
                pass=0;
                break;
            } else if(c=='\n') {
                line[nline]='\0';
                break;
            } else {
                line[nline]=c;
                nline++;
            }
            if(nline>=L) {
                printf("我设想的内存空间不够！");
            }
        }
        if(!pass) break;
        /*printf("line %d: %s\n",count+1,line);*/
        if(line[0]=='I') {
            /*创建一个N行M列的table！
             * 所有像素点都是白色！*/
            sscanf(line,"%c %d %d",&command,&m,&n);
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    g[i][j]='O';
                }
            }
        } else if(line[0]=='C') {
            /*把所有像素点都变为白色！*/
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    g[i][j]='O';
                }
            }
        } else if(line[0]=='L') {
            int x,y;
            sscanf(line,"%c %d %d %c",&command,&x,&y,&color);
            y--,x--;/*start from zero*/
            g[y][x]=color;
        } else if(line[0]=='V') {
            int x,y1,y2;
            sscanf(line,"%c %d %d %d %c",&command,&x,&y1,&y2,&color);
            y1--,y2--,x--;/*start from zero*/
            /*吸取上一次的教训！*/
            if(y1>y2) {
                int tmp=y1;
                y1=y2;
                y2=tmp;
            }
            for(i=y1; i<=y2; i++) {
                g[i][x]=color;
            }
        } else if(line[0]=='H') {
            int x1,x2,y;
            sscanf(line,"%c %d %d %d %c",&command,&x1,&x2,&y,&color);
            x1--,x2--,y--;/*start from zero*/
            /*吸取上一次的教训！*/
            if(x1>x2) {
                int tmp=x1;
                x1=x2;
                x2=tmp;
            }
            for(i=x1; i<=x2; i++) {
                g[y][i]=color;
            }
        } else if(line[0]=='K') {
            int x1,x2,y1,y2;
            sscanf(line,"%c %d %d %d %d %c",&command,&x1,&y1,&x2,&y2,&color);
            x1--,x2--,y1--,y2--;/*start from zero*/
            /*吸取上一次的教训！*/
            if(x1>x2) {
                int tmp=x1;
                x1=x2;
                x2=tmp;
            }
            if(y1>y2) {
                int tmp=y1;
                y1=y2;
                y2=tmp;
            }
            for(i=x1; i<=x2; i++) {
                for(j=y1; j<=y2; j++) {
                    g[j][i]=color;
                }
            }
        } else if(line[0]=='F') {
            int x,y;
            sscanf(line,"%c %d %d %c",&command,&x,&y,&color);
            /*printf("x=%d y=%d\n",x,y);*/
            y--,x--;/*start from zero*/
            origin_color=g[y][x];
            fill_region(x,y);
            /*printf("x=%d y=%d\n",x,y);*/
            /*printf("origin=%c change to = %c\n",origin_color,color);*/
            /*这样的区域需要用bfs办法来处理！*/
        } else if(line[0]=='S') {
            char name[L];
            sscanf(line,"%c %s",&command,name);
            printf("%s\n",name);
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    printf("%c",g[i][j]);
                }
                printf("\n");
            }
            /*printf("---------\n");*/
        } else if(line[0]=='X') {
            exit(0);/*?*/
        }
        /*
            count++;
            for(i=0; i<n; i++) {
                for(j=0; j<m; j++) {
                    printf("%c",g[i][j]);
                }
                printf("\n");
            }
        */
    }
    return 0;
}
