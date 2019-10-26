#include "stdio.h"
#include "malloc.h"

//结构体长度声明
#define LEN_TREE  sizeof(struct TreeNode)
#define LEN_STACK  sizeof(struct stack)
#define LEN_LINK  sizeof(struct link)
//树结构体
typedef struct TreeNode *Bintree;
typedef Bintree Position;
typedef struct TreeNode {
	char data;
	Bintree left;
	Bintree right;
}TreeNode;
//堆栈结构体
typedef struct stack {
	//int data;
	struct TreeNode *tree;
	struct stack *next;
}stack;
//队列结构体
typedef struct link {
	struct TreeNode *tree;
	struct link *next;
}link;

void MakeTree(struct TreeNode* root);               //创建二叉树
//递归遍历
void PreOrderTraversal(struct TreeNode* root);      
void InOrderTraversal(struct TreeNode* root);
void PostOrderTraversal(struct TreeNode* root);
//堆栈遍历
void PreStcakTraversal(struct TreeNode* root);
void InStcakTraversal(struct TreeNode* root);
void PostStcakTraversal(struct TreeNode* root);
//队列遍历
void LayerLinkTraversal(struct TreeNode* root);
//堆栈出入栈
void push(TreeNode *tree);
struct TreeNode * pop(void);
//队列出入列
void append(struct TreeNode* tree);
struct TreeNode* delet(void);


struct stack *top; //堆栈的顶端
struct link *head; //队列头
struct link *tail; //队列尾

