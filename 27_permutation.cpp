# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
    	if(str.empty()) return allString;
        permutation(str, 0);
        // allString.erase(unique(allString.begin(), allString.end(), allString.end()));
        sort(allString.begin(), allString.end(), cmp);
        // cout << allString << endl;
        return allString;
    }
    void permutation(string str, decltype(str.size()) begin)
	{
		vector<string>::iterator it;
		if(begin == str.length())
		{
			//cout << str << endl;
			it = find(allString.begin(), allString.end(), str);
			if(it == allString.end())
			{
				// cout << "it == allString.end()" << endl;
				// cout << str << endl;
				allString.push_back(str);
				cnt++;
			}
		}
		else
		{
			for(decltype(str.size()) i = begin; i < str.length(); ++i)
			{
				char tmp = str[i];
				str[i] = str[begin];
				str[begin] = tmp;

				permutation(str, begin + 1);

				tmp = str[i];
				str[i] = str[begin];
				str[begin] = tmp;
			}

		}
	}

	static int cmp(string s1, string s2)
	{
		return s1.compare(s2) < 0;
	}
private:
	vector<string> allString;
	int cnt = 0;
};




int main()
{
	Solution solution;
	string str = "aa";
	vector<string> allString;
	allString = solution.Permutation(str);
	return 0;
}

// 运行时间：9ms

// 占用内存：468k