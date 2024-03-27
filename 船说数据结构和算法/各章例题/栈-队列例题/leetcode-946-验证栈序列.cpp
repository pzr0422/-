// leetcode-946-验证栈序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int x = 0;
		int n = pushed.size();
		for(int i = 0; i < n; i++){
			//根据出栈序列的元素不停地进栈 
			if(s.empty() || s.top() != popped[i]){
				while(x < pushed.size() && pushed[x] != popped[i]){
					s.push(pushed[x++]);
				}
				//压完了所有元素仍然没有找到popped[i]--直接判断非法 
				if(x == pushed.size()) return false;
				//此时push[x]恰好=popped[i] 
				s.push(pushed[x++]);
			}
			s.pop();
		}
		return true;
    }
}; 
