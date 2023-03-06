
#define DEFAULT_CAPACITY 10
#include <stdio.h>  
#include <stdlib.h>

struct DynamicArray{
    void* pointer;
    size_t element_size_bytes;
    size_t capacity_size_bytes;
    int capacity;
    int length;
};

typedef struct DynamicArray DynamicArray;


void* getElement(DynamicArray* our_array,size_t index);
void destroyArray(DynamicArray* our_array);
void clear(DynamicArray* our_array);


void deleteFirst(DynamicArray* our_array);
void pushElement(DynamicArray* our_array,void* element);
void reduce_length(DynamicArray* our_array);
void deleteAtMiddle(DynamicArray* our_array,size_t index);
DynamicArray* createArray(size_t type_size)