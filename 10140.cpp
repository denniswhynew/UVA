#include <iostream>
#include <vector>

#define max_prime 46341
#define max_prime_sqrt 216
#define max_prime_num 80000
using namespace std;

int p[max_prime];//,prime_num;//prime list
vector<int> prime;
void generate_prime()
{
    int i,j,k;
    p[0]=0;
    //prime_num=0;

    for(i=3;i<max_prime_sqrt;i+=2)
    {
        if(p[i]==1)
            continue;
        k=2*i;
        for(j=i*i;j<max_prime;j+=k)
        {
            p[j]=1;
        }
    }

    for(i=2;i<max_prime;i+=2)
        if(p[i]==0)
            prime.push_back(i);
}

int isprime(int num)
{
    int i;
    if(num<max_prime)
        return !p[num];
    for(int i=0;i<prime.size();i++)
    {
        if(num%prime[i]==0)
            return 0;
    }
    return 1;
}

int main()
{
    generate_prime();
    unsigned int a,b,max_a,max_b,min_a,min_b,p,MAX,MIN;
    while(cin>>a>>b)
    {
        MAX=0,MIN=2147483647;
        if(a<=2)
        {
            p=2;
            a=3;
        }
        else{
            if((a&1)==0)
                a++;
        while(!isprime(a)&&a<b)
            a+=2;
        p=a;
        p+=2;
    }
    while(a<=b)
    {
        if(isprime(a))
        {
            max_a=p;
            max_b=a;
            if(a-p>MAX)
                MAX=a-p;
            if(a-p<MIN)
                MIN=a-p;
            p=a;
        }
        a+=2;
    }
    if(MAX==0)
        cout<<"There are no adjacent primes."<<endl;
    else
        cout<<min_a<<","<<min_b<<" are closest, "<<max_a<<","<<max_b<<" are most distant."<<endl;
    }
}
