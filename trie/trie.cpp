#include<fstream>
#include<vector>
using namespace std;
ifstream cin("trie.in");
ofstream cout("trie.out");
struct trie
{
    int nr;
    int aux;
    trie *L[26];
    trie()
    {
        nr=0;
        aux=0;
        for(int i=0;i<26;i++)
            L[i]=0;
    }
};
trie *Trie;
int _insert(trie *p, char *s)
{
    if(*s!=0)
    {
        if(p->L[*s-'a']==NULL)
            p->L[*s-'a']=new trie,
            p->aux++;
        _insert(p->L[*s-'a'],s+1);
    }
    else
        p->nr++;
}
int _delete(trie *p,char *s)
{
    if(*s==0)
    {
        p->nr--;
        if(p->nr==0 and p->aux==NULL)
        {
            delete p;
            return 1;
        }
        return 0;
    }
    if(p->L[*s-'a']==NULL)
        return 0;
    bool d=_delete(p->L[*s-'a'],s+1);
    if(!d)
        return 0;
    p->L[*s-'a']=NULL;
    p->aux--;
    if(p->aux==0 and p->nr==0 and p!=Trie)
    {
        delete p;
        return 1;
    }
    return 0;
}
int _count(trie *p,char *s)
{
    if(*s==0)
        return p->nr;
    if(p->L[*s-'a']==NULL)
        return 0;
    return _count(p->L[*s-'a'],s+1);
}
int prefix(trie *p,char *s)
{
    if(*s==0)
        return 0;
    if(p->L[*s-'a']==NULL)
        return 0;
    return 1+prefix(p->L[*s-'a'],s+1);
}
int OPERATOR;
char WORD[22];
int main()
{
    Trie = new trie;
    while(cin>>OPERATOR)
    {
        cin>>WORD;
        switch(OPERATOR)
        {
            case 0:
                _insert(Trie,WORD);
                break;
            case 1:
                _delete(Trie,WORD);
                break;
            case 2:
                cout<<_count(Trie,WORD)<<"\n";
                break;
            default:
                cout<<prefix(Trie,WORD)<<"\n";
                break;
        }
    }
}
