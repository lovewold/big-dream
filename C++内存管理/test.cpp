#define _CRT_SECURE_NO_WARNINGS 1
//calloc ==malloc+memset
//realloc ¿©»›£®‘≠µÿ¿©»›∫Õ“Ïµÿ¿©»›£© 
  
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
#include<malloc.h>
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize)
{
    int* pairs = (int*)malloc(spellsSize * 4);
    int i = spellsSize;
    *returnSize = i;
    while (i-- > 0)
    {
        int size = 0;
        for (int j = 0; j < potionsSize; j++)
        {
            if ((spells[i] * potions[j]) >= success)
            {
                size++;
            }
        }
        printf("%d", size);
        pairs[i] = size;
    }
    return pairs;


}