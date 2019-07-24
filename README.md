# The_Evil_Hangman

An alternate take on the classic game Hangman where a user has a limited number of guesses to guess all the letters in a word of length, N. 
  
Evil Hangman stores words of length N from a dictionary in a root list. When the user makes a letter guess the program creates different "keys" representing permutations where letter guessed is located in each word of the current root list, included a "key" for words that don't contain the letter guessed. All the words in the root list are then filtered and added to new lists matching the same "key". The new list with the largest value then becomes the new root list. The process repeats until the user is out of guesses or the word has been guessed, which usually means the current root list holds very few words.



MAIN PROGRAM FILES:
  generic.c
  generic.h
  my_string.c
  my_string.h
  status.h
  main.c


TESTBENCH FILES:
  test_def.c 
  unit_test.c
  unit_test.h
  
  
