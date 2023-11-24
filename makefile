SRC = $(wildcard src/*.c)
MSRC= src/sqrt.c src/thqc3q.c src/thqc4q.c src/thqc5q.c src/thqc2q.c src/thqc7q.c
MOBJ= $(patsubst src/%.c,obj/%.o,$(MSRC))
MBIN= $(patsubst obj/%.o,min/%,$(MOBJ))
OBJ = $(filter-out $(MOBJ),$(patsubst src/%.c,obj/%.o,$(SRC)))
BIN = $(filter-out $(MBIN),$(patsubst obj/%.o,bin/%,$(OBJ)))

.PHONY: all

all    : $(BIN) $(MBIN)
	mv min/* bin/
$(OBJ) : $(SRC)
$(BIN) : $(OBJ)
$(MBIN): $(MOBJ)

obj/%.o: src/%.c
	gcc -g -c $< -o $@
bin/%: obj/%.o
	gcc -o $@ $<
min/%: obj/%.o
	gcc -lm -o $@ $<

init:
	mkdir -p min bin obj

clean:
	rm -f obj/* bin/* min/* 
	rm -f *.EXE *.OBJ
	rm -f src/*.EXE src/*.OBJ src/*.O
	rm -f src/*.exe src/*.obj src/*.o
