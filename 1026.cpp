#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double pi=acos(-1);
int main()
{
    int t=1;
    double a1,b1,t1,a2,b2,O2,c2,real_area;
    int t2,days;
    while(cin>>a1>>b1>>t1>>a2>>b2>>days)
    {
        if(a1==0&&b1==0&&t1==0&&a2==0&&b2==0)
            return 0;

        t2=sqrt((t1*t1*a2*a2*a2)/(a1*a1*a1));
        O2=pi*a2*b2;
        int k=0;
        if((days%t2)/t2>0.5)
        {
            days=t2-days;
            k=1;
        }
        real_area=(days%t2)*O2/t2;
        c2=sqrt(a2*a2-b2*b2);
        double Max=a2,Min=-a2,x,area,y;

        while(abs(real_area-area)>1e-4)
        {
            x=(Max+Min)/2;
            double /*epsilon=sqrt(1-b*b/a*a),*/thita=acos(x/a2)*180,c=pi*a2*a2*thita/360;
            y=sqrt((1-x*x/a2*a2)/b2*b2);
            area=(c*b2/a2)-(abs(x)*y/2);
            if(real_area-area>0)
                Max=x;
            else
                Min=x;
        }
        cout<<fixed<<setprecision(3);
        cout<<"Solar System "<<t<<": "<<x<<" ";
        if(k==1)
            cout<<"-";
        cout<<y<<endl;
        t++;
    }
}
