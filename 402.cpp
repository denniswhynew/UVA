#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int people, free,cases = 1;;
	while (cin >> people)
	{
		cin >> free;
		cout << "Selection #" << cases << endl;
		int poker[21];
		for (int i = 0; i<20; i++)
		{
			cin >> poker[i];
		}
		vector<int>total(people);
		for (int i = 0; i<total.size(); i++)
		{
			total[i] = i + 1;
		}
		for (int i = 0; i<20; i++)
		{
			if (total.size() <= free) break;
			int j = 1, k = 1, temp_size = total.size();
			while (j*poker[i] <= temp_size)
			{
				total.erase(total.begin() + (j*poker[i] - k));
				if (total.size() <= free) break;
				j++;
				k++;
			}
		}
		for (int i = 0; i<total.size(); i++)
		{
			cout << total[i];
			if (i<total.size() - 1)
				cout << " ";
		}
		cout << endl << endl;
		cases++;
	}
}
