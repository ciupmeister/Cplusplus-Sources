#include <iostream>

using namespace std;
int Count,sumcif[50];
int sum(int a);
int main()
{
    int S;
    cin>>S;
    if(S==1)++Count;
    for(int i=0;i<100000;++i)
        ++sumcif[sum(i)];

    for(int i=0;i<10000;++i)
    {
        int x = sum(i);
        if(S-x>=0 && S-x<46)
        {
            Count+=sumcif[S-x];
        }
    }
    cout<<Count;
}

int sum(int a)
{
    int summ=0;
    while(a!=0)
    {
        summ+=a%10;
        a/=10;
    }
    return summ;
}
