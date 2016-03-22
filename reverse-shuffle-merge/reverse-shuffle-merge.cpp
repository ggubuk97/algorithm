/*
	1. S에서 서로 다른 알파벳의 개수와 종류를 찾는다.
	2. 서로 다른 알파벳으로 이루어진 string을 저장한다.
	3. string의 멤버인 char를 개수를 늘려가며 string에 추가한다.
	4. string을 shuffle한다.
	5. shuffle(string) => A가 된다.
	6. A, reverse(A)의 merge를 만족하는 A가 답이다.
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

string no_duplicate_char_string(const string& str)
{
	string result;
	for (int i = 0; i < str.length(); ++i) {
		size_t found = result.find(str[i]);
		if ( found == string::npos )
			result = result + str[i];
		else
			continue;
	}
	return result;
}

int main() {
	string S;
	cin >> S;

	string unique_str = no_duplicate_char_string(S);
	
	for (int i = 0; i < MAX_LENGTH; ++i) {
		for (int j = 0; j < unique_str.length(); ++j) {
			string candidate_str = unique_str + string(i, unique_str[j]);

			//cout << "start : " << candidate_str << endl;

			// sort??  for smallest A?
			do {
				//cout << candidate_str << endl;
				if (S == merge(candidate_str, reverse(candidate_str.begin(), candidate_str.end()))) {
					cout << S;
				}
			} while (next_permutation(candidate_str.begin(), candidate_str.end()));
		}
		
	}

	cin >> S;
	return 0;
}

