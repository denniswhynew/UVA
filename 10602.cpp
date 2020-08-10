#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str[102];

void solve(int n)
{
    int ans,j,k;
    sort(str,str+n);
    ans=str[0].size();
    for(int i=1;i<n;i++)
    {
        if(str[i][0]!=str[i-1][0])
        {
            ans+=str[i].size();
            continue;
        }
        for(j=0,k=0;j<str[i-1].size();j++,k++)
        {
            if(str[i-1][j]!=str[i][k])
                break;
        }
        ans+=str[i].size()-k;
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)
        cout<<str[i]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>str[i];
        solve(n);
    }
}
