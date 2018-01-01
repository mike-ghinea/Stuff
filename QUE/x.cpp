#include <stdio.h>
using namespace std;
int N,T,i;
unsigned char C1,C2,C3,a,b;
const unsigned char zero='0';
const unsigned char n='\n';
int main()
{
    FILE *fin=fopen("staropramen.in", "r");
    FILE *fout=fopen("staropramen.out", "w");
    fscanf(fin,"%d",&T);
    for(int t=0;t<T;t++)
    {
        fscanf(fin,"%d",&N);
        fscanf(fin,"%c");
        for(int i=0;i<N;i++)
        {
            fscanf(fin,"%c%c",&a,&b);
            if(a==n or b==n)
                break;
            int x=a-zero;
            int y=b-zero;
            C3*=10;
            C3+=(x+y);
        }
        fprintf(fout,"%d",C1*256*256+C2*256+C3);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
