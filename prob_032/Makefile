prob_032: prob_032.c tree.h tree.o types.vim tags
	gcc -Wall -ansi -pedantic-errors -g prob_032.c tree.o -o prob_032

tree.o: tree.c tree.h
	gcc -Wall -ansi -pedantic-errors -g -c tree.c -o tree.o

tags: tree.c tree.h prob_032.c
	ctags *

types: types.vim
types.vim: *.[ch]
	ctags --c-kinds=gstu -o- *.[ch] |\
		awk 'BEGIN{printf("syntax keyword Type\t")}\
			{printf("%s ", $$1)}END{print ""}' > $@

clean:
	rm -f *.o types.vim tags prob_032
