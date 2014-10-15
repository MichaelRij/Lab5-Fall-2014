CC = g++
OBJ = prog.o

prog: $(OBJ)
	$(CC) $(OBJ) -o $@

.cpp.o:
	$(CC) -c $<

clean: 
	rm *.o prog
