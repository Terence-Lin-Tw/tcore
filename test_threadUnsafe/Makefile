.DEFAULT_GOAL = run-unsafe

.SILENT :

.RECIPEPREFIX = >
SHELL := bash
.SHELLFLAGS := -eu -o pipefail -c
.ONESHELL :
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

OBJDIR = bin
BIN_SO   = $(OBJDIR)/tclib.so

CFLAGS = -c -Wall -Werror -std=c11 -xc -g
CC     = gcc
PEEK   = ls -al --color $(OBJDIR)/

.PHONY : so
so : $(BIN_SO)
> $(eval PEEK_FLAG = Y)
> @$(PEEK)

.PHONY : run-unsafe
run-unsafe : clean _UnsetMacro $(BIN_SO)
> ./run.py

$(BIN_SO) : *.c
> $(CC) -Wall -g $(SAFE_MACRO) -shared -fPIC *.c -o $(BIN_SO)

.PHONY : run-safe
run-safe : clean _SetMacro $(BIN_SO)
> ./run.py

.PHONY : _SetMacro
_SetMacro :
> $(eval SAFE_MACRO = -DTHREAD_SAFE)

.PHONY : _UnsetMacro
_UnsetMacro :
> $(eval SAFE_MACRO = -DNOTHING)

.PHONY : clean
clean :
> @$(RM) $(BIN_SO) $(OBJDIR)/*
> $(PEEK)
