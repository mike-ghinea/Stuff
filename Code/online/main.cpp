#include <fstream>
#include <vector>
#include <algorithm>

#define Mdim 10003
#define Ndim 202
using namespace std;
ifstream fin("online.in");
ofstream fout("online.out");
short int DISJ[Ndim],N,M,K,nrk,i,j;
struct strct{short int x,y,c;}V[Mdim];
bool cmp(strct a,strct b)
{
    return a.c<b.c;
}
int root(short int x)
{
    while(DISJ[x]>0)
        x=DISJ[x];
    return x;
}
int kruskal()
{
    short int i,nrm=0;
    int sol=0;
    //sort(V+1,V+nrk+1,cmp);
    for(i=1;i<=N;i++)
        DISJ[i]=-1;
    for(i=1;i<=nrk;i++)
    {
        short int root1=root(V[i].x);
        short int root2=root(V[i].y);
        if(root1!=root2)
        {
            sol+=V[i].c;
            if(DISJ[root1]>DISJ[root2])
                swap(root1,root2);
            DISJ[root1]+=DISJ[root2];
            DISJ[root2]=root1;
            V[++nrm].x=V[i].x;
            V[nrm].y=V[i].y;
            V[nrm].c=V[i].c;
        }
    }
    nrk=nrm;
    return sol;
}
int main()
{
    fin>>N>>M;
    short int a,b,c;
    int sol;
    for(i=1;i<=M;i++)
    {
        fin>>V[i].x>>V[i].y>>V[i].c;
    }
    sort(V+1,V+M+1,cmp);
    nrk=M;
    fout<<kruskal()<<'\n';
    fin>>K;
    for(i=1;i<=K;i++)
    {
        fin>>a>>b>>c;
        bool OK=0;
        for(j=0;j<nrk;j++)
        {
            if((V[j].x==a&&V[j].y==b)||(V[j].x==b&&V[j].y==a))
            {
                if(V[j].c>c)
                {
                    V[j].c=c;
                    while(V[j].c<V[j-1].c)
                    {
                        swap(V[j],V[j-1]);
                        j--;
                    }
                    sol=kruskal();
                    fout<<sol<<'\n';
                    OK=1;
                    break;
                }
                else
                {
                    fout<<sol<<'\n';
                    OK=1;
                    break;
                }
            }
        }
        if(OK==0)
        {
            V[++nrk].x=a;
            V[nrk].y=b;
            V[nrk].c=c;
            j=nrk;
            while(V[j].c<V[j-1].c)
            {
                swap(V[j],V[j-1]);
                j--;
            }
            if(j==0)
                j=1;
            V[j].x=a;
            V[j].y=b;
            V[j].c=c;
            sol=kruskal();
            fout<<sol<<'\n';
        }
    }

    return 0;
}
