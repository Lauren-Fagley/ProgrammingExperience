/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct treenode {       /* tree node struct */
int data;                       /* integer field */
struct treenode *left;          /* pointer to the left child */
struct treenode *right;         /* pointer to the right child */
} node;

int BottomLeftValue(node *root)
    {
        if (root)
        {
            // the level is 0 and value equals root value
            int result[] = { 0, root->data };
            BottomLeftValueFind(root, 0, result);
            printf("Leftmost value: %d\n",result[1]);
            return result[1];
        }
        
    }

void BottomLeftValueFind(node *root, int level, int result[])
    {
        if (root)
        {
            if (level > result[0])
            {
                result[0] = level;
                result[1] = root->data;
            }
        
            BottomLeftValueFind(root->left, level + 1, result);
            BottomLeftValueFind(root->right, level + 1, result);
            
        }
    }
    
  
int FindNumber(node *root, int v)
{
    if (root)
    {
        
        if (root->data == v)
        {
            return 0;
        }
        else{
            int l=FindNumber(root->left,v);
            int r=FindNumber(root->right,v);
        
            if(l!=0 || r!=0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        
        

    }
    
}

/* Returns Maximum of two numbers */
int getMax(int a, int b)
{
    if(a >= b)
        return a;
    else
        return b;
}
 
/* Returns Height of binary tree */
int getHeight(node *root)
{
    int leftHeight, rightHeight;
    if(root == NULL)
        return 0;
    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);
     
    return getMax(leftHeight, rightHeight) + 1;
}
 
/* Check is passed binary tree is height-balanced */
int isHeightBalanced(node *root){
   int leftHeight, rightHeight;
  
   /* Empty Tree is always height balanced */
   if(root == NULL)
       return TRUE; 
  
   /* Find the height of left and right subtree */
   leftHeight = getHeight(root->left);
   rightHeight = getHeight(root->right);
    
   /* If both sub trees are height balanced and the 
   difference of height of left and right subtree is <= 1,
    then given tree is Height balanced else not */
   if(abs(leftHeight - rightHeight) <= 1 && isHeightBalanced(root->right) 
            && isHeightBalanced(root->left))
       return TRUE;
   else
       return FALSE;
}

int main()
{
    int n;
    node *p,*root1, *q;
    printf("Enter the number of elements you would like to insert, please.\n");
    scanf("%d",&n);
    
    int a[n];
    
    printf("\nGreat! Now you can enter your elements.\n");
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
    
    BottomLeftValue(root1);
    
    int v;
    
    printf("What number would you like to search for?\n");
    scanf("%d",&v);
    
    FindNumber(root1, v);
    
    if(FindNumber(root1,v) == 1)
    {
       printf("%d is not in the binary search tree. :(\n", v);
    }
    else{
        printf("%d is in the binary search tree!\n",v);
    }
    
    if(isHeightBalanced(root1))
    {
        printf("Height Balanced Tree\n");
    } 
    else 
    {
        printf("Not a Height Balanced Tree\n");
    }
    

    return 0;
}







