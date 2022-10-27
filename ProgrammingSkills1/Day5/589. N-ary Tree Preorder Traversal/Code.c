/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void treePreorderTraverse( int* arr, struct Node* root, int* arrIndex )
{
    if ( root == NULL ) return;
    
    arr[*arrIndex] = root->val;
    ( *arrIndex )++;
    
    for ( int i = 0 ; i < root->numChildren ; i++ )
    {
        treePreorderTraverse( arr, root->children[i], arrIndex);
    }
}

void numberOfNodes( struct Node* root, int* Nodes )
{
    if ( root == NULL ) return;
    
    ( *Nodes )++;
    
    for ( int i = 0 ; i < root->numChildren ; i++)
    {
        numberOfNodes( root->children[i], Nodes );
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) 
{
    /* calculate number of nodes in tree */
    int Nodes = 0;
    numberOfNodes( root, &Nodes );
    
    ( *returnSize ) = Nodes;
    
    /* malloc the return array */
    int* returnArray = ( int* )malloc( sizeof(int) * Nodes );
    int returnArrayIndex = 0;
    
    treePreorderTraverse( returnArray, root, &returnArrayIndex);
 
    return returnArray;
}