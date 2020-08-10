#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

bool online(double x, double y, double t1x, double t1y, double t2x, double t2y, double t3x, double t3y)
{
	bool flag = false;
	if (abs((t2x - t1x)*(y - t1y) - (t2y - t1y)*(x - t1x)) < 0.001)
		flag = true;
	if (abs((t3x - t2x)*(y - t2y) - (t3y - t2y)*(x - t2x)) < 0.001)
		flag = true;
	if (abs((t1x - t3x)*(y - t3y) - (t1y - t3y)*(x - t3x)) < 0.001)
		flag = true;
	return flag;
}

double hilon(double t1x, double t1y, double t2x, double t2y, double t3x, double t3y)
{
	double d = ((t2x*t3y + t3x*t1y + t1x*t2y) - (t3x*t2y + t1x*t3y + t2x*t1y)) / 2;
	return abs(d);
}

struct rectangle
{
	double lx;
	double ly;
	double rx;
	double ry;
};

struct circle
{
	double cx;
	double cy;
	double cr;
};

struct triangle
{
	double t1x;
	double t1y;
	double t2x;
	double t2y;
	double t3x;
	double t3y;
};

struct graph
{
	rectangle R;
	circle C;
	triangle T;
	char types;
};
int main()
{
	char type;
	int figure = 0;
	graph G[1000];
	while (cin>>type)
	{
		if (type == '*')
			break;
		switch (type)
		{
			case 'r':
				cin >> G[figure].R.lx >> G[figure].R.ly >> G[figure].R.rx >> G[figure].R.ry;
				G[figure].types = 'r';
				figure++;
				break;
			case 'c':
				cin >> G[figure].C.cx >> G[figure].C.cy >> G[figure].C.cr;
				G[figure].types = 'c';
				figure++;
				break;
			case 't':
				cin >> G[figure].T.t1x >> G[figure].T.t1y >> G[figure].T.t2x >> G[figure].T.t2y >> G[figure].T.t3x >> G[figure].T.t3y;
				G[figure].types = 't';
				figure++;
				break;
		}
	}
	double x, y;
	int num = 0,flag = 0;
	while (cin >> x >> y)
	{
		flag = 0;
		num++;
		if (abs(9999.9 - x) < 0.001 && abs(9999.9 - y) < 0.001)
			break;
		for (int i = 0; i < figure; i++)
		{
			switch (G[i].types)
			{
				case 'r':
					if (x > G[i].R.lx && x < G[i].R.rx && y > G[i].R.ry && y < G[i].R.ly)
					{
						cout << "Point " << num << " is contained in figure " << i+1 << endl;
						flag = 1;
					}
					break;
				case 'c':
					if ((G[i].C.cr)- sqrt((x - G[i].C.cx)*(x - G[i].C.cx) + (y - G[i].C.cy)*(y - G[i].C.cy)) > 0)
					{
						cout << "Point " << num << " is contained in figure " << i+1 << endl;
						flag = 1;
					}
					break;
				case 't':
					double s = hilon(x, y, G[i].T.t1x, G[i].T.t1y, G[i].T.t2x, G[i].T.t2y)
							+ hilon(x, y, G[i].T.t2x, G[i].T.t2y, G[i].T.t3x, G[i].T.t3y)
							+ hilon(x, y, G[i].T.t3x, G[i].T.t3y, G[i].T.t1x, G[i].T.t1y);
					double k = hilon(G[i].T.t1x, G[i].T.t1y, G[i].T.t2x, G[i].T.t2y, G[i].T.t3x, G[i].T.t3y);
					if (abs(k-s)<0.0001)
					{
						if (!online(x, y, G[i].T.t1x, G[i].T.t1y, G[i].T.t2x, G[i].T.t2y, G[i].T.t3x, G[i].T.t3y))
						{
							cout << "Point " << num << " is contained in figure " << i+1 << endl;
							flag = 1;
						}
					}
					break;
			}
		}
		if (!flag)
		{
			cout << "Point " << num << " is not contained in any figure" << endl;
		}
	}
	return 0;
}
