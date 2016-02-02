#include <stdio.h>
#include <stdlib.h>

typedef struct Tree *Node;
struct Tree
{
	int X;
	Node left;
	Node right;
};

Node makeOne(Node T);   //创建一个子节点
Node find(Node T, int X);   //查找元素X
Node insert(Node T, int X); //插入元素X
Node delete(Node T, int X); //删除元素X
Node findMin(Node T);
//测试用例
int main(){
	int X=0;
	struct Tree T;
	T.left=NULL;
	T.right=NULL;
	makeOne(&T);
	printf("请输入要插入的正整数（必须含有5），用空格分隔，用 -1 结束。\n");
	while(1)
	{
		scanf("%d",&X);
		if(X==-1)
			break;
		insert(&T,X);
	}
	printf("默认删除元素5\n");
	delete(&T,5);
	printf("Delete finished!!!\n");
	return 0;
}

Node makeOne(Node T)
{
	if(T!=NULL)
	{
		makeOne(T->left);
		makeOne(T->right);
	}
	return NULL;
}
Node find(Node T, int X)
{
	if(T==NULL)
	{
		return NULL;
	}else
	if(X<T->X)
	{
		return find(T->left,X);
	}else
	if(X>T->X)
	{
		return find(T->right,X);
	}
	else return T;
}

Node findMin(Node T)
{
	int min=T->X;
}
//比较X和节点对应元素的大小，直到找到合适的位置再插入
Node insert(Node T, int X)
{
	if(T==NULL)
	{
		T=malloc(sizeof(struct Tree));
		if(T==NULL)
		{
			printf("Out of space");
		}
		else
		{
			T->X=X;
			T->left=NULL;
			T->right=NULL;
			printf("Insert Finished!!!\n");
		}
	}else
	if(X<T->X)
	{
		T->left=insert(T->left,X);
	}else
	if(X>T->X)
	{
		T->right=insert(T->right,X);
	}
	return T;
}
/*
 *找到要删除的节点
 *寻找该节点的最小右子节点元素，用该元素替换要删除节点的元素
 *递归进行
 */
Node delete(Node T, int X)
{
	Node min;
	if(T==NULL)
	{
		printf("ERROR:There is no X!!!\n");
	}else
	if(X<T->X)
	{
		T->left=delete(T->left,X);
	}else
	if(X>T->X)
	{
		T->right=delete(T->right,X);
	}
	else
   //找到了要删除的节点,且左右子节点都不为空
	if(T->left&&T->right)		
	{
		min=findMin(T->right);
		T->X=min->X;
		T->right=delete(T->right,T->X);
	}
	else
   //找到了要删除的节点,且左右子节点有一个为空
	{
		min=T;
		if(T->left==NULL)
			T=T->right;
		else if(T->right==NULL)
			T=T->left;
		free(min);
	}
	return T;
}