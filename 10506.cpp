#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
vector<vector<int> > adjList;
vector<int> visit;
vector<string> node;
map<string, int> store; // <node, nodeID>
vector<int> eulerCircuit;
int allPermutation;
void init(int n)
{
	adjList.assign(n, vector<int>());
	visit.assign(n, 0);
	node.clear();
	store.clear();
	eulerCircuit.clear();
}
void buildNode(int digit, int base)
{
	string str(digit, '0');
	node.push_back(str);
	store[str] = 0;
	for (int i = 0; i < allPermutation - 1; i++)
	{
		str[str.size() - 1]++; // "000" -> "001"
		for (int j = str.size() - 1; j > 0; j--) // base = 2, "002" -> "010"
		{
			if (str[j] >= base + '0')
			{
				str[j] = '0';
				str[j - 1]++;
			}
		}
		node.push_back(str);
		store[str] = node.size() - 1;
	}
}
void LinkNode(int a, int b)
{
	if (a != b)
		adjList[a].push_back(b);
}
void Link(int n, int base) // base = 3, (000) link (001), (002)
{
	string tmp = node[n].substr(1);
	tmp += " ";
	for (int i = '0'; i < '0' + base; i++)
	{
		tmp[tmp.size() - 1] = i;
		LinkNode(n, store[tmp]);
	}
}
void DFS(int cur, bool &finish)
{
	visit[cur] = 1;
	eulerCircuit.push_back(cur);
	if (eulerCircuit.size() == node.size())
	{
		string last, first;
		last = node[cur];
		first = node[0];
		if (last.substr(1) == first.substr(0, first.size() - 1))
		{// the last node link the first node
			finish = true;
		}
		return;
	}

	for (int i = 0; i < (int)adjList[cur].size(); i++)
	{
		int tmp = adjList[cur][i];
		if (!visit[tmp])
		{
			DFS(tmp, finish);
			if (finish) return;
		}
	}
	visit[cur] = 0;
	eulerCircuit.pop_back();
}
int main()
{
	int M, N;
	while (cin >> M >> N)
	{
		allPermutation = pow(N, M);
		init(allPermutation);
		buildNode(M, N);
		for (int i = 0; i < (int)node.size(); i++)
		{
			Link(i, N);
		}
		bool finish = false;
		DFS(0, finish);
		for (int i = 0; i < (int)eulerCircuit.size(); i++)
		{
			int t = eulerCircuit[i];
			cout << node[t][0];
		}
		cout << endl;
	}
	return 0;
}