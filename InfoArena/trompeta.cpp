#include <fstream>
#include <stack>
using namespace std;

ifstream is ("trompeta.in");
ofstream os ("trompeta.out");

int n, m;
char C[1000010], x, sol[1000010];
stack <char> S;

int main()
{
    is >> n >> m;
    is.get(x);
    is.getline(C, 1000009, '\n');
    S.push(C[0]);
    for (int i = 1; i < n; ++i)
    {
        if (S.size() + (n - i) <= m) S.push(C[i]);
        else
        {
            while (S.top() < C[i])
            {
                S.pop();
                if (S.empty() || S.size() == m - (n - i)) break;
            }
            S.push(C[i]);
        }
    }
    for (int p = S.size()-1; !S.empty(); S.pop())
        sol[p] = S.top(), --p;
    os << sol;
    is.close();
    os.close();
}
