//HaiZeiOJ-595
//碰到需要遍历栈的情况，那么就需要用vector或数组来模拟，这样会更简便 
#include <bits/stdc++.h>
using namespace std;
int main(void){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int flag = 0;//表示要找的函数在不在 
	int n; cin>>n;
	vector<string> ops(n), s;//s为用vector实现的逻辑上的栈 
	for(int i = 0; i < n; i++){
		cin>>ops[i];
	}
	string target;
	cin>>target;
	for(int i = 0; i < n; i++){
		if(ops[i] == target){
			flag = 1;
			s.push_back(target);
			break;
		}
		if(ops[i] == "return") s.pop_back();
		//其他函数 
		else{
			s.push_back(ops[i]);
		}
	}
	if(flag){
		for(int i = 0; i < s.size(); i++){
			if(i) cout << "->";
			cout << s[i];
		} 
	}
	else{
		cout << "NOT REFERENCED";
	}
}

/* 
using namespace std;
int main(void){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	stack<string> s;
	int n;cin>>n;
	for(int i = 0; i < n; i++){
		string str;cin>>str;
		if(str == "return") s.pop();
		else s.push(str);
	}
	string str;
	cin>>str;
	vector<string> v;
	while(!s.empty()){
		v.push_back(s.top());
		s.pop();
	}
	for(int i = v.size() - 1; i >= 1 && v[i] != str; i--){
		cout << v[i] << "->";
	}
	cout << v[0];
	return 0;
} 
*/





















