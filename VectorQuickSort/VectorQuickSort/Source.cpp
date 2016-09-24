#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void print(vector<int>& inputs)
{
	for (const auto& i : inputs)
		cout << i << " ";
}

int partition(vector<int>& inputs, int start, int end)
{
	srand(time(NULL));
	int randomIndex = rand() % (end - start) + start;
	swap(inputs[randomIndex], inputs[end]);
	int pivot = inputs[end];
	int pIndex = start;
	for (auto i = start; i < end; ++i) // Mark i = start & end; not i = 0 and inputs.size().
	{
		if (inputs[i] <= pivot)
		{
			swap(inputs[i], inputs[pIndex]);
			++pIndex;
		}
	}
	swap(inputs[end], inputs[pIndex]);
	return pIndex;
}

void quicksort(vector<int>& inputs, int start, int end)
{
	if (start < end)
	{
		int pIndex = partition(inputs, start, end);
		quicksort(inputs, start, pIndex - 1);
		quicksort(inputs, pIndex + 1, end);
	}
}

int main()
{
	cout << "Quick Sort Algorithm" << endl;
	cout << "Enter the list to be sorted: " << endl;

	vector<int> inputs;
	int n;
	while (cin >> n)
		inputs.emplace_back(n);
	
	cout << "Before sorting: " << endl;
	print(inputs);
	cout << endl;
	quicksort(inputs, 0, inputs.size()-1);
	cout << "After sorting: " << endl;
	print(inputs);
	cout << endl;

	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}