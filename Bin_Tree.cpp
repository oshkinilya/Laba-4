#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct Node {
	struct Node* left;
	struct Node* right;
	int data = 0;
};
struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node*));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;


		if (root == NULL)
			return r;
		if (data > root->data)
			root->left = r;
		else
			root->right = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
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
		printf("   ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}



void search(struct Node* r, int data) {
	if (r == NULL)
		return;
	if (r->data < data) {
		search(r->right, data);
	}
	else if (r->data > data) {
		search(r->left, data);
	}
	else if (r->data == data) {
		printf("%d\n", r->data);
	}
}


int count(Node* root, int k) {
	if (root == 0)
		return 0;
	return (root->data == k) + count(root->left, k) + count(root->right, k);
}


int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int D, numb;
	printf("Введите размер дерева: ");
	scanf_s("%d", &D);
	while (D)
	{
		root = CreateTree(root, root, rand() % 20);
		D--;
	}
	print_tree(root, 0);
	printf("Введите искомый элемент: ");
	scanf_s("%d", &D);
	search(root, D);
	numb = count(root, D);
	if (numb)
		printf("Найдено %d элементов", numb);
	else
		printf("Элементы не найдены");
	return 0;
}
