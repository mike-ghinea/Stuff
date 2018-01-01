#include<iostream>
#include<vector>
using namespace std;
vector <int>G[10001];
int i,x,y,M,Max,Maxx;
int NR;
int search_(int i)
{
    int Max=0;
    for(int j=0;j<G[i].size();j++)
        Max=max(search_(G[i][j]),Max);
    return Max+1;
}
int main()
{
    cin>>M;
    for(i=1;i<=M;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        Max=max(Max,x);
    }
    for(i=1;i<=Max;i++)
    {
        Maxx=max(search_(i),Maxx);
    }
    cout<<Maxx;
}
