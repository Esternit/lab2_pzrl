.PHONY: all clean run

OUT_FILE = out.exe


all: $(OUT_FILE)

main.o: main.c
	gcc -c main.c

funcs_binary.o: funcs_binary.c
	gcc -c funcs_binary.c

funcs_eight.o: funcs_eight.c
	gcc -c funcs_eight.c

funcs_sixteen.o: funcs_sixteen.c
	gcc -c funcs_sixteen.c

base_funcs.o: base_funcs.c 
	gcc -c base_funcs.c

run: $(OUT_FILE)
	./$(OUT_FILE)
clean:
	rm *.o $(OUT_FILE)

$(OUT_FILE): main.o funcs_binary.o funcs_eight.o funcs_sixteen.o base_funcs.o
	gcc main.o funcs_double.o funcs_eight.o funcs_sixteen.o base_funcs.o -o $(OUT_FILE)