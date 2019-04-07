#pragma once
# include"stdio.h"
# include"stdlib.h"

typedef struct tree {
	//the struct of tree
	char data;
	struct tree * Child_L;
	struct tree * Child_R;
}tree;

void haha(tree *t) {
	char word;
	scanf_s("%c", &word, sizeof(char));
	if(!t)
	t = (tree *)malloc(sizeof(tree));	
	t->data = word;
}

tree * creat_tree() {
	//creat a new tree
	tree *p;
	char word;
	scanf_s("%c", &word, sizeof(char));
	if (word == '#') {
		p = NULL;
	}
	else {
		p = (tree *)malloc(sizeof(tree));
		p->data = word;
		p->Child_L = creat_tree();
		p->Child_R = creat_tree();
	}
	return p;
}

void creat_tree(tree **t) {
	//creat a new tree
	char word;
	
	scanf_s("%c", &word, sizeof(char));
	if (word == '#') {
		*t = NULL;
	}
	else {
		*t = (tree *)malloc(sizeof(tree));
		(*t)->data = word;
		creat_tree(&((*t)->Child_L));
		creat_tree(&((*t)->Child_R));
	}
}

//void insert_tree(tree *t) {
//	//insert a new node for the tree
//}
//
//void delete_tree(tree *t) {
//	//delete a brach of the tree
//}

//int search_tree(tree s) {
//	//search a node in the tree
//	return 0;
//}


//tree * find_tree(tree *s) {
//	//find where can insert
//	return 0;
//}

void list_tree_last(tree *s) {
	//print all data of the tree
	if (s) {
		list_tree_last(s->Child_L);
		list_tree_last(s->Child_R);
		printf("%c\t", s->data);
	}
}
void list_tree_first(tree *s) {
	//print all data of the tree
	if (s) {
		printf("%c\t", s->data);
		list_tree_first(s->Child_L);
		list_tree_first(s->Child_R);
	}
}
void list_tree_middle(tree *s) {
	//print all data of the tree
	if (s) {
		list_tree_middle(s->Child_L);
		printf("%c\t", s->data);
		list_tree_middle(s->Child_R);
	}
}

