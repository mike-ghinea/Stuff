#include<fstream>
#include<cstring>
#define BASE 75
#define N 2000001
#define MOD1 100021
#define MOD2 100007
using namespace std;
ifstream cin("strmatch.in");
ofstream cout("strmatch.out");
char A[N],B[N];
bool match[N];
int i,j,HASH1,HASH2,HASH_1,HASH_2,lenA,lenB,p1,p2,NR;
int main()
{
    cin>>A;
    lenA=strlen(A);
    cin>>B;
    lenB=strlen(B);
    if(lenA>lenB)
    {
        cout<<0;
        return 0;
    }
    p1=p2=1;
    for(i=0;i<lenA;i++)
    {
        HASH1=(HASH1*BASE + A[i])%MOD1;
        HASH2=(HASH2*BASE + A[i])%MOD2;
        if(i)
        {
            p1=(p1*BASE)%MOD1;
            p2=(p2*BASE)%MOD2;
        }
    }
    for(i=0;i<lenA;i++)
    {
        HASH_1=(HASH_1*BASE + B[i])%MOD1;
        HASH_2=(HASH_2*BASE + B[i])%MOD2;
    }
    if(HASH1==HASH_1 and HASH2==HASH_2)
    {
        match[0]=1;
        NR++;
    }
    for(i=lenA;i<lenB;i++)
    {
        HASH_1=((HASH_1-(B[i-lenA]*p1)%MOD1+MOD1)*BASE+B[i])%MOD1;
        HASH_2=((HASH_2-(B[i-lenA]*p2)%MOD2+MOD2)*BASE+B[i])%MOD2;
        if(HASH1==HASH_1 and HASH2==HASH_2)
        {
            match[i-lenA+1]=1;
            NR++;
        }
    }
    cout<<NR<<"\n";
    NR=0;
    for(i=0;i<lenB and NR<1000;i++)
    {
        if(match[i])
        {
            cout<<i<<" ";
            NR++;
        }
    }
    return 0;
}
