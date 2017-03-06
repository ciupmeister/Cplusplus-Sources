#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fi("date.in");

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.second<b.second;
}

int main()
{
    pair<int,int> vect[100000];
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>vect[i].first;
        cin>>vect[i].second;
    }
    sort(vect+1,vect+n+1,cmp);
    int mmr =1;
    int last = vect[1].second;
    for(int i=2;i<=n;i++)
    {
        if(vect[i].first>last)
        {
            mmr++;
            last = vect[i].second;
        }
    }
    cout<<mmr;

}
