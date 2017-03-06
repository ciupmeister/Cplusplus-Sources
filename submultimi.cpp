#include <iostream>
#include <fstream>
using namespace std;
int n, v[1000];
int folosit[1000];
void backtrackSubmultimi(int p)
{
    if(p==n+1)
    {
        for(int i=1;i<=n;i++)
            if(v[i]==1)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }

    v[p]=0;
    backtrackSubmultimi(p+1);
    v[p]=1;
    backtrackSubmultimi(p+1);
}
void backtrackPermutari(int p)
{
    if(p==n+1)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!folosit[i])
        {
            v[p]=i;
            folosit[i]=1;
            backtrackPermutari(p+1);
            folosit[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    backtrackPermutari(1);


}

///this shit ain't working mate (sumbultimi)
/*
    for(int conf=0;conf<(1<<n);++conf) ///submultimi
    {
        for(int i=0;i<n;i++)
        {
            if(conf & (1<<n)) //bitul e setat
                cout<<(i+1)<<" ";
        }
    }
    cout<<"\n\n";

*/







