#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
vector <int >deck1,deck2;
int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        if(cardp1[0]=='A')
            deck1.push_back(15);
        else if(cardp1[0]=='K')
            deck1.push_back(14);
        else if(cardp1[0]=='Q')
            deck1.push_back(13);
        else if(cardp1[0]=='J')
            deck1.push_back(12);
        else
            deck1.push_back(cardp1[0]-48);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp1; // the m cards of player 2
        cin >> cardp1; cin.ignore();
        if(cardp1[0]=='A')
            deck2.push_back(15);
        else if(cardp1[0]=='K')
            deck2.push_back(14);
        else if(cardp1[0]=='Q')
            deck2.push_back(13);
        else if(cardp1[0]=='J')
            deck2.push_back(12);
        else
            deck2.push_back(cardp1[0]-48);
    }
    reverse(deck1.begin(),deck1.end());
    reverse(deck2.begin(),deck2.end());
    //for(int i=0;i<deck1.size();i++)
    //    cout<<deck1[i]<<" ";
    int TURNS=0;
    int j;
    while(1)
    {
        if(deck1.empty())
        {
            cout<<2<<" "<<TURNS;
            return 0;
        }
        else if(deck2.empty())
        {
            cout<<1<<" "<<TURNS;
            return 0;
        }
        TURNS++;
        if(deck1.back()>deck2.back())
        {
            int x=deck1.back();
            int y=deck2.back();
            deck1.pop_back();
            deck2.pop_back();
            reverse(deck1.begin(),deck1.end());
            deck1.push_back(x);
            deck1.push_back(y);
            reverse(deck1.begin(),deck1.end());
            for(j=0;j<deck1.size();j++)
                cout<<deck1[j]<<" ";
            cout<<'\n';
            for(j=0;j<deck2.size();j++)
                cout<<deck2[j]<<" ";
            cout<<'\n';
        }
        else if(deck1.back()<deck2.back())
        {
            int x=deck1.back();
            int y=deck2.back();
            deck1.pop_back();
            deck2.pop_back();
            reverse(deck2.begin(),deck2.end());
            deck2.push_back(y);
            deck2.push_back(x);
            reverse(deck2.begin(),deck2.end());
            for(j=0;j<deck1.size();j++)
                cout<<deck1[j]<<" ";
            cout<<'\n';
            for(j=0;j<deck2.size();j++)
                cout<<deck2[j]<<" ";
            cout<<'\n';
        }
    }
}
