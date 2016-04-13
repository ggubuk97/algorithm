#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits.h>
using namespace std;

int maxSubArray(const vector<int>& v)
{
	int sum;
	int size = v.size();
	int max_value = INT_MIN;
	for (int i=0; i < size; ++i) {
		sum = 0;
		for (int j=i; j < size; ++j) {
			sum += v[j];
			max_value = max(max_value, sum);
		}
	}
	return max_value;
}

int maxSum(const vector<int>& v)
{
	int sum = 0;
	int max_minus_value = INT_MIN;
	bool all_negative = true;
	int size = v.size();

	for (int i=0; i < size; ++i) {
		if (v[i] >= 0) {
			all_negative = false;
			sum += v[i];
		}
		else {
			max_minus_value = max(max_minus_value, v[i]);
		}
	}

	return all_negative ? max_minus_value : sum;
}

int main()
{
	int T, N;
	cin >> T;
	vector<int> v;

	for (int i=0; i < T; ++i) {
		cin >> N;
		int temp;
		for (int j=0; j < N; ++j) {
			cin >> temp;
			v.push_back(temp);	
		}
		cout << maxSubArray(v) << " " << maxSum(v) << endl;
		v.clear();
	}
    return 0;
}

