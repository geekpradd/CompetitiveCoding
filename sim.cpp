#include <bits/stdc++.h>
using namespace std;

signed main(){
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	double dh, dl, dr, k;  
	cin >>dh >> dl >> dr >> k;
	while (dh + dl + dr + k !=0){
		double l =0; double r = dr;
		double cur = (l+r)/2.0;
		double expr = k*(dr-cur)/sqrt((dr-cur)*(dr-cur) + dl*dl) - cur/sqrt(cur*cur + dh*dh);

		double ep = 1e-6;
		while (abs(expr)>ep){
			if (expr > 0){
				l = cur;
				cur = (cur+r)/2;
			}
			else {
				r = cur;
				cur = (cur+l)/2;
			}

			expr = k*(dr-cur)/sqrt((dr-cur)*(dr-cur) + dl*dl) - cur/sqrt(cur*cur + dh*dh);
		}	 

		cout << sqrt(cur*cur + dh*dh) + sqrt((dr-cur)*(dr-cur) + dl*dl) << endl;
		cin >> dh >> dl >> dr >> k;
	}

	return 0;
}