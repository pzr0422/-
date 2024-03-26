// HZOJ-263-»ð³µ½øÕ»
#include <bits/stdc++.h>
using namespace std;

bool isValid(int a[], int n){
	stack<int> s;
	int x = 1;
	for(int i = 0; i < n; i++){
		if(s.empty() || s.top() < a[i]){
			while(x <= a[i]){
				s.push(x);
				x++;
			}
		}
		if(s.empty() || s.top() != a[i]) return false;
		s.pop();
	}
	return true;
}

int main(void){
	int n;
	int a[25];
	int count = 20;
	cin >> n;
	for(int i = 0; i < n; i++){
		a[i] = i + 1;
	}
	do{
		if(isValid(a, n)){
			for(int i = 0; i < n; i++){
				cout << a[i];
			}
			cout << "\n";
			count--;
		}
	}while(next_permutation(a, a + n) && count);
	return 0;
} 
