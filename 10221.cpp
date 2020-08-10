#include <iostream>
#include <cmath>
#include <iomanip>
#define R 6440
using namespace std;
int main()
{
    double a,s;
    string unit;
    while(cin>>s>>a>>unit)
    {
        if(unit=="min")
            a/=60;
        if(a>180)
            a=360-a;
        double angle = a*acos(-1)/180;
        double arc_length = 2*(s+R)*sin(angle/2);
        double b=angle*(s+R);
        cout<<fixed<<setprecision(6);
        cout<<b<<" "<<arc_length<<endl;
    }
}
