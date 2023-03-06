#include "DynamicArray.h"




void* getElement(DynamicArray* our_array,size_t index)
{
    
    if(index>=our_array->capacity || index>our_array->length){
        
        return NULL;
    }
    return ((char*)our_array->pointer)+ (our_array->element_size_bytes*index);
}

void destroyArray(DynamicArray* our_array)
{
    free(our_array->pointer);
}

void clear(DynamicArray* our_array)
{
    our_array->length=0;
}

void deleteFirst(DynamicArray* our_array)
{
    char* new_block=malloc(our_array->capacity_size_bytes);

    char* pointer_to_array=our_array->pointer;
    for (size_t i = 0; i < our_array->capacity_size_bytes; i++)
    {
        size_t index=(our_array->element_size_bytes*(i+1));
        new_block[i]=pointer_to_array[index];
    }

    destroyArray(our_array);

    our_array->pointer=new_block;

    
}
void deleteAtMiddle(DynamicArray* our_array,size_t index)
{
    char* new_block=malloc(our_array->capacity_size_bytes);

    char* pointer_to_array=our_array->pointer;
    size_t where_we_left=our_array->element_size_bytes*index;
    for (size_t i = 0; i < where_we_left; i++)
    {
        new_block[i]=pointer_to_array[i];
    }

    size_t counter=0;
    for (size_t past_deleted_element = where_we_left+our_array->element_size_bytes; 
    past_deleted_element < our_array->capacity_size_bytes; 
    past_deleted_element++,
    counter++)
    {
        
        new_block[counter]=pointer_to_array[past_deleted_element];
    }
    destroyArray(our_array);
    our_array->pointer=new_block;

}


void reduce_length(DynamicArray* our_array)
{
    if(our_array->length<=0)
    {

        return;
    }
    

    our_array->length--;
}

void pushElement(DynamicArray* our_array,void* element)
{

    if(our_array->length>=our_array->capacity)
    {
        size_t new_size=our_array->capacity_size_bytes*2;
        our_array->pointer=realloc(our_array->pointer,new_size);
        our_array->capacity=our_array->capacity*2;
    }
    char* pointer_to_array=(char*)our_array->pointer;
    char* value_pointer=(char*)element;

    for (size_t i = 0; i < our_array->element_size_bytes; i++)
    {   
        size_t index_to_put_element=(our_array->length*our_array->element_size_bytes)+i;
        pointer_to_array[index_to_put_element]=value_pointer[i];
    }

    our_array->length++;

    
}

DynamicArray* createArray(size_t type_size)
{
    DynamicArray* new_array=malloc(sizeof(DynamicArray));
    new_array->capacity_size_bytes=type_size*DEFAULT_CAPACITY;
    new_array->pointer=malloc(new_array->capacity_size_bytes);

    new_array->element_size_bytes=type_size;
    new_array->capacity=DEFAULT_CAPACITY;
    new_array->length=0;
    return new_array;
}