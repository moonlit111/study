#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
} Node;
void add_element_in_tail(Node** head,int data_to_add){
    //检查头结点是不是空的（一般不是）
    if(*head==NULL){
        *head=malloc(sizeof(Node));
        //录入数据
        (*head)->data=data_to_add;
        (*head)->next=NULL;
        return;
    }
    //分配一个新的结点，并录入数据
    Node* p=malloc(sizeof(Node));
    p->data=data_to_add;
    p->next=NULL;
    //检查头指针的next是不是空的
    if((*head)->next==NULL){
        Node* p=malloc(sizeof(Node));
        (*head)->next=p;
    }else{
        Node* current=*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=p;
    }
}
void delete_elements_by_data(Node** head,int data_to_delete){
    //创建指向指针
    Node* current=*head;
    Node* prev=NULL;
    while(current!=NULL){
        if(current->data==data_to_delete){
            if(prev==NULL){
                *head=current->next;
            }else{
                prev->next=current->next;
            }
            Node*temp=current;
            current=current->next;
            free(temp);
        }else{
            prev=current;
            current=current->next;
        }
    }
}
int find_first(Node** head,int data_to_find){
    Node* current=*head;
    int pos=0;
    while(current!=NULL){
        if(current->data=data_to_find){
            return pos;
        }else{
            current=current->next;
        }
        pos++;
    }
}
int main(){
    return 0;
}