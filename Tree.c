/* Barney Dennis, bd0906, version A */
#include <stdio.h>
#include <stdlib.h>
char grab[20];
int count = 0;

typedef struct T {
  char      data;
  struct T *left;
  struct T *right;
} tree;


tree *make_node(char c, tree *l, tree *r) {
  tree *temp = malloc(sizeof(tree));

  temp->data = c;
  temp->left = l;
  temp->right = r;
  return temp;
}


tree *insert_tree(tree *root, char c) {

  if (root == NULL) {
    root = make_node(c, NULL, NULL);
  } else if (c < root->data) {
    root->left = insert_tree(root->left, c);
  } else {
    root->right = insert_tree(root->right, c);
  }
  return root;
}


tree *read_tree( void ) {
  int i = 1;
  char c;
  tree *tp = NULL;
  				
  c = getchar();
  grab[0] = c;
  while (c != '.') {
    tp = insert_tree(tp, c);
    c = getchar();
    grab[i] = c;
    i++; 
    count++;
  }
  return tp;
}

	

int balanced(tree *tp) {
	int countl = 0;
	int countr = 0;
	int i = 1;

	while (i<count) {

		if (grab[i]<grab[0]) countl++;
		else countr++;
		i++;
	}
	
	if (countr == countl) return 1;
	else return 0;

}

int main( void ) {
  tree *tp = read_tree();
  if ((balanced(tp)) == 1) printf("BALANCED\n");
  else printf("UNSTABLE\n");



  return 0;
}
