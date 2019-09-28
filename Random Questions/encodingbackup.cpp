#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int pow10(int exp){
	if (exp == 0){
		return 1;
	}
	if (exp % 2){
		exp--;
		return (10*pow10(exp/2)*pow10(exp/2))%MOD;
	}
	else {
		return (pow10(exp/2)*pow10(exp/2))%MOD;
	}
}

signed main(){
	int t; cin >> t;
	while (t--){
		int nl, nr;
		string l, r;
		cin >> nl >> l;
		cin >> nr >> r;
		int ml = max(nl, nr);

		int sum[ml+1][10], count[ml+1][10];

		for (int d=0; d<=9; ++d){
			sum[1][d] = d;
			count[1][d] = 1;
			count[0][d] = 0;
		}

		for (int i=2; i<=ml; ++i){
			int cur_count = 0;
			int cur_count2 = 0;
			for (int d=0; d<=9; ++d){
				cur_count += count[i-1][d];
				cur_count2 += count[i-2][d];
			}
			if (i==2){
				cur_count2 = 1;
			}
			for (int d=0; d<=9; ++d){
				int tot_sum = 0;
				count[i][d] = 0;
				for (int f = 0; f<=9; ++f){
					tot_sum += sum[i-1][f];
					count[i][d] += count[i-1][f];
				}
				sum[i][d] = ((d*pow10(i-1)*cur_count)%MOD - (d*pow10(i-2)*cur_count2)%MOD + tot_sum%MOD)%MOD;
				
			}
		}

		// processing NR
		

		// cout << vr << endl;

		int vl = 0;
		int curL2 = 1;
		int gen_num2[nl+1];
		gen_num2[0] = 0;


		while (curL2 <= nl){

			int digit = (l[nl-curL2] - '0');

			gen_num2[curL2] = (gen_num2[curL2-1] + pow10(curL2-1)*digit)%MOD;
			vl += (digit*pow10(curL2-1)*(gen_num2[curL2-1]+1))%MOD;

			if (digit != 0)
				vl += sum[curL2][digit-1];

			curL2++;
		}

		cout << vr - vl << endl;
	}
}