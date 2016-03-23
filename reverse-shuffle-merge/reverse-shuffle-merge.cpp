/*
https://www.hackerrank.com/challenges/reverse-shuffle-merge

1. S에서 서로 다른 알파벳의 개수와 종류를 찾는다.
2. 서로 다른 알파벳으로 이루어진 string을 저장한다.
3. string의 멤버인 char를 개수를 늘려가며 string에 추가한다.
4. string을 shuffle한다.
5. shuffle(string) => A가 된다.
6. A, reverse(A)의 merge를 만족하는 A가 답이다.

p.s 아래 프로그램에서 j=0일 때 동작할 필요가 없지만 그것만 예외처리하지는 않았다.
p.s merge는 아래의 site를 참고하였다.
http://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//static const int MAX_LENGTH = 10000;
static const int MAX_LENGTH = 2;
vector<string> merge_str;

string no_duplicate_char_string(const string& str)
{
	string result;
	for (int i = 0; i < str.length(); ++i) {
		size_t found = result.find(str[i]);
		if (found == string::npos)
			result = result + str[i];
		else
			continue;
	}
	return result;
}


void merge(string A, string B, string& eachString, int m, int n, int i)
{
	if (m == 0 && n == 0) {
		//cout << "eachString : " << eachString << endl;
		merge_str.push_back(eachString);
	}

	if (m != 0) {
		eachString[i] = A[0];
		merge(string(A, 1, A.length()), B, eachString, m - 1, n, i+1);
	}

	if (n != 0) {
		eachString[i] = B[0];
		merge(A, string(B, 1, B.length()), eachString, m, n - 1, i+1);
	}
}


int main() {
	string S;
	string solution;
	bool solve = false;

	cin >> S;

	string unique_str = no_duplicate_char_string(S);

	for (int i = 0; i < MAX_LENGTH; ++i) {
		for (int j = 0; j < unique_str.length(); ++j) {
			string candidate_str = unique_str + string(i, unique_str[j]);

			cout << "start : " << candidate_str << endl;

			string reverse_str = candidate_str;
			reverse(reverse_str.begin(), reverse_str.end());

			cout << "reverse : " << reverse_str << endl;
			
			do {
				cout << "permutation : " << candidate_str << endl;

				merge_str.clear();

				string eachString = "";
				eachString.resize(candidate_str.length() + reverse_str.length());
				merge(candidate_str, reverse_str, eachString, candidate_str.length(), reverse_str.length(), 0);

				for (auto& element : merge_str) {
					size_t found = element.find(S);
					if (found != string::npos) {
						solution = element;
						solve = true;
						break;
					}
				}
				if (solve) break;
			} while (next_permutation(candidate_str.begin(), candidate_str.end()));
			
			if (solve) break;
		}
		if (solve) break;
	}

	cout << solution << endl;

	return 0;
}

