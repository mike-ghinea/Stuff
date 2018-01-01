#include<iostream>
using namespace std;
int primes[]={2,3,5,7,11,13,17};//there's lots of primes, too lazy to write them all
int VN[20];
int VM[20];
int main()
{
    int N,M,K=6,i;

    cin>>N>>M;
    //we take N, an integer and compute its factorization
    //Suppose primes, has all the prime numbers in it
    for(i=0;i<=K;i++)
    {
        while(N%primes[i]==0)
        {
            VN[primes[i]]++;
            N/=primes[i];
        }
    }
    for(i=0;i<=K;i++)
    {
        while(M%primes[i]==0)
        {
            VM[primes[i]]++;
            M/=primes[i];
        }
    }
    int p=1;
    for(i=0;i<=K;i++)
    {
        int k=min(VM[primes[i]],VN[primes[i]]);
        while(k--)
        {
            p*=primes[i];
        }
    }
    cout<<p;
    return 0;
}
