//#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#define DIM 200007
using namespace std;
string initial;
string str;
char aux;
int ind,N,M,i,j;
int vN[2*DIM],vM[2*DIM],p[DIM];
long long sol;
int firstLen,firstChr,lastLen,lastChr;
int main()
{
    cin>>N>>M;
    for(i=1;i<=N;i++)
    {
        cin>>str;
        int len=str.length();
        int k=0;
        for(j=0;j<len-2;j++)
        {
            k*=10;
            k+=str[j]-'0';
        }
        if(str[len-1]!=aux)
        {
            vN[++ind]=k;
            vN[++ind]=(str[len-1]-'a')*(-1);
        }
        else
            vN[ind-1]+=k;
        aux=str[len-1];
    }
    int lenN=ind;
    aux=0;
    ind=0;
    for(i=1;i<=M;i++)
    {
        cin>>str;
        int len=str.length();
        int k=0;
        for(j=0;j<len-2;j++)
        {
            k*=10;
            k+=str[j]-'0';
        }
        if(str[len-1]!=aux)
        {
            vM[++ind]=k;
            vM[++ind]=(str[len-1]-'a')*(-1);
        }
        else
            vM[ind-1]+=k;
        aux=str[len-1];
    }
    if(ind>4)
    {

        firstLen=vM[1];
        firstChr=vM[2];
        lastLen=vM[ind-1];
        lastChr=vM[ind];
        ind-=4;
        for(i=1;i<=ind;i++)
            vM[i]=vM[i+2];
        int k=0;
        for(i=2;i<=ind;i++)
        {
            while(k>0 and vM[i]!=vM[k+1])
                k=p[k];
            if(vM[k]==vM[k+1])
                k++;
            p[i]=k;
        }
        k=0;
        for(i=3;i<=lenN-2;i++)
        {
            while(k>0 and vN[i]!=vM[k+1])
                k=p[k];
            if(vN[i]==vM[k+1])
                k++;
            int poz;
            if(k==ind)
            {
                poz=i-ind+1;
                if(firstLen<=vN[poz-2] and firstChr==vN[poz-1] and lastLen<=vN[i+1] and lastChr==vN[i+2])
                    sol++;
                k=p[k];
            }
        }
    }
    else if(ind==2)
    {
        for(i=2;i<=lenN;i+=2)
        {
            if(vN[i]==vM[2] and vN[i-1]>=vM[1])
                sol+=vN[i-1]-vM[1]+1;
        }
    }
    else
    {
        for(i=2;i<=lenN-2;i+=2)
        {
            if(vN[i]==vM[2] and vN[i-1]>=vM[1] and vN[i+1]>=vM[3] and vN[i+2]==vM[4])
                sol++;
        }
    }
    cout<<sol;
}
