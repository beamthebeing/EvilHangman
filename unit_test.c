#include <stdio.h>
#include "unit_test.h"
#include "status.h"

/*
Purpose: 


 */

int main(int argc, char* argv[]){

  Status (*tests[])(char*, int) =
  {
    test_init_default_returns_nonNULL,
    test_get_size_on_init_default_returns_0,
    test_dbennett_get_capacity_on_init_default_returns_7,
    test_dbennett_init_c_string_returns_nonNULL,
    test_dbennett_get_size_on_init_c_string_for_TEST_returns_4,
    test_dbennett_get_capacity_on_init_c_string_for_TEST_returns_5,
    test_dbennett_push_back_10000_characters,
    test_dbennett_push_back_10000_characters_then_pop_back_them_all,
    test_dbennett_my_string_at_returns_null_for_init_default,
    test_dbennett_my_string_at_returns_nonNULL_address_for_init_default_after_push_back,
    test_dbennett_my_string_at_returns_valid_address_for_init_c_string,
    test_dbennett_concat_returns_SUCCESS_if_both_strings_are_empty,
    test_dbennett_concat_does_not_change_hAppend,
    test_dbennett_empty_returns_TRUE_on_init_default,
    test_dbennett_empty_returns_FALSE_on_init_c_string,
    test_dbennett_compare_returns_negative_1_if_left_string_is_smaller,
    test_dbennett_compare_returns_1_if_right_string_is_smaller,
    test_dbennett_compare_returns_0_if_the_two_strings_are_the_same_size,
    test_dbennett_extraction_returns_SUCCESS_if_a_non_empty_string_is_read_on_init_default, 
    test_dbennett_extraction_returns_FAILURE_if_a_empty_string_is_read_on_init_default, 
    test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_stdout,
    test_dbennett_insertion_returns_FAILURE_if_string_is_empty,
    test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_known_file,
    test_dbennett_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist,
    test_dbennett_c_str_returns_valid_address_on_init_default   
  };
  
  int number_of_functions = sizeof(tests)/sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;

  for(i=0; i<number_of_functions; i++)
  {
    if(tests[i](buffer, 500) == FAILURE)
    {
      printf("FAILED: TEST %d failed miserably\n", i);
      printf("\t%s\n", buffer);
      failure_count++;
    }
    else
    {
      // printf("PASS: Test %d passed\n", i);
      // printf("\t%s\n", buffer);
      success_count++;
    }
  }
  printf("Total number of tests: %d\n", number_of_functions);
  printf("%d/%d Pass, %d/%d Failure\n", success_count,
	 number_of_functions, failure_count, number_of_functions);

  return 0;
}
