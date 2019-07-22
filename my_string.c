#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "status.h"
#include "generic.h"

struct my_string
{
    int size; //number of characters the string currently holds
    int capacity; //number of characters the string CAN hold
    char* data; //holds the dynamic array of characters representing a given string
};
typedef struct my_string My_string;







MY_STRING my_string_init_default(void)
{
    My_string* pMy_string;
    pMy_string = (My_string*)malloc(sizeof(My_string));
    if (pMy_string != NULL)
    {
        pMy_string->size = 0;
        pMy_string->capacity = 7;
        pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);
        if (pMy_string->data == NULL)
        {
            free(pMy_string);
            return NULL;
        }
    }
    return (MY_STRING)pMy_string;
}







void my_string_assignment(ITEM* pLeft, ITEM Right)
{
   if (*pLeft == NULL)
   {
       *pLeft = my_string_init_default();
   }

   My_string* left = (My_string*)*pLeft;
   My_string* right = (My_string*)Right;
   int i = 0;
  
   if (left->capacity < right->capacity)
   {
      free(left->data);
      left->data = (char*)malloc(sizeof(char)*right->capacity);
      left->capacity = right->capacity;
   }

   if(left->data != right->data)
   {
      left->size = right->size;
      for(i=0; i<left->size; i++)
      {
	 left->data[i] = right->data[i];
      }
   }
}





MY_STRING my_string_init_c_string(const char* c_string)
{
    My_string* pMy_string;
    int i;
    int c_string_length = 0;

    //Get length of c_string
    for(i = 0; c_string[i] != '\0'; i++)
    {
        c_string_length ++;
    }
    
    
    pMy_string = (My_string*)malloc(sizeof(My_string));
    if (pMy_string != NULL)
    {
        pMy_string->size = c_string_length;
        pMy_string->capacity = c_string_length + 1;
        pMy_string->data = (char*)malloc(sizeof(char)*pMy_string->capacity);
        if (pMy_string->data == NULL)
        {
            free(pMy_string);
            return NULL;
        }
    }

    for(i = 0; i < c_string_length; i ++)
    {
      pMy_string->data[i] = c_string[i];
    }
    pMy_string->data[c_string_length] = '\0';

    
    return (MY_STRING)pMy_string;
}










int my_string_get_capacity(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;
    return pMy_string->capacity;
}








int my_string_get_size(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;
    return pMy_string->size;
}








int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
    int left_size, right_size;
       
    left_size = my_string_get_size(hLeft_string);
    right_size = my_string_get_size(hRight_string);
    
    if (left_size < right_size)
    {
        return -1;
    }
    else if (left_size == right_size)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}





Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;
    char* pTemp = NULL;
    char c;
    int noc;
    int i;



    pMy_string->size = 0;

    noc = fscanf(fp, " %c", &c);
    if (noc != 1)
    {
       return FAILURE;
    }

    while (noc == 1 && !isspace(c))
    {
       

       if (pMy_string->size >= pMy_string->capacity)
       {
	  pTemp = (char*)malloc(sizeof(char) * 2 * pMy_string->capacity);
	  
	  if (pTemp == NULL)
	  {
	     return FAILURE;
	  }
	  
	  for(i = 0; i < pMy_string->size; i ++)
	  {
	     pTemp[i] = pMy_string->data[i];
	     //	free(&(pMy_string->data[i]));
	  }
	  

	  free(pMy_string->data);
	  pMy_string->data = pTemp;
	  pMy_string->capacity *= 2;
       }

       
       pMy_string->data[pMy_string->size] = c;
       pMy_string->size++;
       noc = fscanf(fp, "%c", &c);
    }
    if(noc == 1)
    {
       ungetc(c, fp);
    }
    
    
    return SUCCESS;
}







Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;

    if(fp == NULL)
      {
	return FAILURE;
      }
    
    if(pMy_string->size == 0)
    {
      return FAILURE;
    }
   
    if (fprintf(fp, "%s", pMy_string->data))
    {
      return SUCCESS;
     }
    
   return FAILURE;
}







Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string* pMy_string = (My_string*)hMy_string;
  char* pTemp;
  int i;
  if (hMy_string == NULL)
  {
    return FAILURE;
  }

  if (pMy_string->size >= pMy_string->capacity)
    {
      pTemp = (char*)malloc(sizeof(char) * pMy_string->capacity * 2);
      if (pTemp == NULL)
	{
	  printf("Failed to resize for push_back.\n");
	  return FAILURE;
	}
      for (i = 0; i < pMy_string->size; i++)
	{
	  pTemp[i] = pMy_string->data[i];
	}
      free(pMy_string->data);
      pMy_string->data = pTemp;
      pMy_string->capacity *= 2;
    }
  pMy_string->data[pMy_string->size] = item;
  pMy_string->size++;
  return SUCCESS;
}








Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  if (hMy_string == NULL)
  {
    return FAILURE;
  }
  
  if (pMy_string->size <= 0)
    {
      return FAILURE;
    }
  pMy_string->size--;
  pMy_string->data[pMy_string->size] = '\0';
  return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pMy_string = (My_string*)hMy_string;

  if (hMy_string == NULL)
  {
    return NULL;
  }
  
  if(index < 0 || index >= pMy_string->size)
    {
      return NULL;
    }
  return &(pMy_string->data[index]);
}





