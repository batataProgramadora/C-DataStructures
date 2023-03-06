#include <stdlib.h>


struct SingleNode{
    void* data;
    size_t data_size;
    struct SingleNode* next;
};


typedef struct SingleNode SNode;


SNode* createSingleNode();

void addData(SNode* our_node,void* data,size_t data_size);

void setNext(SNode* src,SNode* dest);


struct SLinkedList{
    SNode* head;
    SNode* current;
    size_t length;
};

typedef struct SLinkedList SLinkedList;
void addNode(SLinkedList* src,void* data,size_t data_size);