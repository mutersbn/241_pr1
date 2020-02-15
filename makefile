EXEC := p1

all: sort.c p1.c sort.h
	gcc sort.c p1.c -g -o $(EXEC)

run: 
	./$(EXEC)

clean:
	$(RM) $(EXEC)
