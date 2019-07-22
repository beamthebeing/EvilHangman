#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "status.h"
#include "unit_test.h"
#include "my_string.h"
#include "generic.h"



Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(hString == NULL)
  {
    strncpy(buffer, "test_init_default_returns_nonNULL\n"
	    "my_string_init_default returns NULL", length);
    return FAILURE;
  }
  else
  {
     my_string_destroy((ITEM*)&hString);
    strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
    return SUCCESS;
  }
}





Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if(my_string_get_size(hString) != 0)
  {
    status = FAILURE;
    printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	    "Did not receive 0 from get_size after init_default\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}





Status test_dbennett_get_capacity_on_init_default_returns_7(char* buffer,
							    int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();

  if(my_string_get_capacity(hString) != 7)
  {
    status = FAILURE;
    printf("Expected a capacity of 7 but got %d.\n",
	   my_string_get_capacity(hString)); 
    strncpy(buffer, "test_dbennett_get_capacity_on_init_default_returns_7\n"
	    "Did not recieve 7 from get_capacity after init_default\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_get_capacity_on_init_default_returns_7\n"
	    , length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}





Status test_dbennett_init_c_string_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("This is a Test");

  if(hString == NULL)
  {
    status = FAILURE;
    strncpy(buffer, "test_dbennett_init_c_string_returns_nonNULL\n"
	    "my_string_init_c_string returns NULL\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_init_c_string_returns_nonNULL\n", length);
  }
    
  my_string_destroy((ITEM*)&hString);
  return status;
}




Status test_dbennett_get_size_on_init_c_string_for_TEST_returns_4(char*	buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("TEST");
  if (my_string_get_size(hString) != 4)
  {
    status = FAILURE;
    printf("Expected size of 4 from \"TEST\" but got %d.\n", my_string_get_size(hString));
    strncpy(buffer, "test_dbennett_get_size_on_init_c_string_for_TEST_returns_4\n"
	    "Did not recieve size of 4 from get_size after init_c_string\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_get_size_on_init_c_string_for_TEST_returns_4\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}




Status test_dbennett_get_capacity_on_init_c_string_for_TEST_returns_5(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_c_string("TEST");
  if(my_string_get_capacity(hString) != 5)
  {
    status = FAILURE;
    printf("Expected a capacity of 5 for \"TEST\" but got %d\n",
	   my_string_get_capacity(hString));
    strncpy(buffer, "test_dbennett_get_capacity_on_init_c_string_for_TEST_returns_5\n"
	    "Did not recieve capacity of 5 from init_c_string after get_capcity\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_get_capacity_on_init_c_string_for_TEST_returns_5\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}





Status test_dbennett_push_back_10000_characters(char* buffer, int length)
{
  MY_STRING hString;
  Status status;
  int i;

  hString = my_string_init_default();

  for(i = 0; i < 10000; i ++)
  {
    status = my_string_push_back(hString, 'a');
    if (status == FAILURE)
    {
      printf("Push_back failed to allocate memory\n");
      strncpy(buffer, "test_dbennett_push_back_10000_characters\n"
	      "Failed to allocate memory while creating string\n", length);
      return FAILURE;
    }
  }

  if(my_string_get_size(hString) != 10000)
  {
    status = FAILURE;
    printf("Expected to push_back 10,000 characters but only pushed back %d\n", my_string_get_size(hString));
    strncpy(buffer, "test_dbennett_push_back_10000_characters\n"
	    "Did not have a size of 10,000 after get_size\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_push_back_10000_characters\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}




Status test_dbennett_push_back_10000_characters_then_pop_back_them_all(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  int i;

  hString = my_string_init_default();

  for(i = 0; i < 10000; i ++)
  {
    status = my_string_push_back(hString, 'a');
    if (status == FAILURE)
    {
      printf("Push_back failed to allocate memory for string of 10,000 characters\n");
      strncpy(buffer, "test_dbennett_push_back_10000_characters_then_pop_back_them_all\n"
              "Failed to allocate memory while creating string\n", length);
      return FAILURE;
    }
  }
  
  if (my_string_get_size(hString) != 10000)
  {
    printf("String has a size of %d after running get_size\n", my_string_get_size(hString));
    strncpy(buffer, "test_dbennett_push_back_10000_characters_then_pop_back_them_all\n"
	    "Does not have a string of size 10,000 after creating the string\n", length);
    return FAILURE;
  }
     

  for(i = 0; i < 10000; i++)
  {
    status = my_string_pop_back(hString);
    if(status == FAILURE)
    {
      strncpy(buffer, "test_dbennett_push_back_10000_characters_then_pop_back_them_all\n"
	      "Failed during pop_back operations\n", length);
      return FAILURE;
    }
  }

  if (!my_string_empty(hString))
  {
    status = FAILURE;
    
    strncpy(buffer, "test_dbennett_push_back_10000_characters_then_pop_back_them_all\n"
	    "Failed, string is not empty\n", length);
  }
  else
  {
    status = SUCCESS;
    strncpy(buffer, "test_dbennett_push_back_10000_characters_then_pop_back_them_all\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  return status;
}


Status test_dbennett_my_string_at_returns_null_for_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  char* value;

  hString = my_string_init_default();
  if(hString == NULL)
    {
      printf("Failed to allocate memory for hString\n");
      return FAILURE;
    }

  value = my_string_at(hString, 0);
  if(value != NULL)
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_null_for_init_default\n"
	      "Failed to return NULL on empty string\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_null_for_init_default\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}



Status test_dbennett_my_string_at_returns_nonNULL_address_for_init_default_after_push_back(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  char* value;
  
  hString = my_string_init_default();
  if(hString == NULL)
    {
      printf("Failed to allocate memory for hString.\n");
      return FAILURE;
    }

  status = my_string_push_back(hString, 'a');
  if (status == FAILURE)
    {
      printf("Failed to push_back\n");
      return FAILURE;
    }

  value = my_string_at(hString, 0);
  if (value == NULL)
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_nonNULL_address_for_init_default_after_push_back\n"
	      "Has a NULL address after push_back\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_nonNULL_address_for_init_default_after_push_back\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}
      
  
  
Status test_dbennett_my_string_at_returns_valid_address_for_init_c_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  char* value;



  hString = my_string_init_c_string("This is a TEST");
  if (hString == NULL)
    {
      printf("Failed to allocate memory for hString\n");
      return FAILURE;
    }

  value = my_string_at(hString, 0);
  if (value == NULL)
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_valid_address_for_init_c_string"
	      "Failed because my_string_at returned an address of NULL\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_my_string_at_returns_valid_address_for_init_c_string", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}

Status test_dbennett_concat_returns_SUCCESS_if_both_strings_are_empty(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  Status status;


  hResult = my_string_init_default();
  hAppend = my_string_init_default();

  if(hResult == NULL || hAppend == NULL)
    {
      printf("Failed to allocate memory for one of the two strings\n");
      return FAILURE;
    }

  status = my_string_concat(hResult, hAppend);
  if (status == FAILURE)
    {
      strncpy(buffer, "test_dbennett_concat_returns_SUCCESS_if_both_strings_are_empty\n"
	      "Failed on concat\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_concat_returns_SUCCESS_if_both_strings_are_empty\n", length);
    }

  my_string_destroy((ITEM*)&hResult);
  my_string_destroy((ITEM*)&hAppend);

  return SUCCESS;
}
  
Status test_dbennett_concat_does_not_change_hAppend(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  Status status;
  char word[4];
  int i;


  hResult = my_string_init_c_string("con");
  hAppend = my_string_init_c_string("cat");

  if(hResult == NULL || hAppend == NULL)
    {
      printf("Failed to allocate memory for one of the two strings\n");
      return FAILURE;
    }

  for (i= 0; i < my_string_get_size(hAppend); i ++)
    {
      word[i] = *my_string_at(hAppend, i);
    }
  word[my_string_get_size(hAppend)] = '\0';

  
  status = my_string_concat(hResult, hAppend);
  if(status == FAILURE)
    {
      printf("Failed to concat");
      return FAILURE;
    }


   for(i = 0; i < 3; i++)
    {
      if ( word[i] != *my_string_at(hAppend, i))
	{
	  strncpy(buffer, "test_dbennett_concat_does_not_change_hAppend\n"
	      "Failed because hAppend changed after concat\n", length);
	  return FAILURE;
	}
    }


  if(my_string_get_size(hAppend) != 3)
    {
      strncpy(buffer, "test_dbennett_concat_does_not_change_hAppend\n"
	      "Failed because hAppend changed after concat\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_concat_does_not_change_hAppend\n", length);
    }

  my_string_destroy((ITEM*)&hResult);
  my_string_destroy((ITEM*)&hAppend);

  return SUCCESS;
}

    
  
Status test_dbennett_empty_returns_TRUE_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Boolean boolean;

  hString = my_string_init_default();
  if(hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  boolean = my_string_empty(hString);
  if (boolean != TRUE)
    {
      strncpy(buffer, "test_dbennett_empty_returns_TRUE_on_init_default\n"
	      "failed to recognize empty string\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_empty_returns_TRUE_on_init_default\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}

  
Status test_dbennett_empty_returns_FALSE_on_init_c_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Boolean boolean;

  hString = my_string_init_c_string("This is a TEST");
  if(hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  boolean = my_string_empty(hString);
  if (boolean == TRUE)
    {
      strncpy(buffer, "test_dbennett_empty_returns_FALSE_on_init_c_string\n"
	      "Failed and my_string_empty found an empty string when it was not empty\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_empty_returns_FALSE_on_init_c_string\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}

Status test_dbennett_compare_returns_negative_1_if_left_string_is_smaller(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int value;

  hLeft = my_string_init_c_string("s");
  hRight = my_string_init_c_string("bigger");

  if (hLeft == NULL || hRight == NULL)
    {
      printf("failed to allocate memory for one of the two strings\n");
      return FAILURE;
    }

  value = my_string_compare(hLeft, hRight);
  if(value != -1)
    {
      printf("Got a value of %d\n", value);
      strncpy(buffer, "test_dbennett_compare_returns_negative_1_if_left_string_is_smaller\n"
	      "Failed because it did not return -1\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_compare_returns_negative_1_if_left_string_is_smaller\n", length);
    }

  my_string_destroy((ITEM*)&hLeft);
  my_string_destroy((ITEM*)&hRight);

  return SUCCESS;
}

Status test_dbennett_compare_returns_1_if_right_string_is_smaller(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int value;

  hLeft = my_string_init_c_string("bigger");
  hRight = my_string_init_c_string("s");

  if (hLeft == NULL || hRight == NULL)
    {
      printf("failed to allocate memory for one of the two strings\n");
      return FAILURE;
    }

  value = my_string_compare(hLeft, hRight);
  if(value != 1)
    {
      printf("got value of %d\n", value);
      strncpy(buffer, "test_dbennett_compare_returns_1_if_right_string_is_smaller\n"
	      "Failed to get value of 1\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_compare_returns_1_if_right_string_is_smaller\n", length);
    }

  my_string_destroy((ITEM*)&hLeft);
  my_string_destroy((ITEM*)&hRight);

  return SUCCESS;
}

Status test_dbennett_compare_returns_0_if_the_two_strings_are_the_same_size(char* buffer, int length)
{
  MY_STRING hLeft = NULL;
  MY_STRING hRight = NULL;
  int value;

  hLeft = my_string_init_c_string("same");
  hRight = my_string_init_c_string("same");

  if (hLeft == NULL || hRight == NULL)
    {
      printf("failed to allocate memory for one of the two strings\n");
      return FAILURE;
    }

  value = my_string_compare(hLeft, hRight);
  if (value != 0)
    {
      printf("got value of %d\n", value);
      strncpy(buffer, "test_dbennett_compare_returns_0_if_the_two_strings_are_the_same_size\n"
	      "Failed to get value of 0\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_compare_returns_0_if_the_two_strings_are_the_same_size\n", length);
    }

  my_string_destroy((ITEM*)&hLeft);
  my_string_destroy((ITEM*)&hRight);

  return SUCCESS;
}

Status test_dbennett_extraction_returns_SUCCESS_if_a_non_empty_string_is_read_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  FILE* fp = NULL;
  Status status = FAILURE;

  
  hString = my_string_init_default();
  if(hString == NULL)
   {
    printf("failed to allocate memory for hString\n");
    return FAILURE;
   }

  fp = fopen("dbennett_test.txt", "w");
  if(fp == NULL)
  {
    printf("failed to open file\n");
    return FAILURE;
   }

  fprintf(fp, "\n\n\n");
  fprintf(fp, "THIS IS A TEST");
				   
  fprintf(fp, "\n\n");

  fclose(fp);
  
  fopen("dbennett_test.txt", "r");
  if(fp == NULL)
   {
    printf("failed to open file\n");
    return FAILURE;
   }

  status = my_string_extraction(hString, fp);
  if(status != SUCCESS)
  {
    printf("The string extracted reads: %s\n", my_string_c_str(hString));
    strncpy(buffer, "test_dbennett_extraction_returns_SUCCESS_if_a_non_empty_string_is_read_on_init_default\n"
  	      "Failed at extraction\n", length);
    return FAILURE;
  }
  else
  {
     strncpy(buffer, "test_dbennett_extraction_returns_SUCCESS_if_a_non_empty_string_is_read_on_init_default\n", length);
  }


  fclose(fp);
  my_string_destroy((ITEM*)&hString);

  return SUCCESS;
}


Status test_dbennett_extraction_returns_FAILURE_if_a_empty_string_is_read_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  FILE* fp = NULL;
  Status status;

  
  hString = my_string_init_default();
  if(hString == NULL)
   {
    printf("failed to allocate memory for hString\n");
    return FAILURE;
   }

  fp = fopen("dbennett_test.txt", "w");
  if(fp == NULL)
  {
    printf("failed to open file\n");
    return FAILURE;
   }

  fprintf(fp, "\n\n\n");
  fprintf(fp, "\n\n");

  fclose(fp);
  
  fopen("dbennett_test.txt", "r");
  if(fp == NULL)
   {
    printf("failed to open file\n");
    return FAILURE;
   }

  status = my_string_extraction(hString, fp);
  if(status == SUCCESS)
  {
    printf("The string extracted reads: %s\n", my_string_c_str(hString));
    strncpy(buffer, "test_dbennett_extraction_returns_FAILURE_if_a_empty_string_is_read_on_init_default\n"
  	      "Failed at extraction\n", length);
    return FAILURE;
  }
  else
  {
    strncpy(buffer, "test_dbennett_extraction_returns_FAILURE_if_a_empty_string_is_read_on_init_default\n", length);
  }

  my_string_destroy((ITEM*)&hString);
  fclose(fp);

  return SUCCESS;
}


Status test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_stdout(char* buffer, int length)
{

  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_c_string("HELLO WORLD");
  if (hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  status =  my_string_insertion(hString, stdout);
  if(status != SUCCESS)
    {
      strncpy(buffer,"test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_stdout\n"
	      "Failed and returned FAILURE after insertion\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_stdout\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}


Status test_dbennett_insertion_returns_FAILURE_if_string_is_empty(char* buffer, int length)
{

  MY_STRING hString = NULL;
  Status status;
  
  hString = my_string_init_default();
  if (hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  status =  my_string_insertion(hString, stdout);
  if(status == SUCCESS)
    {
      strncpy(buffer,"test_dbennett_insertion_returns_FAILURE_if_string_is_empty\n"
	      "Failed and returned SUCCESS after insertion on empty string\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_insertion_returns_FAILURE_if_string_is_empty\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}

  


Status test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_known_file(char* buffer, int length)
{
  MY_STRING hString = NULL;
  FILE* fp = NULL;
  Status status;
  
  hString = my_string_init_c_string("HELLO WORLD");
  if (hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  fp = fopen("dbennett_test.txt", "w");
  if(fp == NULL)
    {
      printf("failed to open file\n");
      return FAILURE;
    }
  

  status =  my_string_insertion(hString, fp);
  if(status != SUCCESS)
    {
      strncpy(buffer,"test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_known_file\n"
	      "Failed and returned FAILURE after insertion\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_known_file\n", length);
    }

  fclose(fp);
  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}


Status test_dbennett_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status = FAILURE;
  FILE* fp = NULL;
  
  hString = my_string_init_c_string("HELLO WORLD");
  if (hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }


  status =  my_string_insertion(hString, fp);
  if(status == SUCCESS)
    {
      strncpy(buffer,"test_dbennett_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist\n"
	      "Failed and returned SUCCESS after insertion on unknown FILE\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist\n", length);
    }

  my_string_destroy((ITEM*)&hString);
  return SUCCESS;
}


Status test_dbennett_c_str_returns_valid_address_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  char* value = NULL;

  hString = my_string_init_default();
  if(hString == NULL)
    {
      printf("failed to allocate memory for hString\n");
      return FAILURE;
    }

  value = my_string_c_str(hString);
  if (value == NULL)
    {
      strncpy(buffer, "test_dbennett_c_str_returns_valid_address_on_init_default\n"
	      "Failed and returned NULL after c_str\n", length);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_dbennett_c_str_returns_valid_address_on_init_default\n", length);
    }

  my_string_destroy((ITEM*)&hString);

  return SUCCESS;
}
