#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;

	while (t--){
		string inp;
		cin >> inp;
		if (inp == "1"){
			cout << "1" << endl;
			continue;
		}
		if (inp[0]!='1'){
			bool diff = false;
			for (int i=1; i<inp.length(); ++i){
				if (inp[i]!='9')
					diff = true;
			}
			cout << (diff ? '1' : inp[0]);
			for (int i=1; i<inp.length(); ++i)
				cout << '9';

			cout << endl;
		}
		else {
			bool found = false; int c;
			for (int i=1; i<inp.length(); ++i){
				if (inp[i]!='0'){
					found = true;
					c = i;
					break;
				}
			}
			if (found){
				bool diff= false;
				for (int i=c+1; i<inp.length(); ++i){
					if (inp[i]!='9')
						diff = true;
				}
				cout << '1';
				for(int i=1; i<c;++i)
					cout << '0';
				char x = (diff ? inp[c] - 1 : inp[c]);
				cout << x;
				for (int i=c+1; i<inp.length(); ++i)
					cout << '9';
				cout << endl;
			}
			else {
				for (int i=1; i<inp.length(); ++i)
					cout << '9';

				cout << endl;
			}
		}
	}
}