// leetcode-202-快乐数 链表思想 取出一个正整数的各位数字 
// 算出x的各位数字的平方和 
int getNext(int x){
	int y = 0;
	while(x){
		int ge = x % 10;
		y += ge * ge;
		x /= 10;
	}
	return y;
}

bool isHappy(int n){
	//思维逻辑上的p,q指针，使用快慢指针法确定是否无限循环 
	int p = n;
	int q = n;
	while(q != 1){
		p = getNext(p);//移1步 
		q = getNext(getNext(q));//移2步
		if(p == q && q != 1) return false; 
	}
	return true;
} 
