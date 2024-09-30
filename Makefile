collatz: collatz.c 
	gcc -o collatz collatz.c LRUCache.c FIFOCache.c CollatzCore.c

clean:
	rm collatz