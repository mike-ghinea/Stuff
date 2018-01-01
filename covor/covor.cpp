#include<bits/stdc++.h>
#define DIM 2001
using namespace std;
ifstream input("covor.in");
ofstream output("covor.out");
string line;
bool Matrix[DIM];
short H[DIM],N,i,j,STV[DIM];
int SUM[DIM],sol,vf;
int main()
{
    input>>N;
    for(i=1;i<=N;i++)
    {
        memset(SUM,0,sizeof(SUM));
        vf=0;
        input>>line;
        for(j=1;j<=N;j++)
        {
            H[j]=(line[j-1]=='0')?(H[j]+1):0;
            while(H[STV[vf]]>=H[j] and vf>0)
                vf--;
            STV[++vf]=j;
            SUM[j]=H[j]*(STV[vf]-STV[vf-1])+SUM[STV[vf-1]];
            sol+=SUM[j];
        }
    }
    output<<sol;
}
