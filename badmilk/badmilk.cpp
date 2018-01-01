#include<fstream>
using namespace std;
ifstream cin("badmilk.in");
ofstream cout("badmilk.out");
int N,M,D,S,k,i,j,p,P;
struct whop{
    int person,milk,time;
}who[1001],sick[51];
bool m[51][51],matrix[51][51],milky[51],persony[51];
int mm[51];
int main()
{
    cin>>N>>M>>D>>S;
    for(i=1;i<=D;i++)
    {
        cin>>who[i].person>>who[i].milk>>who[i].time;
        m[who[i].person][who[i].milk]=1;
    }
    for(i=1;i<=S;i++)
    {
        cin>>sick[i].person>>sick[i].time;
        persony[sick[i].person]=1;
    }

    for(i=1;i<=S;i++)
    {
        for(j=1;j<=D;j++)
        {
            if(who[j].person==sick[i].person and sick[i].time>who[j].time)
            {
                matrix[who[j].person][who[j].milk]=1;
            }
        }
    }
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            if(matrix[i][j]==0 and persony[i]==1)
                milky[j]=1;
    for(i=1;i<=D;i++)
    {
        if(milky[who[i].milk]==0)
            persony[who[i].person]=1;
    }
    for(i=1;i<=N;i++)
        P+=persony[i];
    cout<<P;
}
