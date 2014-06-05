#include "avl.h"

/*Create empty tree*/
avl_node* create_empty_tree(){
  return NULL;
}

/*Empty node*/
int empty_node(avl_node *node){
  return (node == NULL);
}

/*Maximum*/
int maximum(int left_height, int right_height){
  return (left_height > right_height) ? left_height : right_height;
}

/*find Height*/
int find_height(avl_node *node){
  int height = 0;
  if (!empty_node(node)){
    height = 1 + maximum(find_height(node->left), find_height(node->right));
  }
  return height;
}

/*Difference between left right*/
int difference_between_left_right(avl_node *node){
  return find_height(node -> left) - find_height(node -> right);
}

/*Rotations*/
avl_node* right_to_right_rotation(avl_node *parent_node){
  avl_node *node;
  node = parent_node->right;
  parent_node->right = node->left;
  node->left = parent_node;
  return node;
}

avl_node* left_to_left_rotation(avl_node *parent_node){
  avl_node *node;
  node = parent_node->left;
  parent_node->left = node->right;
  node->right = parent_node;
  return node;
}

avl_node* right_to_left_rotation(avl_node *parent_node){
  avl_node *node;
  node = parent_node->right;
  parent_node->right = left_to_left_rotation(node);
  return right_to_right_rotation(parent_node);
}

avl_node* left_to_right_rotation(avl_node *parent_node){
  avl_node *node;
  node = parent_node->left;
  parent_node->left = right_to_right_rotation(parent_node);
  return left_to_left_rotation(parent_node);
}

/*Balancing Tree*/
avl_node* balancing_tree(avl_node *node){
  int balancing_factor = difference_between_left_right(node);
  if (balancing_factor > 1) {
    if (difference_between_left_right(node->left) >0)
      node = left_to_left_rotation(node);
    else
      node = left_to_right_rotation(node);
  }
  else if(balancing_factor < -1) {
    if(difference_between_left_right(node->right)>0)
      node = right_to_left_rotation(node);
    else
      node = right_to_right_rotation(node);
    }
  return node;
}

/*Insert*/
avl_node* insert(avl_node *root, Student student){
  if (empty_node(root)) {
    return create_node(student);
  }
  else if (student.matriculation < root->data.matriculation) {
    root->left = insert(root->left, student);
    root = balancing_tree(root);
  }
  else if (student.matriculation > root->data.matriculation) {
    root->right = insert(root->right, student);
    root = balancing_tree(root);
  }
  return root;
}

/*The "remove_node" function is not working properly,
 it is a failure of the library.*/
avl_node* remove_node(avl_node *root, Student student){
  if (empty_node(root)) {
    return root;
  }
  else if(student.matriculation == root->data.matriculation){
    avl_node* auxiliar_node = root;
    free(auxiliar_node);
    root = balancing_tree(root);
  }
  else if(student.matriculation < root->data.matriculation) {
    root->left = remove_node(root->left, student);
    root = balancing_tree(root);
  }
  else if(student.matriculation > root->data.matriculation) {
    root->right = remove_node(root->right, student);
    root = balancing_tree(root);
  }
  return root;
}

/*Create node*/
avl_node* create_node(Student student){
  avl_node* root = (avl_node*) malloc(sizeof(avl_node));
  root->data = student;
  root->left = NULL;
  root->right = NULL;
  return root;
}

/*Find*/
avl_node* find(avl_node* tree, int matriculation){
  if(empty_node(tree))
    return NULL;
  if(matriculation < tree->data.matriculation)
    return find(tree->left, matriculation);
  else if(matriculation > tree->data.matriculation)
    return find(tree->right, matriculation);
  else
    return tree;
}

/*Free tree*/
avl_node* free_tree(avl_node* tree){
  if(!empty_node(tree)){
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
  }
  return NULL;
}

/*Display*/
void display_in_order(avl_node *tree){
  if(empty_node(tree)){
    return;
  }
  else {
    display_in_order(tree->left);

    printf("%d\t", tree->data.matriculation);
    if(!empty_node(tree->left))
      printf("(L:%d)",tree->left->data.matriculation);
    if(!empty_node(tree->right))
      printf("(R:%d)",tree->right->data.matriculation);
    printf("\n");

    display_in_order(tree->right);
  }
}

void display_pre_order(avl_node *tree){
  if(empty_node(tree)){
    return;
  }
  else {
    printf("%d\t", tree->data.matriculation);
    if(!empty_node(tree->left))
      printf("(L:%d)",tree->left->data.matriculation);
    if(!empty_node(tree->right))
      printf("(R:%d)",tree->right->data.matriculation);
    printf("\n");

    display_pre_order(tree->left);
    display_pre_order(tree->right);
  }
}

void display_post_order(avl_node *tree){
  if(empty_node(tree)){
    return;
  }
  else {
    display_post_order(tree->left);
    display_post_order(tree->right);

    printf("%d\t", tree->data.matriculation);
    if(!empty_node(tree->left))
      printf("(L:%d)",tree->left->data.matriculation);
    if(!empty_node(tree->right))
      printf("(R:%d)",tree->right->data.matriculation);
    printf("\n");
  }
}
