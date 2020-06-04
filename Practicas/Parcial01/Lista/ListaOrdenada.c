#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} * head;

head = NULL; 

void insert(int num){
    int c=0;
    struct node *temp; 
    temp = head;
    if(temp == NULL){
        add(num);
    }else{
        while(temp != NULL){
            if(temp->data<num)
                c++;
            temp = temp->next;
        }
        if (c == 0)
        {
            add(num);
        }
        else if (c < count())
        {
            addAfter(num, ++c);
        }
        else
        {
            append(num);
        }
    }
}

void add(int num){
    struct node * temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    if(head == NULL){
        head = temp;
        head->next =NULL;
    }else{
        temp->next = head;
        head = temp;
    }
}

void addafter(int num, int loc){
    int i;
    struct node * temp, *left, *right;
    right = head;
    for (int i = 0; i < loc; i++)
    {
        left = right;
        right = right->next;
    }
    temp = (struct node*) malloc(sizeof(struct node));
    temp -> data=num;
    left->next = temp;
    left = temp;
    left->next = right;
}

int count(){
    struct node *n;
    int c = 0;
    n = head; 
    while(n != NULL){
        n = n->next;
        c++;
    }
    return c;
}

void append(int num){
    struct node *temp, *right;
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = num;
    right = head;
    while(right->next != NULL)
        right = right->next;
    right->next = temp;
    right = temp;
    right->next = NULL;
}

void display(struct node * r){
    r = head; 
    if(r == NULL)
        return;
    while(r != NULL){
        printf("%d", r->data);
        r = r->next;
    }
    printf("\n");
}

int del(int num){
    struct node * temp, *prev;
    temp = head;
    while(temp != NULL){
        if(temp->data == num){
            if(temp == head){
                head = temp->next;
                free(temp);
                return 1;
            }else{
                prev->next = temp->next;
                free(temp);
                return 1;
            }
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    return 0;
}