#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long long int fir,sec,temp,ans,ans1;
    while(cin>>fir>>sec){
    ans1=INT_MIN;
    cout<<fir<<" "<<sec<<" ";
    if(sec<fir)
    {
        temp=sec;sec=fir;fir=temp;
    }
    for(long long int i=fir;i<=sec;i++)
    {
        temp=i;
        ans=1;
        while(temp!=1)
        {
            if(temp%2==0)
                temp/=2;
            else if(temp%2!=0)
            temp=temp*3+1;
            ans++;
        }
        if(ans>ans1)
            ans1=ans;
    }
    cout<<ans1<<endl;
}}
