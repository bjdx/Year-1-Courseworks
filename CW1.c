#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int Search = -1 ;

typedef struct L {
	struct L *pre ;
	char x ;
  	struct L *next ;
} List ;

typedef struct tree {
  	struct tree *parent ;
	char name[ 20 ] ;
  	List *numbers;
  	struct tree *left ;
  	struct tree *right ;
} Tree ;

List *addList( char number, List *pointlast){
	List *pointnew = calloc (1, sizeof(List));
	pointnew->x = number; 
	pointnew->next = pointlast;
	if ( pointnew->next != NULL ) pointnew->next->pre = pointnew ;
	return pointnew;
}

void searchtree( Tree *Tree1 ) {
	char name[20] ;
	int found = 0, i = 0 ;
	Tree *root = Tree1 ;
	List *List1;
	
	while ( 1 == 1) {
		found = 0 ;
		Tree1 = root ;
		printf("Enter a name please ") ;
		scanf("%19s", name ) ;
		i = 0 ;
		while ( name[i] != '\0' ) {
			name[i] = toupper( name[i] ) ;
			i++ ;
		}
		if ( name[0] == '.' ) break ;
		if ( Tree1 != NULL ) {
			while ( Tree1->left != 0 || Tree1->right != 0 ) {
				if ( strcmp( name, Tree1->name ) < 0 ) {
					if (Tree1->left != NULL ) {
						Tree1 = Tree1->left ;
					} else break ;
				} else {
					if ( strcmp( name, Tree1->name ) > 0 ) {
						if ( Tree1->right != NULL ) {	
							Tree1 = Tree1->right ;
						} else break ;
					} else {
						found = 1 ;
						break ;
					}
				}
			}
			if ( Tree1->left == 0 && Tree1->right == 0 ) {
				if ( strcmp( name, Tree1->name ) == 0 ) {
					found = 1 ;
				} else {
					found = 0 ;
				}
			}
			if ( found == 1 ) {
				List1 = Tree1->numbers ;
				while (List1->next != NULL) {
					List1 = List1->next ;			
				}
				while (List1->pre !=NULL) {
					printf("%c", List1->x) ;
					List1 = List1->pre ;
				}
				printf("%c", List1->x) ;			
			} else {
				printf("NOT FOUND\n") ;
			}
		} else {
			printf("NOT FOUND\n") ;
		}
	}
	
}

Tree *addTree( Tree *Tree1, char *name, List *List1){ 

	Tree *TreeNode = calloc (1, sizeof(Tree));
	TreeNode->parent = Tree1 ;
	strncpy(TreeNode->name, name, 19);
	TreeNode->numbers = List1;


	TreeNode->left = NULL;
	TreeNode->right = NULL;
	
	if ( Search == 0 ) {
		if ( TreeNode->parent != NULL ) {
			TreeNode->parent->left = TreeNode ;
		} else {
			TreeNode->left = TreeNode ;
		}
	} else {
		if ( TreeNode->parent != NULL ) {
			TreeNode->parent->right = TreeNode ;
		} else {
			TreeNode->right = TreeNode ;
		}
	}
	return TreeNode;
}

Tree *createtree(void) {
	Tree *Tree1;
	Tree *root = NULL;
	List *List1 ;
	int i = 0 , j=0, found = 0;
	char temp;
	char name[20];
	char number[15];
	while (1==1){
		List1 = NULL ;
		scanf("%19s", name);
		i = 0, j = 0 ;
		while ( name[i] != '\0' ) {
			name[i] = toupper( name[i] ) ;
			i++ ;
		}
		if (name[0] == '.') break;
		for ( i = 0 ; i <15 ; i++ ) {
			number[i] = '\0';
		}
		scanf("%14s", number);
		while (number[j] != '\0') {
			j++;
		}
		number[j] = '\n';
		i = 0 ;
		Tree1 = root ;
		
		if ( Tree1 == 0 ) {
			while (number[i] != '\0') {
				List1 = addList(number[i], List1);
				i++;
			}
			List1->pre = NULL ;
			Tree1 = addTree(Tree1, name, List1) ;
			root = Tree1 ;

			Tree1->right = NULL ;
			Tree1->left = NULL ;


		}else{
			
			while ( Tree1->left != 0 || Tree1->right != 0 ) {
				if ( strcmp( name, Tree1->name ) < 0 ) {
					if (Tree1->left != NULL ) {
						Tree1 = Tree1->left ;
					} else break ;
				} else {
					if ( strcmp( name, Tree1->name ) > 0 ) {
						if ( Tree1->right != NULL ) {	
							Tree1 = Tree1->right ;
						} else break ;
					} else {
						found = 1 ;
						break ;
					}
				}
			}
			if ( Tree1->left == 0 && Tree1->right == 0 ) {
				if ( strcmp( name, Tree1->name ) == 0 ) {
					found = 1 ;
				} else {
					found = 0 ;
				}
			}
			
			if (found==0) {
				Tree1 = root ;
				while ( Tree1->left != 0 || Tree1->right != 0 ) {

					if( strcmp( name, Tree1->name ) < 0 ) {
						Search = 0 ;
						if ( Tree1->left != NULL ) {
							Tree1 = Tree1->left;
						} else {
							break ;
						}
					} else {
						Search = 1;
						
						if ( Tree1->right != NULL ) {
							
							Tree1 = Tree1->right;
						} else {
							break ;
						}
					}
				}
				if( strcmp( name, Tree1->name ) < 0 ) {
					Search = 0 ;
				} else Search = 1 ;
				while (number[i] != '\0') {
					List1 = addList(number[i], List1);
					i++;
				}
				List1->pre = NULL ;
				Tree1 = addTree(Tree1, name, List1) ;
			} else {
				List1 = Tree1->numbers ;
				while (number[i] != '\0') {
					List1 = addList(number[i], List1);
					i++;
				}
				List1->pre = NULL ;
			}
			Tree1->numbers = List1;
		}
		
			
	}	
	Tree1 = root ;
	return Tree1;
	
}



int main ( void ) {
	printf("100%%\n");
	Tree *found = NULL ;
	Tree *Tree1 = createtree() ;
	searchtree( Tree1 ) ;
	return 0 ; 
}
