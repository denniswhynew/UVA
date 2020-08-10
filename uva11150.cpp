#include <iostream>
using namespace std;
int main()
{
    int  n,m=3;
    while(cin>>n)
    {
        int l=n,s=n;
        while(l>=m)
        {
            s+=l/m;
            l=l%m+l/m;
        }
        if (l==2) s++;
        cout<<s<<endl;;
    }
}
