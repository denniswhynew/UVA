#include <iostream>
#include <algorithm>
using namespace std;
int num[1005],a,c,d,numbers,ans;
bool finding()
{
    for(a=numbers-1;a>=0;a--)
    {
        for(int b=numbers-1;b>1;b--)
        {
            if(a==b)
                continue;
            ans=num[a]-num[b];
            for(c=0,d=b-1;c<d;)
            {
                if(num[c]+num[d]==ans)
                    return true;
                else if(num[c]+num[d]>ans)
                    d--;
                else
                    c++;
            }
        }
    }
    return false;
}
int main()
{
    while(cin>>numbers)
    {
        if(numbers==0)
            return 0;
        for(int i=0;i<numbers;i++)
            cin>>num[i];
        sort(num,num+numbers);
        if(finding())
            cout<<num[a]<<endl;
        else
            cout<<"no solution"<<endl;
    }
}
