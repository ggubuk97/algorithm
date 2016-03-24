/*
https://www.hackerrank.com/challenges/reverse-shuffle-merge

merge는 아래의 site를 참고하였다.
http://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

static const int alphabet_num = 26;

vector<string> merge_str_v;
vector<string> shuffle_A_v;
vector<string> final_str_v;

string find_alphabetical_string(const string& str)
{
    int alphabet[alphabet_num] = {0};
    string divided_str;
    for (int i = 0; i < str.length(); ++i) {
        alphabet[str[i] - 'a']++;
    }

    for (int i =0; i < alphabet_num; ++i) {
        if (alphabet[i] != 0) {
            divided_str = divided_str + string(alphabet[i]/2, i + 'a'); // 2n -> n
        }
    }

    //cout << "divided_str : " << divided_str << endl;
    return divided_str;
}


void merge(string first, string second, string& eachString, int m, int n, int i)
{
    if (m == 0 && n == 0) {
        //cout << "eachString : " << eachString << endl;
        merge_str_v.push_back(eachString);
    }

    if (m != 0) {
        eachString[i] = first[0];
        merge(string(first, 1, first.length()), second, eachString, m - 1, n, i+1);
    }

    if (n != 0) {
        eachString[i] = second[0];
        merge(first, string(second, 1, second.length()), eachString, m, n - 1, i+1);
    }
}


int main() {

    string S;
    cin >> S;
    bool found = false;

    string divided_str = find_alphabetical_string(S);
    string copy = divided_str;

    do {
        for (int j = 0; j < divided_str.size(); j++) {
            string eachString = "";
            eachString.resize(copy.size()*2);

            merge_str_v.clear();
            merge(copy, divided_str, eachString, copy.length(), divided_str.length(), 0);
        }

        if (find(merge_str_v.begin(), merge_str_v.end(), S) != merge_str_v.end()) {
            string rev_str = divided_str;
            reverse(rev_str.begin(), rev_str.end());
            final_str_v.push_back(rev_str);
            //cout << "Added to final_str_v : " << rev_str << endl;
            found = true;
            break;
        }
        if (found) break;
    } while (next_permutation(divided_str.begin(), divided_str.end()));

    sort(final_str_v.begin(), final_str_v.end());

    // Test
    for (int i = 0; i < final_str_v.size(); ++i) {
        //cout << "final string vector : " << final_str_v[i] << endl;
    }

    // solution
    reverse(final_str_v[0].begin(), final_str_v[0].end());
    cout << final_str_v[0] << endl;

    return 0;
}
