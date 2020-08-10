#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
int SQRT_MAX=31622;
int prime[31622]={0};
vector<int> primes;
int findprime()
{
    prime[0]=0;
    prime[1]=0;
    prime[2]=1;
    for(int i=3;i<SQRT_MAX;i++)
        prime[i]=i%2;
    int ssqrt=sqrt(SQRT_MAX);
    for(int i=3;i<ssqrt;i+=2)
    {
        if(prime[i]==0)
            continue;
        for(int j=i*i;j<SQRT_MAX;j+=i)
            prime[j]=0;
    }
    for(int i=2;i<SQRT_MAX;i++)
        if(prime[i])
            primes.push_back(i);
}

int divisionnum(int n)
{
    if(n==1)return 1;
    if(n<SQRT_MAX&&prime[n])return 2;
    int total=1;
    int temp=n;
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++)
    {
       int div=primes[i];
       int exp=1;
       for(;temp%div==0;exp++)
       {
           temp/=div;
       }
       total*=exp;
       if(temp==1)
        return total;
    }
    if(total!=1)
        return total*2;
    return 2;
}

int main()
{
    findprime();
    int times;
    cin>>times;
    while(times--)
    {
        int a,b;
        cin>>a>>b;
        int mi=0,md=0;
        for(int i=a;i<=b;i++)
        {
            int cd=divisionnum(i);
            if(cd>md)
            {
                mi=i;
                md=cd;
            }
        }
        cout<<"Between "<<a<<" and "<<b<<", "<<mi<<" has a maximum of "<<md<<" divisors."<<endl;
    }
}
