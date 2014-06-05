#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct student {
	int  matriculation;
	char name[20];
	int  notes[3];
} Student;

typedef struct avl_node {
  Student data;
  struct avl_node *left;
  struct avl_node *right;
} avl_node;

avl_node* right_to_right_rotation(avl_node *parent_node);
avl_node* right_to_left_rotation(avl_node *parent_node);
avl_node* left_to_left_rotation(avl_node *parent_node);
avl_node* left_to_right_rotation(avl_node *parent_node);
avl_node* balancing_tree(avl_node *node);
avl_node* insert(avl_node *root, Student student);
avl_node* create_node(Student student);
avl_node* find(avl_node* tree, int matriculation);
avl_node* free_tree(avl_node* tree);
avl_node* remove_node(avl_node *root, Student student); /*The "remove_node" function is not working properly, it is a failure of the library.*/

void display_in_order(avl_node *tree);
void display_pre_order(avl_node *tree);
void display_post_order(avl_node *tree);
