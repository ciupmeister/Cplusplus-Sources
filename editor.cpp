#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream fi("editor.in");
ofstream fo("editor.out");

bool eval(string exp);
bool check(char i, char j);

int main()
{
    int t;
    string in,out;
    fi>>t;
    for(int j=1;j<=t;j++)
    {

        fi>>in;
        for(int i=0;i< in.size()-1;i++)
        {
            if(in[i]=='*')
            {
                if(out.size()>0)
                    out.pop_back();
            }
            else
                out.push_back(in[i]);
        }

        if(eval(out))
            fo<<":)"<<"\n";
        else
            fo<<":("<<"\n";
        out="";
        in="";
    }
    fi.close();
    fo.close();
}
bool check(char i, char j)
{
    return ((i=='(' && j==')') || (i=='[' && j==']'));
}

bool eval(string exp)
{
    stack<char> st;
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='(' || exp[i]=='[')
            st.push(exp[i]);
        else
        {
            if(st.size() == 0)
                return 0;
            char x = st.top();
            st.pop();
            if(!check(x,exp[i]))
                return 0;
        }
    }
    if(st.size()>0)
        return 0;
    return 1;
}


