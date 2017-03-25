#include <iostream>
#include <vector>
using namespace std;

int main(){
    int x;
    cin >> x;
    vector<bool> b(x+1, true);
    b[0] = false;
    b[1] = false;
    for (int i = 2; i < x+1; i++){
	if (b[i] == true) 
	    for (int j = i*i; j < x+1; j += i)
		if (j % i == 0){
		    b[j] = false;
		    }}
    int sum = 0;
    for (int i = 0; i < x + 1; i++ ) {
	    sum+= b[i];}
    cout << sum << endl;
    return 0;
}