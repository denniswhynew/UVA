#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    int times,num[91]={0},Max=0;
    char line[1000],ch;
    cin>>times;
    while(times>=0)
    {
        cin.get(ch);
        if(ch=='\n') times--;
        if(ch>=97&&ch<=122) ch-=32;
        num[ch]++;
        if(num[ch]>Max) Max=num[ch];
    }
    for(int i=Max;i>=1;i--)
            for(int j=65;j<=90;j++)
                if(num[j]==i)
                    cout<<char(j)<<" "<<i<<endl;
}
