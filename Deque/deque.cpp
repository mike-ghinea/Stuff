#include <fstream>
using namespace std;
ifstream cin("deque.in");
ofstream cout("deque.out");
int n,k,a[5000001],dq[5000001],f=1,s=0,i;
long long sum;
int main()
{
    cin>>n>>k;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<=n;i++)
    {
        while(f<=s&&a[i]<=a[dq[s]])
            s--;
        s++;
        dq[s]=i;
        if(dq[f]==i-k)
            f++;
        if(i>=k)
            sum+=a[dq[f]];
    }
    cout<<sum;
    return 0;
}
