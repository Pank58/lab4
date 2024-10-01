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

void find(struct Node* r, int find_data) {
	if (r->data == find_data) {
		printf("%d ", r->data);
		return;
	}
	else if(r->data < find_data && r->left!=NULL){
		printf("%d->", r->data);
		find(r->left, find_data);
	}
	else if(r->data > find_data && r->right != NULL)
	{
		printf("%d->", r->data);
		find(r->right, find_data);
	}
	else {
		printf("Тут его нет :(");
		return;
	}
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
	int D, start = 1;

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
	find(root, D);

	printf("\nконец");
	scanf_s("%d", &D);
	return 0;
}
