#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fi("paranteze.in");
ofstream fo("paranteze.out");

stack <pair<int,char> > stiva;

void wipeout()
{
    while(!stiva.empty())
    {
        stiva.pop();
    }
}

int main()
{

    char ve[200];
    ve[')']='(';
    ve['}']='{';
    ve[']']='[';


    int n,nr=0,maxx=0;
    char x;
    bool v[1000005]={0};
    fi>>n;
    for(int i=1;i<=n;i++)
    {
        fi>>x;
        if(x=='{' || x=='[' || x=='(')
            {
                stiva.push(make_pair (i, x));
            }

        else if(!stiva.empty())
        {
            if(ve[x]==stiva.top().second)
                {
                    v[stiva.top().first]=1;
                    v[i]=1;
                    stiva.pop();

                }

            else
            {
                wipeout();
            }

        }
    }
    for(int i=1;i<=n;i++)
        if(v[i]==1)
        {
            nr++;
            if(nr>maxx)
                maxx=nr;
        }
        else
        {
            nr=0;
        }
    fo<<maxx;



}
