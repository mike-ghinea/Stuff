#include <fstream>

using namespace std;
ifstream fin("deque.in");
ofstream fout ("deque.out");
int n,k,v[1001],st,dr,i,dq[1001],s;
int main()
{
   fin>>n>>k;
   for(i=1;i<=n;i++)
   {
       fin>>v[i];
   }
   st=1;
   dr=0;
   for(i=1;i<=n;i++)
   {
       while(dr>=st&&v[i]<v[dq[dr]])
        dr--;
       dq[++dr]=i;
       while(dq[st]<i-k+1)
        st++;
       if(i>=k)
        s+=v[dq[st]];
   }
   fout<<s;
    return 0;
}
