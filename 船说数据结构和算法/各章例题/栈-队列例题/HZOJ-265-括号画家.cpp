// HZOJ-265-括号画家
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
char str[MAX_N + 5];
int match[MAX_N + 5] = {0};//match[i]=0代表，第i个位置的括号没有与之匹配的括号；若match[i]=c，那么第i个位置的括号的匹配项下标为c 
stack<int> s;
int main(void){
	cin >> (str + 1);//使字符数组的下标从1开始，避开0以方便标记match数组 
	for(int i = 1; str[i]; i++){
		switch(str[i]){
			case '(':
			case '[':
			case '{':
				s.push(i);
				break;
			case ')':
				if(!s.empty() && str[s.top()] == '('){
					match[s.top()] = i;
					match[i] = s.top();
					s.pop();
				}
				else{
					s.push(i);//信息阻隔，如果此右括号不匹配，则说明前面的所有序列均非法 
				}
				break;
			case ']': 
				if(!s.empty() && str[s.top()] == '['){
					match[s.top()] = i;
					match[i] = s.top();
					s.pop();
				}
				else{
					s.push(i);//信息阻隔，如果此右括号不匹配，则说明前面的所有序列均非法 
				}
				break;
			case '}':
				if(!s.empty() && str[s.top()] == '{'){
					match[s.top()] = i;
					match[i] = s.top();
					s.pop();
				}
				else{
					s.push(i);//信息阻隔，如果此右括号不匹配，则说明前面的所有序列均非法 
				}
				break;
		}
	}
	//寻找最长序列
	int temp_ans = 0;
	int ans = 0;
	int i = 1;
	while(str[i]){
		//如果第i个位置有匹配的括号 
		if(match[i]){
			temp_ans += match[i] - i + 1;
			i = match[i] + 1;
		}
		//当前位置没有匹配的括号 
		else{
			i++;
			temp_ans = 0;
		}
		if(temp_ans > ans) ans = temp_ans;
	} 
	cout << ans;
	return 0;
}

