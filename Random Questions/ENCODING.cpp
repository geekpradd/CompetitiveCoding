#include <bits/stdc++.h>
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

int absmod(int val){
	int base = val%MOD;
	if(base >= 0){
		return base;
	}
	else {
		return (base + MOD);
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
				cur_count = absmod(cur_count + count[i-1][d]);
				cur_count2 = absmod(cur_count2 + count[i-2][d]);
			}
			if (i==2){
				cur_count2 = 1;
			}
			for (int d=0; d<=9; ++d){
				int tot_sum = 0;
				count[i][d] = 0;
				for (int f = 0; f<=9; ++f){
					tot_sum = absmod(tot_sum + sum[i-1][f]);
					count[i][d] = absmod(count[i][d] + count[i-1][f]);
				}
				sum[i][d] = absmod((d*pow10(i-1)*cur_count)%MOD - (d*pow10(i-2)*cur_count2)%MOD + tot_sum%MOD);
				
			}
		}

		// sum[i][d]: sum for all numbers of length i with first digit d

		int vr = 0;
		int pointer = 1;
		int gen_num[nr+1];
		gen_num[0] = 0;
		int prev_digit = -1;

		while (pointer <= nr){

			int digit = (r[nr-pointer] - '0');

			gen_num[pointer] = absmod(gen_num[pointer-1] + pow10(pointer-1)*digit);
			
			vr = absmod(vr + (digit*pow10(pointer-1)*(gen_num[pointer-1]+1)));
			for (int i=1; digit-i>=0; ++i){
				vr = absmod(vr + sum[pointer][digit-i]);
			}
			if (prev_digit == digit){
				vr = absmod(vr - (digit*pow10(pointer-2)*(gen_num[pointer-2]+1)));
			}
			else if(prev_digit > digit){
				vr = absmod(vr - (digit*pow10(2*pointer-4)));
			}


			pointer++;
			prev_digit = digit;
		}


		int vl = 0;
		int pointer2 = 1;
		int gen_num2[nl+1];
		gen_num2[0] = 0;
		int prev_digit2 = -1;

		while (pointer2 <= nl){

			int digit = (l[nl-pointer2] - '0');

			gen_num2[pointer2] = absmod(gen_num2[pointer2-1] + pow10(pointer2-1)*digit);
			
			vl = absmod(vl + digit*pow10(pointer2-1)*(gen_num2[pointer2-1]+1));
			for (int i=1; digit-i>=0; ++i){
				vl = absmod(vl + sum[pointer2][digit-i]);
			}
			if (prev_digit2 == digit){
				vl = absmod(vl -(digit*pow10(pointer2-2)*(gen_num2[pointer2-2]+1)));
			}
			else if(prev_digit2 > digit){
				vl = absmod(vl - (digit*pow10(2*pointer2-4)));
			}

			pointer2++;
			prev_digit2 = digit;
		}

		// we need to add f(l) to the expression 
		int f_l = 0;
		int j = 1;
		int prev = -1;

		while (j <= nl){
			int digit = (l[nl-j]-'0');
			f_l = absmod(f_l + (digit*pow10(j-1)));

			if (prev == digit){
				f_l =  absmod(f_l - (digit*pow10(j-2)));
			}

			j++;
			prev = digit;
		}

		cout << absmod(vr - vl + f_l) << endl;
	}

	return 0;
}