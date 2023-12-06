#include<stdio.h>
#include<stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
struct Node
{
    int data;
    struct Node* next;
};
 void traverse(struct Node* ptr); 
int countCommon(struct Node *a,struct Node *b)
{
    int count = 0;
    for (; a && b; a = a->next, b = b->next)
        if (a->data == b->data)
            ++count;
        else
            break;
 
    return count;
}
 
int maxPalindrome(struct Node *head)
{
    int result = 0;
    struct Node *prev = NULL;
    struct Node *curr = head;
    while (curr)
    {
        struct Node *next = curr->next;
        curr->next = prev;
        result = max(result,2*countCommon(prev, next)+1);
        result = max(result,2*countCommon(curr, next));
        prev = curr;
        curr = next;
    }
    return result;
}
int main()
{
    int i,n,data;
    printf("Enter the no. of nodes you want to enter:");
    scanf("%d",&n);
    struct Node *head =(struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;
    printf("\nEnter the data of the first node:");
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
     struct Node* fnode=(struct Node*)malloc(sizeof(struct Node));
     printf("\nEnter the data of node %d:",i);
     scanf("%d",&data);
     fnode->data=data;
     fnode->next=NULL;
     temp->next=fnode;
     temp=fnode;
    }
    printf("\nThe list you entered:");
    traverse(head);
    int ans = maxPalindrome(head);
    printf("\nThe length of the longest palindrome list is %d",ans);
    return 0;
}
void traverse(struct Node* ptr)
{
 while(ptr!=NULL)
 {
  if(ptr->next!=NULL)
  printf("%d->",ptr->data);
  else
  printf("%d",ptr->data);
  ptr=ptr->next;
 }
}  






