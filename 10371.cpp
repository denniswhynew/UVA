#include <iostream>
#include <map>
#include <sstream>
using namespace std;

map< string, pair<int,int> > timezones;
void time(int& h, int& m) {
  if (h < 0) {
    h += 24;
  } else if (h > 23) {
    h -= 24;
  }

  if (m < 0) {
    m += 60;
    h -= 1;
  } else if (m > 59) {
    m -= 60;
    h += 1;
  }

  if (h < 0) {
    h += 24;
  } else if (h > 23) {
    h -= 24;
  }
}

void utc(int& h, int& m, string& zone) {
  h -= timezones[zone].first;
  m -= timezones[zone].second;
  time(h, m);
}

void local(int& h, int& m, string& zone) {
  h += timezones[zone].first;
  m += timezones[zone].second;
  time(h, m);
}

int main()
{
    timezones["UTC"] = make_pair(0 , 0);
    timezones["GMT"] = make_pair(0 , 0);
    timezones["BST"] = make_pair(1 , 0);
    timezones["IST"] = make_pair(1 , 0);
    timezones["WET"] = make_pair(0 , 0);
    timezones["WEST"]= make_pair(1 , 0);
    timezones["CET"] = make_pair(1 , 0);
    timezones["CEST"]= make_pair(2 , 0);
    timezones["EET"] = make_pair(2 , 0);
    timezones["EEST"]= make_pair(3 , 0);
    timezones["MSK"] = make_pair(3 , 0);
    timezones["MSD"] = make_pair(4 , 0);
    timezones["AST"] = make_pair(-4, 0);
    timezones["ADT"] = make_pair(-3, 0);
    timezones["NST"] = make_pair(-3,-30);
    timezones["NDT"] = make_pair(-2,-30);
    timezones["EST"] = make_pair(-5, 0);
    timezones["EDT"] = make_pair(-4, 0);
    timezones["CST"] = make_pair(-6, 0);
    timezones["CDT"] = make_pair(-5, 0);
    timezones["MST"] = make_pair(-7, 0);
    timezones["MDT"] = make_pair(-6, 0);
    timezones["PST"] = make_pair(-8, 0);
    timezones["PDT"] = make_pair(-7, 0);
    timezones["HST"] = make_pair(-10,0);
    timezones["AKST"]= make_pair(-9, 0);
    timezones["AKDT"]= make_pair(-8, 0);
    timezones["AEST"]= make_pair(10, 0);
    timezones["AEDT"]= make_pair(11, 0);
    timezones["ACST"]= make_pair(9 , 30);
    timezones["ACDT"]= make_pair(10,30);
    timezones["AWST"]= make_pair(8 , 0);

    int t;
    string ctime,itime,p1,p2;
    cin>>t;
    char CCCC;
    while(t--)
    {
        int h=0,m=0;
        cin>>ctime;
        if(ctime!="noon"&&ctime!="midnight")
        {
            cin>>itime;
        }
        cin>>p1>>p2;
        if(ctime=="noon")
        {
            h=12;m=0;
        }
        else if(ctime=="midnight")
        {
            h=0;m=0;
        }
        else
        {
            istringstream ct(ctime);
            ct>>h;
            ct>>CCCC;
            ct>>m;

            if(itime[0]=='p'&&h<12)
            {
                h+=12;
                if(h==24)
                    h=0;
            }
            else if(itime[0]=='a'&&h==12)
                h=0;
        }
        /*m=h*60+m;
        m=m+((timezone[p2]-timezone[p1]*60+24*60));
        h=(m/60)%24;
        m=m%60;*/

        utc(h, m, p1);
        local(h, m, p2);
        if(h==0&&m==0)
            cout<<"midnight"<<endl;
        else if(h==12&&m==0)
            cout<<"noon"<<endl;
        else
        {
            if(h==0)
                cout<<"12:"<<(m>9? "":"0")<<m<<" a.m."<<endl;
            else if(h==12)
                cout<<"12:"<<(m>9?"":"0")<<m<<" p.m."<<endl;
            else if (h>12)
                cout<<h-12<<":"<<(m>9?"":"0")<<m<<" p.m."<<endl;
            else
                cout<<h<<":"<<(m>9?"":"0")<<m<<" a.m."<<endl;
        }
    }
}
