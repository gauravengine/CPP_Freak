#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
	int src;
	int des;
	int weight;
};

bool comparator(edge &a1, edge &b1)
{
	return a1.weight < b1.weight;
}

int find_parent(int *parent, int child)
{
	if (parent[child] == child)
	{
		return child;
	}
	else
	{
		return find_parent(parent, parent[child]);
	}
}

void print(edge output[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (output[i].src <= output[i].des)
			cout << output[i].src << " " << output[i].des << " " << output[i].weight << "\n"; // print smaller first ;)
		else
		{
			cout << output[i].des << " " << output[i].src << " " << output[i].weight << "\n";
		}
	}
}

int main()
{
	int v, e;
	cin >> v >> e;
	edge inputedges[e];
	edge output[v - 1];
	for (int i = 0; i < e; i++)
	{
		cin >> inputedges[i].src;
		cin >> inputedges[i].des;
		cin >> inputedges[i].weight;
	}
	sort(inputedges, inputedges + e, comparator);
	int count = 0, edgescount = 0;

	int parent[v];
	for (int i = 0; i < v; i++)
	{
		parent[i] = i;
	}
	while (count < v - 1)
	{
		int v1 = inputedges[edgescount].src;
		int v2 = inputedges[edgescount].des;
		if (find_parent(parent, inputedges[edgescount].src) != find_parent(parent, inputedges[edgescount].des))
		{
			// update their parents         done
			// insert them into output         done
			output[count].src = inputedges[edgescount].src;
			output[count].des = inputedges[edgescount].des;
			output[count].weight = inputedges[edgescount].weight;

			// finding v2 parent and updating it
			int v2_parent = find_parent(parent, v2);
			parent[v2_parent] = find_parent(parent, v1);

			edgescount++;
			count++;
		}

		else
		{
			edgescount++;
		}
	}

	print(output, v - 1);
	cout << "printing parent array " << endl;
	for (int i = 0; i < v; i++)
	{
		cout << i << " has parent : " << parent[i] << endl;
	}

	return 0;
}