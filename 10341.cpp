#include <iostream>
#include <cmath>
#include <iomanip>
//#define F(x) (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u)
using namespace std;

double p,q,r,s,t,u;

double F(double x)
{
    return(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main()
{
    //double p,q,r,s,t,u;
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        double Max=1.0,Min=0.0,mid;
        for(int i=0;i<100;i++)
        {
            mid=(Max+Min)/2;
            if(F(mid)>0)
                Min=mid;
            else
                Max=mid;
        }
        if (abs(F(mid)) > 1e-6)
            cout<<"No solution"<<endl;
        else
            cout<<fixed<<setprecision(4)<<mid<<endl;
    }
}
