#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int count = 0;

int BinarySearch(vector<int> vec, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        if (low <= mid || mid >= high)
			return -1;
        
        cout << "central element = " << vec[mid] << "\n";
        if (x > vec[mid])
        {
            ::count++;
            for (int i = mid + 1; i <= high; i++)
                cout << vec[i] << " ";
            cout << "\n";
            return BinarySearch(vec, mid + 1, high, x);
        }
        else if (x < vec[mid])
        {
            for (int i = low; i <= mid - 1; i++)
                cout << vec[i] << " ";
            cout << "\n";
            ::count++;
            return BinarySearch(vec, low, mid - 1, x);
        }
        else
        {
            ::count++;
            return ::count;
        }
    }

    return -1;
}

int main()
{
    vector<int> a = {2, -4, 6, 10, 12, -7, 8, 0, 22};
    sort(a.begin(), a.end());

    for (auto x : a)
        cout << x << " ";
    int low = 0;
    int high = a.size() - 1;

    cout << "\n\nFind 0:\n\n"
         << BinarySearch(a, low, high, 0);
}
