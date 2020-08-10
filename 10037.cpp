#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int num,pe,P[1010];
    cin>>num;
    while(num--)
    {
        cin>>pe;
        for(int i=0;i<pe;i++)
            cin>>P[i];
        sort(P,P+pe);

        int sum=0,i;
        for(i=pe-1;i>=3;i-=2)
        {
            int a=P[1]+P[0]+P[i]+P[1];
            int b=P[i]+P[0]+P[i-1]+P[0];
            if(a<b)
                sum+=a;
            else
                sum+=b;
        }
        if(i==2)//3
            sum+=(P[1]+P[0]+P[2]);
        else if(i==1)//2
            sum+=P[1];
        else //if(pe==1)//1
            sum+=P[0];

        cout<<sum<<endl;
        //pe=temp;
        for (int i=pe-1;i>=3;i-=2)
        {
            int A=P[1]+P[0]+P[i]+P[1];
            int B=P[i]+P[0]+P[i-1]+P[0];
            if(A<B)
                cout<<P[0]<<" "<<P[1]<<endl<<P[0]<<endl<<P[i-1]<<" "<<P[i]<<endl<<P[1]<<endl;
            else
                cout<<P[0]<<" "<<P[i-1]<<endl<<P[0]<<endl<<P[0]<<" "<<P[i]<<endl<<P[0]<<endl;
        }
        if(i==2)
            cout<<P[0]<<" "<<P[1]<<endl<<P[0]<<endl<<P[0]<<" "<<P[2]<<endl;
        else if(i==1)
            cout<<P[0]<<" "<<P[1]<<endl;
        else //if(pe==1)
            cout<<P[0]<<endl;
        if(num)
            cout<<endl;
    }
}