char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;
  char* pTemp;
  int i;
 
  if (hMy_string == NULL)
  {
    return NULL;
  }
 
    
  if (pMy_string->size >= pMy_string->capacity)
    {
      pTemp = (char*)malloc(sizeof(char) * pMy_string->capacity + 1);
      if (pTemp == NULL)
	{
	  printf("Failed to make space for c_str.\n");
	  return NULL;
	}
      for (i = 0; i < pMy_string->size; i++)
	{
	  pTemp[i] = pMy_string->data[i];
	}
      free(pMy_string->data);
      pMy_string->data = pTemp;
      pMy_string->capacity ++;
    }
  
  pMy_string->data[pMy_string->size] = '\0';
  return pMy_string->data;
}






Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* pResult = (My_string*)hResult;
  My_string* pAppend = (My_string*)hAppend;

  if (hResult == NULL || hAppend == NULL)
  {
    //printf("One of the strings is NULL.\n");
    return FAILURE;
  }
  
  char* pTemp;
  int i;
  int combined_capacity = pResult->capacity + pAppend->capacity;
      
   if ((pResult->size + pAppend->size) >= pResult->capacity)
    {
      pTemp = malloc(sizeof(char) * combined_capacity * 2);
      if (pTemp == NULL)
	{
	  return FAILURE;
	}
      for (i = 0; i < pResult->size; i++)
	{
	  pTemp[i] = pResult->data[i];
	}
      free(pResult->data);
      pResult->data = pTemp;
      pResult->capacity = combined_capacity * 2;
    }

  for (i = pResult->size; i < (pResult->size + pAppend->size); i++)
    {
      pResult->data[i] = pAppend->data[i - pResult->size];
    }
  pResult->size += pAppend->size;
     
  return SUCCESS;
}







Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*)hMy_string;
  
  if (pMy_string->size <= 0)
    {
      return TRUE;
    }
  
  return FALSE;
}


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
   My_string* pCurrent_word_family = (My_string*)current_word_family;
   My_string* pNew_key = (My_string*)new_key;
   My_string* pWord = (My_string*)word;
   int i;

   //Failure condition
   if(pCurrent_word_family->size != pNew_key->size)
   {
      return FAILURE;
   }

   //Change upper case to lower case
   if (isupper(guess))
   {
      guess = tolower(guess);
   }



   for(i=0; i< pWord->size; i++)
   {
      if(pWord->data[i] == guess)
      {
	 pNew_key->data[i] = guess;
      }
   }
   return SUCCESS;
}

void my_string_destroy(ITEM* phItem)
{
    My_string* pMy_string = (My_string*)*phItem;
    // printf("Heres my string_destroy = %p\n",pMy_string->data);
    free(pMy_string->data);
    free(pMy_string);
    *phItem = NULL;
}