int main() {
	//创建二叉树根
	struct TreeNode *root;
	root = (struct TreeNode*)malloc(LEN_TREE);
	//创建堆栈顶部
	top = (struct stack*)malloc(LEN_STACK);
	top->next = NULL;
	top->tree = NULL;
	//创建队列头尾
	head = (struct link*)malloc(LEN_LINK);
	tail = (struct link*)malloc(LEN_LINK);
	tail->next = head;
	head->tree = NULL;
	tail->tree = NULL;
	//生成二叉树
	MakeTree(root);
	//二叉树遍历
	printf("\n先序递归遍历..\n");
	PreOrderTraversal(root);
	printf("\n中序递归遍历..\n");
	InOrderTraversal(root);
	printf("\n后序递归遍历..\n");
	PostOrderTraversal(root);
	printf("\n先序堆栈遍历..\n");
	PreStcakTraversal(root);
	printf("\n中序堆栈遍历..\n");
	InStcakTraversal(root);
	//printf("\n后序堆栈遍历..\n");
	//PostStcakTraversal(root);
	printf("\n层序队列遍历..\n");
	LayerLinkTraversal(root);
	//函数尾
	printf("\nThe_end..\n");
	while (1);
	return 0;
}
/*
        A
     /     \
    B       C
  /   \   /   \
 D     F G     I
      /   \
     E     H
*/
//创建二叉树
void MakeTree(struct TreeNode* root) {
	struct TreeNode *B;
	struct TreeNode *C;
	struct TreeNode *D;
	struct TreeNode *E;
	struct TreeNode *F;
	struct TreeNode *G;
	struct TreeNode *H;
	struct TreeNode *I;

	B = (struct TreeNode*)malloc(LEN_TREE);
	C = (struct TreeNode*)malloc(LEN_TREE);
	D = (struct TreeNode*)malloc(LEN_TREE);
	E = (struct TreeNode*)malloc(LEN_TREE);
	F = (struct TreeNode*)malloc(LEN_TREE);
	G = (struct TreeNode*)malloc(LEN_TREE);
	H = (struct TreeNode*)malloc(LEN_TREE);
	I = (struct TreeNode*)malloc(LEN_TREE);

	root->data = 'A';
	B->data = 'B';
	C->data = 'C';
	D->data = 'D';
	E->data = 'E';
	F->data = 'F';
	G->data = 'G';
	H->data = 'H';
	I->data = 'I';
	
	root->left = B;
	root->right = C;
	B->left = D;
	B->right = F;
	C->left = G;
	C->right = I;
	D->left = NULL;
	D->right = NULL;
	F->left = E;
	F->right = NULL;
	G->left = NULL;
	G->right = H;
	I->left = NULL;
	I->right = NULL;
	E->left = NULL;
	E->right = NULL;
	H->left = NULL;
	H->right = NULL;
}
//先序遍历 递归 ->A->B->D->F->E->C->G->H->I
void PreOrderTraversal(struct TreeNode* root) {
	if (root) {
		printf("->%c", root->data);
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}
//中序遍历 递归
void InOrderTraversal(struct TreeNode* root) {
	if (root) {
		InOrderTraversal(root->left);
		printf("->%c", root->data);
		InOrderTraversal(root->right);
	}
}
//后序遍历 递归
void PostOrderTraversal(struct TreeNode* root) {
	if (root) {
		PostOrderTraversal(root->left);
		PostOrderTraversal(root->right);
		printf("->%c", root->data);
	}
}
//入栈
void push(TreeNode *tree) {

	struct stack *p;
	p = (struct stack*)malloc(LEN_STACK);
	
	p->tree = tree;
	p->next = top->next;
	top->next = p;
}
//出栈
struct TreeNode * pop(void) {
	if (top->next == NULL) {
		return NULL;
	}
	struct stack *p;
	struct TreeNode *tree;
	p = top->next;
	top->next = p->next;


	//free(p);
	//printf("->%c", data);
	tree = p->tree;
	free(p);
	return tree;
}
//堆栈先序
void PreStcakTraversal(struct TreeNode* root) {
	struct TreeNode *T;
	T = (struct TreeNode*)malloc(LEN_TREE);
	T = root;
	while (T != NULL || top->next != NULL) {
		while (T != NULL) {
			printf("->%c", T->data);
			push(T);
			if (T->left != NULL)
				T = T->left;
			else
				T = NULL;
		}
		if (top->next != NULL) {
			T = pop();
			if (T->right != NULL)
				T = T->right;
			else
				T = NULL;

		}
	}
}
//堆栈中序
void InStcakTraversal(struct TreeNode* root) {
	struct TreeNode *T;
	T = (struct TreeNode*)malloc(LEN_TREE);
	T = root;
	while (T != NULL || top->next != NULL) {
		while (T != NULL) {
			push(T);
			if (T->left != NULL)
				T = T->left;
			else
				T = NULL;
		}
		if (top->next != NULL) {
			T = pop();
			printf("->%c", T->data);
			if (T->right != NULL)
				T = T->right;
			else
				T = NULL;
		}
	}
}
//堆栈后序
void PostStcakTraversal(struct TreeNode* root) {
	struct TreeNode *T;
	T = (struct TreeNode*)malloc(LEN_TREE);
	T = root;
	while (T != NULL || top->next != NULL) {
		while (T != NULL) {
			push(T);
			if (T->left != NULL)
				T = T->left;
			else
				T = NULL;
		}
		if (top->next != NULL) {	
			T = pop();	
			if (T->right != NULL) {
				T = T->right;
			}
			else {
				T = NULL;
			}
		}
	}
}
//队列入列
void append(struct TreeNode* tree) {
	struct link *p1;
	p1 = (struct link*)malloc(LEN_LINK);
	head->tree = tree;
	head->next = p1;
	head = p1;

}
//队列出列
struct TreeNode* delet(void) {
	struct TreeNode *p;
	if (tail->next != head) {
		tail = tail->next;
		p = tail->tree;
	}
	return p;
}
//队列层序遍历
void LayerLinkTraversal(struct TreeNode* root) {
	struct TreeNode* tree;
	append(root);
	while (tail->next != head) {
		tree = delet();
		printf("->%c", tree->data);
		if (tree->left) {
			append(tree->left);
		}
		if (tree->right) {
			append(tree->right);
		}
	}
}

