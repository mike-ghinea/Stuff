#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream cin("ascii.in");
ofstream cout("ascii.out");
string M;
int main()
{
    int L,H,i,n,j,k;
    cin>>L>>H;
    cin.get();
    getline(cin,M);
    n=M.length();
    for(i=0;i<n;i++)
    {
        if(M[i]<='z' and M[i]>='a')
            M[i]-=32;
        if(!((M[i]<='z' and M[i]>='a') or  (M[i]<='Z' and M[i]>='A')))
            M[i]='?';
    }
    string S;
    for(i=1;i<=H;i++)
    {
        S="";
        getline(cin,S);
        for(j=0;j<n;j++)
        {
            if(M[j]=='?')
            {
                for(k=26*L;k<27*L;k++)
                    cout<<S[k];
            }
            else
            {
                for(k=(M[j]-65)*L;k<(M[j]-65)*L+L;k++)
                    cout<<S[k];
            }
        }
        cout<<'\n';
    }
}
