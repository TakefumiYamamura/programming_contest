CC_FILES = $(wildcard */*.cc)
BIN_FILES = $(notdir $(CC_FILES:.cc=))
CC_FLAGS = -std=c++0x -Wall -O2 -lm
CC = g++

.SECONDEXPANSION:
$(BIN_FILES): %: $$(wildcard */$$**.cc)
	$(CC) $(CC_FLAGS) -o $@ $<

clean:
	rm -f $(BIN_FILES)