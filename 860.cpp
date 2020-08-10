#include <iostream>
#include <cstring>
#include <sstream>
#include <map>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstdio>
using namespace std;
int main()
{
    char s[999];
    while(gets(s))
    {
        if(!strcmp(s,"****END_OF_INPUT****"))
            break;
        map<string,int> M;
        int N=0;
        do
        {
            if(!strcmp(s,"****END_OF_TEXT****"))
                break;
            for(int i=0;s[i];i++)
            {
                if (s[i] == ','||s[i] == '.'||s[i] == ':'||s[i] == ';'||s[i] == '!'||s[i] == '?'||s[i] == '\"'||s[i] == '('||s[i] == ')')
                    s[i] = ' ';
                if(s[i]>='A'&&s[i]<='Z')
                    s[i]=tolower(s[i]);
            }
            stringstream sin(s);
            string K;
            while(sin>>K)
            {
                int &v=M[K];
                v++;N++;
            }
        }while(gets(s));
        double V=0,U=0,R;
        for(map<string,int>::iterator it=M.begin();it!=M.end();it++)
        {
            V+=(it->second)*(log10(N)-log10(it->second));
        }
        V/=N;
        U=log10(N);
        R=V/U;
        cout<<N<<" "<<fixed<<setprecision(1)<<V<<" "<<fixed<<setprecision(0)<<R*100<<endl;
    }
}
