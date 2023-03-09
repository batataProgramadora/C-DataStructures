
#include "Array/DynamicArray.h"

int main()
{
    DynamicArray* my_array=createArray(sizeof(int));
    int element=50;
    pushElement(my_array,&element);
    printf("%d",*(int*)getElement(my_array,0));
    return 0;
}