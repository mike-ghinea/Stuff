#include<fstream>
#include<algorithm>
#define MOD 30211
using namespace std;
ifstream cin("carry.in");
ofstream cout("carry.out");
string n;
int N,K,i;
int main()
{
    cin>>N>>K;
    cin>>n;
    reverse(n.begin(),n.end());
    long long sol1,sol2,sol=1;
    for(i=0;i<N;i++)
    {
        sol1=n[i]-'0';
        sol2=10-n[i]+'0';
        if(N-i<=K)
        {
            if(N-i+1<=K)
                sol*=sol1+1;
            else
                sol*=sol1;
            sol%=MOD;
        }
        else
        {
            sol*=sol2;
            sol%=MOD;
        }
    }
    cout<<sol;
}
