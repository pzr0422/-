// leetcode-844-比较含退格的字符串
class Solution{
    public:
        bool backspaceCompare(string s, string t){
            stack<char> s1, s2;
            for(int i = 0; s[i]; i++){
            	if(s[i] == '#') {
            		if(!s1.empty()) s1.pop();
				}
            	else s1.push(s[i]);
			}
			for(int i = 0; t[i]; i++){
            	if(t[i] == '#') {
            		if(!s2.empty()) s2.pop();
				}
            	else s2.push(t[i]);
			}
			if(s1.size() != s2.size()) return false;
			while(!s1.empty()){
				if(s1.top() != s2.top()) return false;
				s1.pop();
				s2.pop();
			}
			return true;
        }
};






















/*
#include <bits/stdc++.h>
using namespace std;
bool backspaceCompare(char* s, char* t) {
    deque<char> dq_1, dq_2;
	while(*s){
		if(*s != '#')dq_1.push_back(*s);
		else {
			if(!dq_1.empty()) dq_1.pop_back();
		}
		s++;
	}
	while(*t){
		if(*t != '#')dq_2.push_back(*t);
		else {
			if(!dq_2.empty()) dq_2.pop_back();
		}
		t++;
	}
	if(dq_1.size() != dq_2.size()) return false;
	while(!dq_1.empty()){
		if(dq_1.front() != dq_2.front()) return false;
		else {
			dq_1.pop_front();
			dq_2.pop_front();
		}
	}
	return true;
} 
*/

