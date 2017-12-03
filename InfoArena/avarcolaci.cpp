#include <bits/stdc++.h>

using namespace std;
ifstream fi("avarcolaci.in");
ofstream fo("avarcolaci.out");
int main()
{
    int n,t,a;
    int curr, cnt = 0;
    int j = 1;
    int tests[20];
    fi>>t;
    for(int j = 1; j <= t; ++j)
    {
        cnt = 0;
        fi>>n;
        for(int i = 1; i <= n*2; ++i)
        {
            fi>>a;
            if(cnt == 0)
            {
                curr = a;
            }
            if(curr != a)
            {
                --cnt;
            }
            if(curr == a)
            {
                ++cnt;
            }
        }
        tests[j] = curr;
    }
    fi.close();
    fi.open("avarcolaci.in");
    fi>>t;
    for(int i = 1; i <= t; ++i)
    {
        fi>>n;
        cnt = 0;
        for(int j = 1; j <= 2*n; ++j)
        {
            fi>>a;
            if(tests[i] == a)
                cnt++;
        }
        if(cnt > n)
            fo<<tests[i]<<"\n";
        else
            fo<<"Mozart\n";
    }
}
