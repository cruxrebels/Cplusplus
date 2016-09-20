#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& inputs)
{
	for (auto const& i : inputs)
		cout << i << " ";
}

void merge(vector<int>& inputs, vector<int>& left, vector<int>& right)
{
	auto nL = left.size();
	auto nR = right.size();
	int i = 0, j = 0, k = 0;
	while (j < nL && k < nR)
	{
		if (left[j] <= right[k])
		{
			inputs[i] = left[j]; ++j;
		}
		else
		{
			inputs[i] = right[k]; ++k;
		}
		++i;
	}

	while (j < nL)
	{
		inputs[i] = left[j]; ++i; ++j;
	}
	while (k < nR)
	{
		inputs[i] = right[k]; ++i; ++k;
	}
}

void mergesort(vector<int>& inputs)
{
	auto n = inputs.size();
	if (n < 2)
		return;
	int mid = floor(n / 2);

	vector<int> left, right;
	for (auto i = 0; i < mid; ++i)
		left.emplace_back(inputs[i]);
	for (auto j = mid; j < n; ++j)
		right.emplace_back(inputs[j]);

	mergesort(left);
	mergesort(right);
	merge(inputs, left, right);
}

int main()
{
	cout << "Merge Sort Algorithm" << endl;
	cout << "Enter the list to be sorted: " << endl;
	
	vector<int> inputs;
	int n;
	while (cin >> n)
		inputs.emplace_back(n);

	cout << "Before sorting: " << endl;
	print(inputs);
	cout << endl;
	mergesort(inputs);
	cout << "After sorting: " << endl;
	print(inputs);
	cout << endl;

	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}