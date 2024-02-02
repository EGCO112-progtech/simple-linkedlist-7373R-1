compile: main.c 
	 gcc main.c -o tatar

run: tatar
	 ./tatar

clean: tatar
	 rm tatar
