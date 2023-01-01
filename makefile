SRC = $(wildcard src/*.c)
MSRC= src/sqrt.c src/thqc3q.c src/thqc4q.c src/thqc5q.c src/thqc2q4.6.c
MOBJ= $(patsubst src/%.c,obj/%.o,$(MSRC))
MBIN= $(patsubst obj/%.o,min/%,$(MOBJ))
OBJ = $(filter-out $(MOBJ),$(patsubst src/%.c,obj/%.o,$(SRC)))
BIN = $(filter-out $(MBIN),$(patsubst obj/%.o,bin/%,$(OBJ)))

all    : $(BIN) $(MBIN)
	mv min/* bin/
$(OBJ) : $(SRC)
$(BIN) : $(OBJ)
$(MBIN): $(MOBJ)

obj/%.o: src/%.c
	gcc -o $@ -c $<
bin/%: obj/%.o
	gcc -o $@ $<
min/%: obj/%.o
	gcc -lm -o $@ $<


clean:
	rm -f obj/* bin/* min/*
