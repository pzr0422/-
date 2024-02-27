//˳���vector�ִ�
#include <stdio.h>
#include <stdlib.h>
typedef struct vector{
	int* data;//����Ԫ�صĴ洢�� 
	int count;//˳��������е�Ԫ������ 
	int size;//˳����������� 
}vector;

//����һ���������Ϊn��˳��� 
vector* getNewVector(int n){
	int *p = (int*)malloc(n*sizeof(int));
	vector *v = (vector*)malloc(sizeof(vector));
	v->size = n;
	v->data = p;
	v->count = 0;
	return v;
}

//���ݲ���
int expand(vector *v){
	if(!v) return 0;
	int *tool = (int *)realloc(v->data, 2*sizeof(int)*v->size);
	//ʹ��realloc������������
	//realloc����ԭ�����Ҳ�������һ�����ݺ�Ŀռ䣬�򷵻�NULL��ԭ��ַ���� 
	if(tool==NULL) {
		return 0;
	}
	v->data = tool;
	v->size*=2;
	return 1; 
}
 
int insert(vector *v, int pos, int val){
	//��posλ�ò�����Ҫ�������ʧ�� ���жϺϷ��ԣ� 
	if(pos<0||pos>=v->count||!expand(v)) return 0;
	//�����������򷵻�0 
	if(v->size == v->count) return 0;
	//��λ 
	for(int i = v->count-1; i>=pos; i--){
		v->data[i+1] = v->data[i];
	}
	v->data[pos] = val;
	v->count++;
	return 1;
}

int erase(vector *v, int pos){
	//�жϺϷ��� 
	if(pos <0 || pos >= v->count) return 0;
	//����գ���ɾ��ʧ�� 
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



















