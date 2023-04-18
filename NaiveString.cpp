// Time Complexity : O(n^2)

#include<bits/stdc++.h>
using namespace std;

int main() {
	string text, pattern;
	cout << "Enter the text  : " << endl;
	cin >> text;
	cout << "Enter the pattern: " << endl;
	cin >> pattern;




	int i, j;
	for (i = 0; i <= (int)text.size() - (int)pattern.size(); i++) {
		for (j = 0; j < (int)pattern.size(); j++) {
			if (text[i + j] != pattern[j])break;
		}
		if (j == (int)pattern.size()) cout << "Pattern found at index:" << i << endl;
	}

}
