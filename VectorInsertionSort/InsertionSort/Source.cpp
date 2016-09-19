#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& inputs)
{
	for (const auto& i : inputs)
		cout << i << " ";
}

void insertionsort(vector<int>& inputs)
{
	auto n = inputs.size();
	for (auto i = 1; i < n; ++i)
	{
		int val = inputs[i];
		int hole = i;
		while (hole > 0 && inputs[hole-1] > val)
		{
			inputs[hole] = inputs[hole-1];
			--hole;
		}
		inputs[hole] = val;
	}
}

int main()
{
	cout << "Insertion Sort Algorithm" << endl;
	cout << "Enter the list to be sorted: " << endl;

	vector<int> inputs;
	int n;
	while (cin >> n)
		inputs.emplace_back(n);

	cout << "Before sorting: " << endl;
	print(inputs);
	cout << endl;
	insertionsort(inputs);
	cout << "After sorting: " << endl;
	print(inputs);
	cout << endl;

	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}