#include<iostream>
#include<algorithm>
#define DIM 200001
using namespace std;
int v[DIM],N,M,i,t,r;
int main()
{
    cin>>N>>M;
    for(i=1;i<=N;i++)
        cin>>v[i];
    for(i=1;i<=M;i++)
    {
        cin>>t>>r;
        if(t==1)
            sort(v+1,v+r+1);
        else
            sort(v+r+1,v+1);
    }
    for(i=1;i<=N;i++)
        cout<<v[i]<<" ";
}
