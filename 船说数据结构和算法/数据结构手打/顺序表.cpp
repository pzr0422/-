//顺序表vector手打
#include <stdio.h>
#include <stdlib.h>
typedef struct vector{
	int* data;//数据元素的存储区 
	int count;//顺序表中现有的元素数量 
	int size;//顺序表的最大容量 
}vector;

//创建一个最大容量为n的顺序表 
vector* getNewVector(int n){
	int *p = (int*)malloc(n*sizeof(int));
	vector *v = (vector*)malloc(sizeof(vector));
	v->size = n;
	v->data = p;
	v->count = 0;
	return v;
}

//扩容操作
int expand(vector *v){
	if(!v) return 0;
	int *tool = (int *)realloc(v->data, 2*sizeof(int)*v->size);
	//使用realloc函数进行扩容
	//realloc函数原理：若找不到这样一个扩容后的空间，则返回NULL，原地址保留 
	if(tool==NULL) {
		return 0;
	}
	v->data = tool;
	v->size*=2;
	return 1; 
}
 
int insert(vector *v, int pos, int val){
	//若pos位置不满足要求，则插入失败 （判断合法性） 
	if(pos<0||pos>=v->count||!expand(v)) return 0;
	//若表已满，则返回0 
	if(v->size == v->count) return 0;
	//移位 
	for(int i = v->count-1; i>=pos; i--){
		v->data[i+1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;
	return 1;
}

int erase(vector *v, int pos){
	//判断合法性 
	if(pos <0 || pos >= v->count) return 0;
	//若表空，则删除失败 
	if(v->count == 0) return 0;
	for(int i = pos + 1; i <= v->count - 1; i++){
		v->data[i-1] = v->data[i];
	}
	v->count--;
	return 1;
}

void clear(vector *v){
	if(!v) return ;
	free(v->data);
	free(v);
	return ;
}

void output_vector(vector *v){
	if(!v) return ;
	printf("Vector: ")
	for(int i = 0; i < v->count; i++){
		printf("%d", v->data[i]);
	}
	return ;
}

int main(void){
	
	return 0;
} 



















