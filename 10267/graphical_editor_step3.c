#include<stdio.h>
#include<stdlib.h>
#define L 20
#define M 250
#define N 250
int main() {
    int pass=1;
    /*int count=0;*/
    char g[N][M+1];
    int n,m;
    char command;
    char color;
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
            /*printf("x=%d y=%d\n",x,y);*/
            char origin_color=g[x][y];
	    /*printf("origin=%c change to = %c\n",origin_color,color);*/
            /*这样的区域需要用bfs办法来处理！*/
            struct point queue[M*N];
            int start=0;
            int end=0;

            queue[end].x=x;
            queue[end].y=y;
            g[queue[end].y][queue[end].x]=color;
            end++;
            while(start<end) {
		    /*printf("%d < %d\n",start,end);*/
                struct point cur;
                cur.x=queue[start].x;
                cur.y=queue[start].y;
                start++;

                struct point next;
                next.x=cur.x+1;
                next.y=cur.y;
                if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && g[next.y][next.x]==origin_color) {
                    queue[end].x=next.x;
                    queue[end].y=next.y;
                    g[queue[end].y][queue[end].x]=color;
                    end++;
                }
                next.x=cur.x-1;
                next.y=cur.y;
                if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && g[next.y][next.x]==origin_color) {
                    queue[end].x=next.x;
                    queue[end].y=next.y;
                    g[queue[end].y][queue[end].x]=color;
                    end++;
                }
                next.x=cur.x;
                next.y=cur.y-1;
                if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && g[next.y][next.x]==origin_color) {
                    queue[end].x=next.x;
                    queue[end].y=next.y;
                    g[queue[end].y][queue[end].x]=color;
                    end++;
                }
                next.x=cur.x;
                next.y=cur.y+1;
                if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && g[next.y][next.x]==origin_color) {
                    queue[end].x=next.x;
                    queue[end].y=next.y;
                    g[queue[end].y][queue[end].x]=color;
                    end++;
                }
            }
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
