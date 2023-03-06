#include "LinkedList.h"

SNode* createSingleNode()
{
    SNode* new_node=(SNode*)malloc(sizeof(SNode));
    return new_node;
}

void setNext(SNode* src,SNode* dest)
{
    src->next=dest;
}


void addData(SNode* our_node,void* data,size_t data_size)
{
    char* node_data_pointer=(char*)our_node->data;
    our_node->data_size=data_size;

    char* user_data_pointer=(char*)data;

    for (size_t i = 0; i < data_size; i++)
    {
        node_data_pointer[i]=user_data_pointer[i];
    }
    
}