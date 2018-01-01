#include<iostream>
#include<cstring>
using namespace std;
struct trie
{
    trie *D[10];
    trie()
    {
        for(int i=0;i<10;i++)
            D[i]=0;
    }
};
int _insert(trie *p,char *s)
{
    if(*s!=0)
    {
        if(p->D[*s-'0']==NULL)
            p->D[*s-'0']=new trie;
        _insert(p->D[*s-'0'],s+1);
    }
}
int prefix(trie *p,char *s)
{
    if(*s==0)
        return 0;
    if(p->D[*s-'0']==NULL)
        return 0;
    return 1+prefix(p->D[*s-'0'],s+1);
}
trie *Trie;
char num[11];
int n,i,sum;
int main()
{
    Trie=new trie;
    cin>>n;
    memset(num,0,sizeof(num));
    cin>>num;
        _insert(Trie,num);
    sum+=strlen(num);
    for(i=2;i<=n;i++)
    {
        cin>>num;
        sum+=strlen(num);
        sum-=prefix(Trie,num);
    }
    cout<<sum;
}
