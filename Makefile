.PHONY: compile run clean

OUT_FILE = out.exe
WORKING_FILES = main.c funcs.c

compile: $(WORKING_FILES)
	gcc $(WORKING_FILES) -o $(OUT_FILE)
run: compile
	./$(OUT_FILE)
clean:
	rm *.o $(OUT_FILE)