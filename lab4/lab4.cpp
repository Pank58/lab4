#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;


struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}

int find_input(struct Node* r, int find_data, int count_fun, int m) {
	if (r->data == find_data) {
		count_fun += 1;
	}
	if (m < count_fun) {
		m=count_fun;
	}
	if( r->left!=NULL){
		m=find_input(r->left, find_data, count_fun, m);
	}
	if(r->right != NULL)
	{
		m=find_input(r->right, find_data, count_fun, m);
	}
	
	return m;
}

void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}




int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1, count=0;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &D);
		if (D == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);
	printf("Введите число которое необходимо найти: ");
	scanf_s("%d", &D);
	count=find_input(root, D, count, 0);
	printf("Элемент встретился %d раз", count);


	printf("\nконец");
	scanf_s("%d", &D);
	return 0;
}
