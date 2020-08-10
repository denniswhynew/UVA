#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int M,K;
int p[502];
int ans[502][502],n[502];

int main()
{
    int N;
    cin>>N;
    while (N--)
    {
        cin>>M>>K;
        long long int Min=0,Max=0,mid=0;
        for (int i=0;i<M;i++)
        {
            cin>>p[i];
            if (p[i]>Min)
                Min=p[i];
            Max += p[i];
        }

        while (Min<Max)
        {
            int counts=1;
            long long int sum=0;
            mid=(Min+Max)/2;
            for (int i=0;i<M;i++)
            {
                if (sum+p[i]>mid)
                {
                    counts++;
                    sum = 0;
                }
                sum += p[i];
            }
            if(counts>K)
                Min=mid+1;
            else
                Max=mid;
        }

        fill(n,n+502,0);
        long long sum=0;
        for(int i=M-1,j=K-1;i>=0;i--)
        {
            if(sum+p[i]>Max||j>i)
            {
                j--;
                sum = 0;
            }
            sum += p[i];
            ans[j][n[j]++] = p[i];
        }

        for(int i=0; i<K; i++)
        {
            for(int j=n[i]-1; j>=0; j--)
            {
                if(i!=0 || j!=n[0]-1) cout<<" ";
                cout<<ans[i][j];
            }
            if(i!=K-1)
                cout<<" /";
        }
        cout<<endl;
    }
}
