#include <bits/stdc++.h>

typedef struct Node {
	int key;
	struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int val){
	Node *p = (Node *)malloc(sizeof(Node));
	p->key = val;
	p->lchild = p->rchild = NULL;
	return p;
}

//返回根节点地址 
Node *insert(Node *root, int val){
	//边界条件 
	if(root == NULL) return getNewNode(val);
	//递归，找到空节点-->插入新节点；当前节点不为空-->直接返回 
	if(rand() % 2) root->lchild = insert(root->lchild, val);
	else root->rchild = insert(root->rchild, val);	
	return root;
}

Node *queue[12];
int head = 0, tail = 0;
//广度优先遍历（层序遍历，使用队列） 
void bfs(Node *root){
	printf("BFS:\n");
	queue[0] = root;
	tail++;
	while(head < tail){
		Node *node = queue[head];
		printf("\nNode:%d\n", node->key);
		if(node->lchild) {
			queue[tail++] = node->lchild;
			printf("\t%d->%d(left)", node->key, node->lchild->key);
		}
		if(node->rchild) {
			queue[tail++] = node->rchild;
			printf("\t%d->%d(right)", node->key, node->rchild->key);
		}
		head++;
	}
	return;
}

//深度优先遍历（使用栈，递归解决） 
//记录节点入栈出栈的时间戳tot
int tot = 0; 
void dfs(Node *root){
	//边界条件
	if(root == NULL) return; 
	int start = 0, end = 0;
	tot++;
	start = tot;
	//开始从此节点的左孩子开始遍历 
	if(root->lchild) dfs(root->lchild);
	if(root->rchild) dfs(root->rchild);
	//直到左右子树都为空树时，停止遍历 
	tot++;
	end = tot;
	printf("%d : [%d, %d]\n", root->key, start, end);
	return;
} 

void clear(Node *root){
	if(root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return; 
}

int main(void){
	srand(time(0));
	#define MAX_NODE 10
	//根节点地址初始化为空地址 
	Node *root = NULL;
	for(int i = 0; i < MAX_NODE; i++){
		root = insert(root, rand() % 100); 
	}
	bfs(root);
	printf("\n\n");
	printf("DFS:\n");
	dfs(root);
	clear(root);
	return 0;
}





















