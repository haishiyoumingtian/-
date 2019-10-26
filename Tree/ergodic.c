#include "stdio.h"
#include "malloc.h"

//�ṹ�峤������
#define LEN_TREE  sizeof(struct TreeNode)
#define LEN_STACK  sizeof(struct stack)
#define LEN_LINK  sizeof(struct link)
//���ṹ��
typedef struct TreeNode *Bintree;
typedef Bintree Position;
typedef struct TreeNode {
	char data;
	Bintree left;
	Bintree right;
}TreeNode;
//��ջ�ṹ��
typedef struct stack {
	//int data;
	struct TreeNode *tree;
	struct stack *next;
}stack;
//���нṹ��
typedef struct link {
	struct TreeNode *tree;
	struct link *next;
}link;

void MakeTree(struct TreeNode* root);               //����������
//�ݹ����
void PreOrderTraversal(struct TreeNode* root);      
void InOrderTraversal(struct TreeNode* root);
void PostOrderTraversal(struct TreeNode* root);
//��ջ����
void PreStcakTraversal(struct TreeNode* root);
void InStcakTraversal(struct TreeNode* root);
void PostStcakTraversal(struct TreeNode* root);
//���б���
void LayerLinkTraversal(struct TreeNode* root);
//��ջ����ջ
void push(TreeNode *tree);
struct TreeNode * pop(void);
//���г�����
void append(struct TreeNode* tree);
struct TreeNode* delet(void);


struct stack *top; //��ջ�Ķ���
struct link *head; //����ͷ
struct link *tail; //����β

int main() {
	//������������
	struct TreeNode *root;
	root = (struct TreeNode*)malloc(LEN_TREE);
	//������ջ����
	top = (struct stack*)malloc(LEN_STACK);
	top->next = NULL;
	top->tree = NULL;
	//��������ͷβ
	head = (struct link*)malloc(LEN_LINK);
	tail = (struct link*)malloc(LEN_LINK);
	tail->next = head;
	head->tree = NULL;
	tail->tree = NULL;
	//���ɶ�����
	MakeTree(root);
	//����������
	printf("\n����ݹ����..\n");
	PreOrderTraversal(root);
	printf("\n����ݹ����..\n");
	InOrderTraversal(root);
	printf("\n����ݹ����..\n");
	PostOrderTraversal(root);
	printf("\n�����ջ����..\n");
	PreStcakTraversal(root);
	printf("\n�����ջ����..\n");
	InStcakTraversal(root);
	//printf("\n�����ջ����..\n");
	//PostStcakTraversal(root);
	printf("\n������б���..\n");
	LayerLinkTraversal(root);
	//����β
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
//����������
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
//������� �ݹ� ->A->B->D->F->E->C->G->H->I
void PreOrderTraversal(struct TreeNode* root) {
	if (root) {
		printf("->%c", root->data);
		PreOrderTraversal(root->left);
		PreOrderTraversal(root->right);
	}
}
//������� �ݹ�
void InOrderTraversal(struct TreeNode* root) {
	if (root) {
		InOrderTraversal(root->left);
		printf("->%c", root->data);
		InOrderTraversal(root->right);
	}
}
//������� �ݹ�
void PostOrderTraversal(struct TreeNode* root) {
	if (root) {
		PostOrderTraversal(root->left);
		PostOrderTraversal(root->right);
		printf("->%c", root->data);
	}
}
//��ջ
void push(TreeNode *tree) {

	struct stack *p;
	p = (struct stack*)malloc(LEN_STACK);
	
	p->tree = tree;
	p->next = top->next;
	top->next = p;
}
//��ջ
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
//��ջ����
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
//��ջ����
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
//��ջ����
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
//��������
void append(struct TreeNode* tree) {
	struct link *p1;
	p1 = (struct link*)malloc(LEN_LINK);
	head->tree = tree;
	head->next = p1;
	head = p1;

}
//���г���
struct TreeNode* delet(void) {
	struct TreeNode *p;
	if (tail->next != head) {
		tail = tail->next;
		p = tail->tree;
	}
	return p;
}
//���в������
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

