/*Linked List Program from scratch*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node * createList(int val_data)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->next=NULL;
    new_node->data=val_data;
    
    return new_node;
}
struct node * add_at_begin(int new_data,struct node *head)
{
    struct node *begin = createList(new_data);
    begin->next=head;
    
    return begin;
    
}
void printList(struct node *begin)
{
    printf("\n List is as follows : ");
    while(begin!=NULL)
    {
        printf("\t%d\t",begin->data);
        begin=begin->next;
    }
}

void add_at_end(struct node *begin,int data)
{
    struct node *end = createList(data);
    while(begin->next!=NULL)
    {
        begin=begin->next;
    }
    begin->next=end;
}

void add_in_nth_position(struct node *head,int data,int position)
{
    struct node *mid = createList(data);
    struct node *temp = NULL;
    int count=1;
    while(count<position-1)
    {
        count+=1;
        head=head->next;
    }
    temp=head->next;
    head->next=mid;
    head->next->next=temp;
}
struct node* del_from_front(struct node *head)
{
    head=head->next;
    return head;
}

void del_from_position(int position,struct node *head)
{
    int count=1;
    struct node *temp;
    while(count<position-1)
    {
        count+=1;
        head=head->next;
    }
    head->next=head->next->next;
}
void main()
{
    struct node *head=NULL;
    head=createList(5);
    head->next=createList(6);
    head->next->next=createList(7);
    head->next->next->next=createList(8);
    printList(head);
    head=add_at_begin(9,head);
    head=add_at_begin(10,head);
    add_at_end(head,11);
    add_at_end(head,12);
    printList(head);
    add_in_nth_position(head,66,5);
    printList(head);
    head=del_from_front(head);
    printList(head);
    del_from_position(5,head);
    printList(head);

}
