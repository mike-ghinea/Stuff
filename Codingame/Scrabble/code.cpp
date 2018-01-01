#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N,i,j,ind;
int viz[28],viz2[28];
int score[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
char w[100001][31];
int x=0,Max=-1;
int value[100001];
char W[31];
char L[7];
int main()
{
    cin>> N; cin.ignore();
    for (i = 1; i <=N; i++) {
        cin>>W;
        x++;
        for(j=0;W[j]!=0;j++)
            w[x][j]=W[j];
        int k=0;
        for(j=0;W[j]!=0;j++)
            k+=score[W[j]-'a'];
        value[x]=k;
    }
    cin>>L;
    for(i=0;L[i]!=0;i++){
        viz2[L[i]-'a']++;
        viz[L[i]-'a']++;}
    for(i=1;i<=x;i++)
    {
        int ok=1;
        for(j=0;w[i][j]!=0;j++)
        {
            if(viz[w[i][j]-'a']>=1)
                viz[w[i][j]-'a']--;
            else
            {
                ok=0;
                break;
            }
        }
        if(ok==1)
        {
            if(Max<value[i])
            {
                Max=value[i];
                ind=i;
            }
        }
        for(j=0;j<=27;j++)
            viz[j]=viz2[j];
    }
    cout<<w[ind];
}
