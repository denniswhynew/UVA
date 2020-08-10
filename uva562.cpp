#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
void A(int k,int temp[])
{
    temp[0]++;
    for(int i=0;i<k;i++)
    {
        if(temp[i]==2)
        {
            temp[i]=0;
            temp[i+1]++;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a,total=0;
        cin>>a;
        int S[a],temp[a+1];
        for(int i=0;i<a;i++)
        {
            cin>>S[i];
            total+=S[i];
        }
        sort(S,S+a);
        for(int l=0;l<a+1;l++)
        {
            temp[l]=0;
        }
        int one=0,two=0;
        int big=total,small=total;
        while(!temp[a])
        {
            A(a,temp);
            one=0;two=0;
            for(int j=0;j<a;j++)
            {
                if(temp[j]==0)
                    one+=S[j];
                else
                    two+=S[j];
            }
            if(one>two)
            {
                if(one<=big)
                {
                    big=one;
                    small=two;
                }
            }
            else
            {
                if(two<=big)
                {
                    big=two;
                    small=one;
                }
            }
        }
        cout<<abs(big-small)<<endl;
    }
}
