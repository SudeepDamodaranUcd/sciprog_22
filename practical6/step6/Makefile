CC = gcc
CCFLAGS = -O3
LDFLAGS = -lm

all: matmultc

matmultc: main.o matmult.o
    $(CC) -o $@ $^ $(LDFLAGS)
##$(CC) -o matmultc main.o matmult.o $(LDFLAGS) 

matmult.o: matmult.c
    $(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) matmult.c

main.o: main.c
    $(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) main.c

clean:
    rm *.o
