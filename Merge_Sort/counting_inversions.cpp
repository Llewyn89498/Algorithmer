#include <iostream>
#include <vector>
using namespace std;

// merge sort & counting inversions

int merge_sort(vector<int> &arr);
int merge(vector<int> &ar, vector<int> &left, vector<int> &right);

int main()
{
	vector<int> a = { 6,5,4,3,2,1 };

	// vector<int> sortedArr;
	// sortedArr = merge_sort(a);
	// for (int x : sortedArr)
	// 	cout << x << "\t";
	cout << merge_sort(a) << endl;

	for (int x : a)
		cout << x << "\t";
	cout << endl;
	return 0;
}

int merge_sort(vector<int> &arr)
{
	int count = 0;

	if (arr.size() == 1)
		return 0;
	if (arr.size() == 0)
		return 0;


	// if (arr.size() == 1)
	// 	return arr;
	// if (arr.size() == 0)
	// 	return vector<int>();

	vector<int>::iterator mid = arr.begin() + arr.size() / 2;
	vector<int> arr1(arr.begin(), mid);
	vector<int> arr2(mid, arr.end());

	count += merge_sort(arr1);
	count += merge_sort(arr2);
	count += merge(arr, arr1, arr2);

	return count;
}

int merge(vector<int> &ar, vector<int> &left, vector<int> &right)
{
	int i = 0;
	int j = 0;
	int m = int(left.size());
	int n = int(right.size());
	//vector<int> result(m+n);
	int inv_count = 0;

	for (int k = 0; k < m + n; k++)
	{
		if (i == m)
		{
			ar[k] = right[j];
			j++;
			continue;
		}

		if (j == n)
		{
			ar[k] = left[i];
			i++;
			continue;
		}

		if ((left[i] <= right[j]))
		{
			ar[k] = left[i];
			i++;
		}
		else
		{
			ar[k] = right[j];
			inv_count += m - j; 
			j++;
		}
	}

	return inv_count;
}
