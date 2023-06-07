#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
typedef struct BTNode* BinTree;
struct BTNode{
	char data;
	BinTree lchild;
	BinTree rchild;
};

void PostOrderTraverse(BinTree T){
	if(T == NULL)
		return; 
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout<<T->data;
}

BinTree CreateBTree(char a[],char b[],int n){ //先序序列a,中序序列b 
	int k;
	if(n<=0) return NULL;
	BinTree T = (BinTree)malloc(sizeof(BinTree));
	char root = a[0];
	T->data = root;
	for(k=0;k<n;k++){
		if(b[k] == root)
			break;
	}
	T->lchild = CreateBTree(a+1,b,k);
	T->rchild = CreateBTree(a+k+1,b+k+1,n-k-1);
	return T;
}

int main(){
	char a[101]; //先序序列 
	char b[101]; //中序序列 
	while(cin>>b>>a){
		BinTree T;
		int length = strlen(a);
		T = CreateBTree(a,b,length);
		PostOrderTraverse(T);
		cout<<endl;
	}
	return 0;
}

