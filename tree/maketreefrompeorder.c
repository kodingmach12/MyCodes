// Problem: Binary Tree - PreOrder Traversal to Tree Shape -
// - When each node can only be named 'N' or 'L'
// - A node named 'N' must have exactly two children (not less and not more)
// - A node named 'L' must have zero children (or leaf node)
// - Not a complete binary tree - Ex: NNLLL
#include <stdio.h>
#define ARRSIZE(arr)  (sizeof((arr))/sizeof((arr)[0]))
struct Node
{
  struct Node *pLeft;
  struct Node *pRight;
  char data; // Char - 'N', 'L'
};
struct Node* CreateTree(char *pData, int nData);
struct Node* DeleteTree(struct Node *pRoot);
void PrintInOrderTree(struct Node *pRoot);
void PrintPreOrderTree(struct Node *pRoot);
void PrintPostOrderTree(struct Node *pRoot);
void PrintTree(struct Node *pRoot);

int main(int argc, char *args[])
{
  struct Node  *pRoot = NULL;
  char *pInputs[] = {"L", "NLL", "NNLLL", "NLNLL", "NNNLLLL", "NLNLNLL", "N", "NL" };
  int i;

  printf("\n\n");

  for (i = 0; i < ARRSIZE(pInputs); i++)
  {
    printf("Tree     (Input) : %s\n", pInputs[i]);
    pRoot = CreateTree(pInputs[i], strlen(pInputs[i]) + 1);
    PrintTree(pRoot);
    pRoot = DeleteTree(pRoot);
    printf("\n");
  }

  return 0;
}

int _CreateTree(char *pData, int nData, struct Node **ppRoot, int *pIdxData)
{
  struct Node *pRoot = NULL;
  struct Node *pNode = NULL;
  int errorCode;

  if (*pIdxData >= nData)
  {
    errorCode = -4; // Should not idelly lead to here
    goto Exit;
  }

  pNode = (struct Node *) malloc(sizeof(struct Node));
  if (NULL == pNode)
  {
    errorCode = -3; // E_OUTOFMEMORY
    goto Exit;
  }

  *ppRoot = pNode;
  pNode->data = pData[*pIdxData];
  pNode->pLeft = pNode->pRight = NULL;

  if ('L' == pNode->data)
  {
    errorCode = 0;
    goto Exit;
  }

  *pIdxData += 1;
  errorCode = _CreateTree(pData, nData, &(pNode->pLeft), pIdxData);
  if (errorCode < 0) goto Exit;

  *pIdxData += 1;
  errorCode = _CreateTree(pData, nData, &(pNode->pRight), pIdxData);
  if (errorCode < 0) goto Exit;

  errorCode = 0;

Exit:
  return errorCode;
}

struct Node* CreateTree(char *pData, int nData)
{
  int idxData = 0;
  int errorCode;
  struct Node *pRoot = NULL;

  if (0 != nData % 2)
  {
    // A tree can only have odd number of elements if the given
    // restrictions have to be met - N has 2 and L has zero children
    errorCode = -2;
    goto Exit;
  }

  errorCode = _CreateTree(pData, nData, &pRoot, &idxData);

Exit:
  if (errorCode < 0)
  {
    pRoot = DeleteTree(pRoot);
  }

  return pRoot;
}

struct Node* DeleteTree(struct Node *pRoot)
{
  if (NULL != pRoot)
  {
    pRoot->pLeft = DeleteTree(pRoot->pLeft);
    pRoot->pRight = DeleteTree(pRoot->pRight);
    free(pRoot);
    pRoot = NULL;
  }

  return pRoot;
}

void _PrintInOrderTree(struct Node *pRoot)
{
  if (NULL != pRoot)
  {
    _PrintInOrderTree(pRoot->pLeft);
    printf("%c, ", pRoot->data);
    _PrintInOrderTree(pRoot->pRight);
  }
}

void PrintInOrderTree(struct Node *pRoot)
{
  printf("Tree   (InOrder) : ");
  if (NULL != pRoot)
    _PrintInOrderTree(pRoot);
  else
    printf("<EMPTY>");
  printf("\n");
}

void _PrintPreOrderTree(struct Node *pRoot)
{
  if (NULL != pRoot)
  {
    printf("%c, ", pRoot->data);
    _PrintPreOrderTree(pRoot->pLeft);
    _PrintPreOrderTree(pRoot->pRight);
  }
}

void PrintPreOrderTree(struct Node *pRoot)
{
  printf("Tree  (PreOrder) : ");
  if (NULL != pRoot)
    _PrintPreOrderTree(pRoot);
  else
    printf("<EMPTY>");
  printf("\n");
}

void _PrintPostOrderTree(struct Node *pRoot)
{
  if (NULL != pRoot)
  {
    _PrintPostOrderTree(pRoot->pLeft);
    _PrintPostOrderTree(pRoot->pRight);
    printf("%c, ", pRoot->data);
  }
}

void PrintPostOrderTree(struct Node *pRoot)
{
  printf("Tree (PostOrder) : ");
  if (NULL != pRoot)
    _PrintPostOrderTree(pRoot);
  else
    printf("<EMPTY>");
  printf("\n");
}

void PrintTree(struct Node *pRoot)
{
  PrintPreOrderTree(pRoot);
  PrintInOrderTree(pRoot);
  PrintPostOrderTree(pRoot);
}

