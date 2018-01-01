//#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
using namespace std;
ofstream cout("raz.out");
void f(int j1[],int j2[])
{
    static int A[999],B[999],i,F[26],a,n,x,y,e,u,q=25,w=25;
    string V[26],p="Niciun castigator",P="Jucator1 >> ",O="<< Jucator2\n",o="Jucatorul ",W;
    for(i=0;i<26;i++)
        A[i]=j1[i],
        B[i]=j2[i],
        V[i]=i+48,
        F[i]=i;
    V[10]="10";
    V[11]=65;
    F[11]=15;
    V[12]=74;
    V[13]=81;
    V[14]=75;
    while(++n<101)
    {
        x=A[a],y=B[a];
        W=P+V[x]+" vs "+V[y]+" "+O;
        e=a;
        while(x==y)
        {
            x=min(x,min(q-a,w-a));
            W+="Razboi!\n";
            if(!x)
            {
                cout<<W+p;
                return;
            }
            W+=P;
            for(i=1;i<=x;W+=V[A[a+i++]]+' ');
            W+="vs ";
            for(;i>1;W+=V[B[a+--i]]+' ');
            x=A[a+=x];
            y=B[a];
            W+=O;
        }
        u=F[x]<F[y];
        cout<<W+"Runda "<<n<<": "+o<<u+1<<" ia cartile\n";
        for(i=1;i<=a-e+1;i++)
            x=e+i-1,
            y=i+a-e+1,
            (u?B[w+i]:A[q+i])=A[x],
            (u?B[w+y]:A[q+y])=B[x];
        (u?w:q)+=2*(a++-e+1);
        if(!(w-a+1)|!(q-a+1))
        {
            cout<<o<<(q<w)+1<<" a castigat";
            return;
        }
    }
    cout<<p;
}
int main()
{
    int j1[] = {10,13,11,7,8,5,11,5,8,8,12,6,9,9,3,6,12,7,11,3,5,14,6,7,2,4},j2[] = {9,13,14,12,13,5,4,7,11,10,3,9,13,10,2,4,2,8,4,12,14,6,14,2,3,10};
    f(j1,j2);
}
