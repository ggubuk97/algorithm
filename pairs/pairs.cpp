#include <iostream>
#include <limits>
#include <set>
#include <numeric>
using namespace std;
/* Head ends here */

int pairs(set<int>& a,int k)
{
    int ans = 0;
    for (set<int>::iterator it = a.begin(); it != a.end(); ++it)
        if (a.find(*it + k) != a.end()) ans++;
    return ans;
}

/* Tail starts here */
int main()
{
    int res;
    
    int _a_size,_k;
    cin >> _a_size >> _k;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    set<int> _a;
    int _a_item;
    for(int _a_i = 0; _a_i < _a_size; _a_i++) {
        cin >> _a_item;
        _a.insert(_a_item);
    }
    
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}
