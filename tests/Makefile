.DEFAULT_GOAL = SHOW_INFO

.SILENT :

.RECIPEPREFIX = >
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c
.ONESHELL :
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

TEST = $(BASE)_tests
SRC = ..
BIN = ../bin
BIN_PARENT = bin

UT_HOME = TEST_FACILITY/CPPUTEST_HOME
PROG_DIR = .
CXXFLAGS += -I$(UT_HOME)/include -I$(PROG_DIR) -Wall -Werror -g
UT_LIB = ${UT_HOME}/lib
CXX = g++

#--------------------------------
# FINAL STEP
#--------------------------------
$(BIN)/$(TEST) : $(TEST).cpp $(TEST).hpp $(BIN)/$(BASE).o
> $(CXX) $(CXXFLAGS) $< $(BIN)/$(BASE).o -L$(UT_LIB) -lCppUTest -o $@

$(BIN)/$(BASE).o : $(SRC)/$(BASE).c $(SRC)/$(BASE).h
> cd .. && $(MAKE) $(BIN_PARENT)/$(BASE).o

.PHONY: run
ifndef BASE
> echo Usage: ./sh_run.sh
> exit 1
endif

run : $(BIN)/$(TEST)
> - $(BIN)/$(TEST) -c -v

.PHONY : leak
leak : $(BIN)/$(TEST)
> $(eval  TMP_FILE=$(shell mktemp -q /tmp/$(TEST).XXXXXX)  )
> - valgrind  -s --leak-check=full --show-leak-kinds=all  $(BIN)/$(TEST) > $(TEST)_leak.txt 2>&1

.PHONY: clean
clean:
> rm -f $(BIN)/*_tests
> cd .. && $(MAKE) clean

.PHONY: SHOW_INFO
SHOW_INFO :
> echo
> echo "Usage:"
> echo "    ./sh_run.sh"
> echo
> exit 0
