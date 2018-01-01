#include <fstream>

using namespace std;
ifstream fin("coins.in");
ofstream fout("coins.out");
int sol,N;
char VAL[(1<<22)];
char verif(int nr)
{
    int i,frstnull=0,poz=0;
    char OK='2';
    for(i=1;i<=nr;i=(i<<1),poz++)
    {
        if(nr&i==1)
        {
            if(frstnull==0)
            {
                OK='1';
                break;
            }
            if(VAL[nr-i+(1<<frstnull)]==2)
            {
                OK='1';
                break;
            }
        }
        else
            frstnull=poz;
    }
    return OK;
}
void prep()
{
    int i;
    VAL[1]='1';
    for(i=2;i<=(1<<22)-1;i++)
    {
        VAL[i]=verif(i);
    }
}
void read()
{
    fin>>N;
    int x,nr1,a;
    while(N--)
    {
        x=nr1=0;
        for(int i=0;i<22;i++)
        {
            fin>>a;
            if(a==1)
            {
                x+=(1<<i);
                nr1++;
            }
        }
        if(VAL[x]==1)
            sol+=nr1;
    }
}
int main()
{
    prep();
    read();
    for(int i=1;i<=(1<<6)-1;i++)
        fout<<VAL[i]-'0'<<' ';
    return 0;
}
