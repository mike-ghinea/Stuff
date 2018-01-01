// prof. Daniel Popa
// backtracking

#include <iostream>
#include <fstream>
using namespace std;
int n,k,w,t=0,m=0,i=0;
int v[100];

void bk(int x,int a)
{int i;
 if(x==k){t++; t%=666013;}
 else
 for(i=w;i<=n-a-(k-x-1)*w;i++)
    bk(x+1,a+i);
}
int main()
{
ifstream fin("nmult.in");
ofstream fout("nmult.out");
fin>>n>>k>>w;
do
{t=0;
 i++;
 bk(1,i);
 m+=t;
 m%=666013;
}while(t!=0);
fout<<m;

    return 0;
}
