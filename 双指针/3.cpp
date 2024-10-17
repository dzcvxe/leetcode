#include <iostream>
#include <string> 
#include <map>
using namespace std;
int lengthOfLongestSubstring(string s) {
	if(s.size() == 0) {
	    return 0;
	}
	int n = s.size(), i = 0, j = 0, ans = 1, kind = 1;
	map<char, int> mp;
	mp[s[0]] = 1;
	while(i < n && j < n - 1) {
	    j++;
	    mp[s[j]]++;
	    if(mp[s[j]] == 1){
	        ans = max(ans, j - i + 1);
	        kind++;
	    } else {
	        while(i < j) {
	            mp[s[i]]--;
	            if(mp[s[i]] == 0) {
	                kind--;
	            }
	            i++;
	            if(kind == j - i + 1) {
	                ans = max(ans, j - i + 1);
	                break;
	            }
	        }
	    }
	}
	return ans;
}
int main() {
	string s;
	cin >> s;
	int ans = lengthOfLongestSubstring(s);
	cout << ans;
	return 0;
} 
