/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>



typedef struct treenode
{
  int data;
  struct treenode *left;
  struct treenode *right;
} node;



// Function to create a new node

node *newNode (int data)
{

  node *new_node = (node *) malloc (sizeof (node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;

}



void traverseTree (node * root, int *leaf_seq, int *index)
{

  if (!root)
    {
      return;
    }

  if (!root->left && !root->right)
    {
      leaf_seq[*index] = root->data;
      (*index)++;
    }

  traverseTree (root->left, leaf_seq, index);
  traverseTree (root->right, leaf_seq, index);

}





bool leafSimilar (node * root1, node * root2)
{
  int *leaf_seq1 = (int *) malloc (sizeof (int) * 100);
  int *leaf_seq2 = (int *) malloc (sizeof (int) * 100);

  int index1 = 0, index2 = 0;

  traverseTree (root1, leaf_seq1, &index1);
  traverseTree (root2, leaf_seq2, &index2);

  if (index1 != index2)
    {
      return false;
    }

  for (int i = 0; i < index1; i++)
    {
      if (leaf_seq1[i] != leaf_seq2[i])
	{

	  free (leaf_seq1);
	  free (leaf_seq2);

	  return false;

	}

    }

  free (leaf_seq1);
  free (leaf_seq2);

  return true;

}



int
main ()
{
    int n, b;
    node *p,*root1, *q, *root2;
    
    printf("Enter the number of elements for the first tree, please.\n");
    scanf("%d",&n);
    
    int a[n];
    
    printf("\n Great! Now you can enter your elements for the first tree.\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    p = (struct treenode *)malloc(sizeof(struct treenode));
    p-> data = a[0];
    p-> left = NULL;
    p-> right = NULL;
    
    root1 = p;

    for(int i=1;i<n;i++)
    {
        p = (struct treenode *)malloc(sizeof(struct treenode));
        p-> data = a[i];
        p-> left = NULL;
        p-> right = NULL;
        
        q=root1;
        while(1)
        {
            if(p->data < q->data)
            {
                if(q->left == NULL)
                {
                    q->left = p;
                    break;
                }
                else
                {
                    q = q->left;
                }
            }
            else //if p-> data > q->data
            {
                if(q-> right ==NULL)
                {
                    q->right = p;
                    break;
                }
                else
                {
                    q = q->right;
                }
            }
            
        }
        
        
    }
    
    printf("Enter the number of elements for the second tree, please.\n");
    scanf("%d",&b);
    
    int arr[b];
    
    printf("\n Great! Now you can enter your elements for the second tree.\n");
    for(int i=0;i<b;i++)
    {
        scanf("%d",&arr[i]);
    }

    p = (struct treenode *)malloc(sizeof(struct treenode));
    p-> data = a[0];
    p-> left = NULL;
    p-> right = NULL;
    
    root2 = p;

    for(int i=1;i<b;i++)
    {
        p = (struct treenode *)malloc(sizeof(struct treenode));
        p-> data = arr[i];
        p-> left = NULL;
        p-> right = NULL;
        
        q=root2;
        while(1)
        {
            if(p->data < q->data)
            {
                if(q->left == NULL)
                {
                    q->left = p;
                    break;
                }
                else
                {
                    q = q->left;
                }
            }
            else //if p-> data > q->data
            {
                if(q-> right ==NULL)
                {
                    q->right = p;
                    break;
                }
                else
                {
                    q = q->right;
                }
            }
            
        }
        
        
    }


  if (leafSimilar (root1, root2))
    {
      printf ("The trees are leaf-similar.\n");
    }
  else
    {
      printf ("The trees are not leaf-similar.\n");
    }

  return 0;

}




