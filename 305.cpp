#include <iostream>
using namespace std;
int lists[15];
int slove(int k)
{
    int people,kill,counts,m;
    if(k==1) return 2;
    people=2*k;
    for(m=k+1;;m++)
    {
        if((m-1)%people>=k)
        {
            kill=(m-1)%people;
            for(counts=2;counts<=k;counts++)
            {
                kill=(kill+m-1)%(people-counts+1);
                if(kill<k||kill>2*k)break;
            }
            if(counts==k+1) return m;
        }
    }
}
int main()
{
    for(int i=1;i<15;i++)
    {
        lists[i]=slove(i);
    }
    int k;
    while(cin>>k,k!=0)
    {
        cout<<lists[k]<<endl;
    }
}
