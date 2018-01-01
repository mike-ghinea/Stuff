#include<iostream>
#include<vector>
using namespace std;
vector <int>G[150001];
bool v[150001];
int i,x,y,M,Max,Maxx;
int NR;
int search_(int i)
{
    int Max=0;
    for(int j=0;j<G[i].size();j++){
        if(v[G[i][j]]==0){
        Max=max(search_(G[i][j]),Max);
        v[G[i][j]]=1;
        }
    }
    return Max+1;
}
int main()
{
    cin>>M;
    for(i=1;i<=M;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        Max=max(Max,max(x,y));
    }
    for(i=0;i<=Max;i++)
    {
        Maxx=min(search_(i),Maxx);
    }
    cout<<Maxx-1;
}
