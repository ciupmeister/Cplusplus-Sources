#include <fstream>
using namespace std;
ifstream fi("expresie3.in");
ofstream fo("expresie3.out");
int aray[40],nr,val=1,used[40],semafor,j,f,sem;
int main()
{

    string s;

    fi>>s;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]==')')
        {
            j=f=i;
            while(s[j]!='(')--j;
            i-=2;
            if(s[j-1]=='/')
            {
                for(int l=j+1;l<f;++l)
                {
                    if(s[l]=='/')
                        s[l]='*';
                    else if(s[l]=='*')
                        s[l]='/';
                }
            }
            s.erase(f,1);
            s.erase(j,1);
        }
    }

    used[s[0]-'a']=1;
    aray[s[0]-'a']++;
    for(int i=2;i<s.size();++i)
    {
        if(isalpha(s[i]))
        {
            used[s[i]-'a']=1;
            if(s[i-1]=='*')
                aray[s[i]-'a']++;
            else
                aray[s[i]-'a']--;
        }
    }
    for(int i=0;i<30;++i)
    {
        if(used[i]==1)
            fo<<(char)(i+'a')<<" "<<aray[i]<<'\n';
    }
}
