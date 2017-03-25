#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    vector<string> vec;
    map <int, vector<string> > m;
    cin >> N;
    string s[100];
    for (int i = 0; i < N; i++)
	cin >> s[i];
    for (int i = 1; i < 16; i++)
	m.insert(pair<int, vector<string> >(i, vec));
    cout << s[0] << endl;
    for (int i = 0; i < N; i++){
	m[i].push_back(s[i]);
    }
    for (int i = 1; i < 16; i++)
	if (m[i].size() != 0){
	    cout << i << endl;
	    for (int j = 0; j < m[i].size(); i++)
		cout << m[i][j] << endl;}
    return 0;
}