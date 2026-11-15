CC = gcc
CFLAGS = -Wall -Wextra -std=c99

DIRS = 01_even_or_odd 02_sum_of_n_numbers 03_string_palindrome \
       04_number_palindrome 05_reverse_string 06_prime_number \
       07_factorial 08_vowels_consonants_digits 09_matrix_sum

.PHONY: all clean test

all:
	@for dir in $(DIRS); do \
		echo "Compiling programs in $$dir..."; \
		$(CC) $(CFLAGS) $$dir/server.c -o $$dir/server; \
		$(CC) $(CFLAGS) $$dir/client.c -o $$dir/client; \
		$(CC) $(CFLAGS) $$dir/udpserver.c -o $$dir/udpserver; \
		$(CC) $(CFLAGS) $$dir/udpclient.c -o $$dir/udpclient; \
	done
	@echo "=========================================================="
	@echo "All 36 programs compiled successfully across 9 variations!"
	@echo "=========================================================="

clean:
	@for dir in $(DIRS); do \
		rm -f $$dir/server $$dir/client $$dir/udpserver $$dir/udpclient; \
	done
	@echo "All compiled binaries removed."

test:
	@python3 test_all.py

