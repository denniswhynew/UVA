#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int a,b,w[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97},k=0;
    int z=0;
    while(1)
    {
        cin>>a;if(a==0)break;
        cin>>b;
        int c=pow(a,b),e;
        char d;
        cin.get(d);
        if(d==' ')
        {
            while(1)
            {
                cin>>a>>b;
                e=pow(a,b);
                c*=e;
                cin.get(d);
                if(d=='\n')break;
            }
        }
        c--;
        a=24,b=0;
        while(c!=1)
        {
            if(c%w[a]==0)
            {
                if(w[a]!=b)
                {
                    cout<<w[a]<<" ";
                    b=w[a];z=1;
                }k++;
                c/=w[a];
            }else
            a--;
            if(z==1)
            {
                cout<<k<<" ";
            }
        }
    }
}
