CC = gcc -g 
CFLAGS = -Wall --std=c99
STRING_OBJECTS = main.o my_string.o generic.o 
UNIT_OBJECTS = my_string.o unit_test.o test_def.o



string_driver: $(STRING_OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $(STRING_OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic.o: generic.c
	$(CC) $(CFLAGS) -c generic.c -o generic.o



unit_test: $(UNIT_OBJECTS)
	$(CC) $(CFLAGS) -o unit_test $(UNIT_OBJECTS)
unit_test.o: unit_test.c
	$(CC) $(CFLAGS) -c unit_test.c -o unit_test.o
test_def.o: test_def.c
	$(CC) $(CFLAGS) -c test_def.c -o test_def.o


clean:
	rm string_driver $(STRING_OBJECTS)
clean_unit:
	rm unit_test dbennett_test.txt $(UNIT_OBJECTS)




