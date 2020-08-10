#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int a;
        cin>>a;
        int S[a],temp[50001];
        for(int i=0;i<a;i++)
        {
            cin>>S[i];
        }
        sort(S,S+a);
        temp[0]=0;
        int k=1;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<=i;j++)
            {
                temp[k]=S[i]+temp[j];
                k++;
            }
        }
        int z=k/2;
        cout<<(temp[z+1]-temp[z])<<endl;
    }
}
