#Makefile
#Řešení IJC-DU2, 20.4.2022
#Autor: Jakub Kontrík, FIT
CC=gcc
CFLAGS=-g -O2 -std=c11 -pg -pedantic -Wall -Wextra #-D HASHTEST


.PHONY: clean all zip
all: tail wordcount wordcount-dynamic libhtab.a libhtab.so

tail: tail.o error.o
	$(CC) $^ -o tail
wordcount: wordcount.o io.o libhtab.a error.o
	$(CC) $(CFLAGS)  $^ -o $@
wordcount-dynamic: wordcount.o io.o libhtab.so error.o
	$(CC) $(CFLAGS)  $^ -o $@

wordcount.o: wordcount.c htab.h error.h io.h
io.o: io.c io.h error.h
error.o: error.c error.h
tail.o: tail.c error.h

libhtab.a: htab_init.o htab_resize.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_hash_function.o htab_find.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o
	ar rcs libhtab.a $^
libhtab.so: htab_init.o htab_resize.o htab_size.o htab_bucket_count.o htab_lookup_add.o htab_hash_function.o htab_find.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o
	$(CC) $(CFLAGS) -fPIC -shared  -L "." $^ -o $@

htab_init.o: htab_init.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_resize.o: htab_resize.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_size.o: htab_size.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_bucket_count.o: htab_bucket_count.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_lookup_add.o: htab_lookup_add.c htab.h htab_struc.h 
	$(CC) $(CFLAGS) -fPIC -c $<
htab_find.o: htab_find.c htab.h htab_struc.h 
	$(CC) $(CFLAGS) -fPIC -c $<
htab_erase.o: htab_erase.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_for_each.o: htab_for_each.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_clear.o: htab_clear.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_free.o: htab_free.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<
htab_hash_function.o: htab_hash_function.c htab.h htab_struc.h
	$(CC) $(CFLAGS) -fPIC -c $<

clean:
	rm tail wordcount wordcount-dynamic *.o libhtab.so libhtab.a
zip:
	zip xkontr02.zip *.c *.cc *.h Makefile