PROG :=
CC = musl-gcc 
CFLAGS := -Wall -pthread


program:
	@read -p "Enter source file: " PROG;\
	$(CC) $(CFLAG) $(PROG).c ../libget_num.a ../liberror_functions.a -o $PROG

.PHONY: clean

clean: 
	rm -f $(PROG)
