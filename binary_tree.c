#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char name[30];
	int age;
	struct data *left, *right;
};


struct data *newData(char name[], int age){
	//proses pembuatan data baru
	struct data	*temp = (struct data*)malloc(sizeof(struct data));
	strcpy(temp->name, name);
	temp->age = age;
	temp->right = temp->left = NULL;
	return temp;
}

struct data *push(struct data *root, char name[], int age){
	//cek jika root masih kosong dia kan membuat data baru
	if(!root) return newData(name, age);
	
	//validasi untuk merecursive dirinya sendiri hingga mencapain left/right nya NULL lalu ia akan membuat data baru 
	if(strcmp(name, root->name) < 0) root->left = push(root->left, name, age);
	else if(strcmp(name, root->name) > 0) root->right = push(root->right, name, age);
	return root;
}


/*
	cara kerja inorder
	-cek kiri
	-print
	-cek kanan
*/

void inorder(struct data *root){
	if(root){
		inorder(root->left);
		printf("Name: %s | Umur: %d\n", root->name, root->age);
		inorder(root->right);
	}
}


/*
	cara kerja preorder
	-print parentnya terlebih dahulu
	-cek kiri
	-cek kanan
*/
void preorder(struct data *root){
	if(root){
		printf("Name: %s | Umur: %d\n", root->name, root->age);
		preorder(root->left);
		preorder(root->right);
	}
}


/*
	cara kerja postorder
	-cek kiri
	-cek kanan
	-print akan dilakukan terakhir
*/
void postorder(struct data *root){
	if(root){
		postorder(root->left);
		postorder(root->right);
		printf("Name: %s | Umur: %d\n", root->name, root->age);
	}
}



int main(){
	struct data *root = NULL;
	
	
	root = push(root, "syalala", 18);
	root = push(root, "mamam", 19);
	root = push(root, "ehehe", 12);
	root = push(root, "yolo", 7);
		
	
	inorder(root);
	printf("\n\n");
	
	preorder(root);
	printf("\n\n");
	
	postorder(root);
	printf("\n\n");
	
	return 0;
}


