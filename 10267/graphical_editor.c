#include<stdio.h>
#define L 20
#define M 250
#define N 250
int main() {
    int pass=1;
    int count=0;
    char g[N][M+1];
    while(1) {
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
        }
	if(!pass) break;
	printf("line %d: %s\n",count+1,line); 
	count++;
    }
    return 0;
}
