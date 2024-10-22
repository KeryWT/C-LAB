#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int val;
  struct treenode *left_child;
  struct treenode *right_child;
} treenode;
treenode *createnode(int value) {
  treenode *result = malloc(sizeof(treenode));
  if (result == NULL) {
    printf(
        "Error while trying to allocate memory for the node inside 'create'");
    return NULL;
  }

  result->left_child = NULL;
  result->right_child = NULL;
  result->val = value;
  return result;
}

void printTabs(){

}

void printTree(treenode * root){
  if (root = NULL){
    printf("EMPTY TREE\n");
    return;
  }
  printf("value = %d", root->val);
  printf("left\n");
  printTree(root->left_child);
  printf("right\n");
  printTree(root->right_child);
  printf("Done\n");
}

int main(void) {
  treenode *n1 = createnode(10);
  treenode *n2 = createnode(11);
  treenode *n3 = createnode(12);
  treenode *n4 = createnode(13);
  treenode *n5 = createnode(14);

  n1->left_child = n2;
  n1->right_child = n3;
  n3->left_child = n4;
  n3->right_child = n5;

  printTree(n1);
  free(n1);
  free(n2);
  free(n3);
  free(n4);
  free(n5);

}
