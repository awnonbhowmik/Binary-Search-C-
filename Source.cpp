#include<iostream>
#include<vector>
#include<algorithm>
#include<chrono>

using namespace std;

int BinarySearch(vector<int>vec, int low, int high, int x)
{
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (x > vec[mid])
			return BinarySearch(vec, mid + 1, high, x);
		else if (x < vec[mid])
			return BinarySearch(vec, low, mid - 1, x);
		else
			return mid;
	}

	return -1;
}

int main()
{
	vector<int> a = { 17,12,9,6,30,25,20,35,120 };
	int x;
	int low = 0;
	int high = a.size() - 1;

	sort(a.begin(), a.end());
	while (true)
	{
		cout << endl;
		cout << "Enter data to find: ";
		cin >> x;
		auto t1 = chrono::high_resolution_clock::now();
		cout << endl;
		if (x < 0)
		{
			cout << "The sorted list was..." << endl;
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << " ";
			break;
		}
		if (BinarySearch(a, low, high, x) == -1)
			cout << "Not found!" << endl;
		else
			cout << "Found at: " << BinarySearch(a, low, high, x) << endl;
		
		auto t2 = chrono::high_resolution_clock::now();
		chrono::duration<double, milli>fp_ms = t2 - t1;
		cout << "Time to find: " << fp_ms.count();
	}
	system("pause");
	return 0;
}