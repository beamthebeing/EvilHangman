#ifndef TEST_DEF_H
#define TEST_DEF_H
#include "my_string.h"
#include "status.h"

/*
Precondition: 
Postcondition: initialize an array of function pointers where every function
pointer will hold the address of a test function
 */

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_dbennett_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_dbennett_init_c_string_returns_nonNULL(char* buffer, int length);
Status test_dbennett_get_size_on_init_c_string_for_TEST_returns_4(char* buffer, int length);
Status test_dbennett_get_capacity_on_init_c_string_for_TEST_returns_5(char* buffer, int length);
Status test_dbennett_push_back_10000_characters(char* buffer, int length);
Status test_dbennett_push_back_10000_characters_then_pop_back_them_all(char* buffer, int length);
Status test_dbennett_my_string_at_returns_null_for_init_default(char* buffer, int length);
Status test_dbennett_my_string_at_returns_nonNULL_address_for_init_default_after_push_back(char* buffer, int length);
Status test_dbennett_my_string_at_returns_valid_address_for_init_c_string(char* buffer, int length);
Status test_dbennett_concat_returns_SUCCESS_if_both_strings_are_empty(char* buffer, int length);
Status test_dbennett_concat_does_not_change_hAppend(char* buffer, int length);
Status test_dbennett_empty_returns_TRUE_on_init_default(char* buffer, int length);
Status test_dbennett_empty_returns_FALSE_on_init_c_string(char* buffer, int length);
Status test_dbennett_compare_returns_negative_1_if_left_string_is_smaller(char* buffer, int length);
Status test_dbennett_compare_returns_1_if_right_string_is_smaller(char* buffer, int length);
Status test_dbennett_compare_returns_0_if_the_two_strings_are_the_same_size(char* buffer, int length);
Status test_dbennett_extraction_returns_SUCCESS_if_a_non_empty_string_is_read_on_init_default(char* buffer, int length);
Status test_dbennett_extraction_returns_FAILURE_if_a_empty_string_is_read_on_init_default(char* buffer, int length);
Status test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_stdout(char* buffer, int length);
Status test_dbennett_insertion_returns_FAILURE_if_string_is_empty(char* buffer, int length);
Status test_dbennett_insertion_successfully_prints_HELLO_WORLD_to_known_file(char* buffer, int length);
Status test_dbennett_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist(char* buffer, int length);
Status test_dbennett_c_str_returns_valid_address_on_init_default(char* buffer, int length);


#endif
