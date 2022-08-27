.DEFAULT_GOAL = run

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

$(OBJDIR)/%.o : %.c %.h
> $(CC) $(CFLAGS) $< -o $@

.PHONY : so
so : $(BIN_SO)
> $(eval PEEK_FLAG = Y)
> @$(PEEK)

.PHONY : run
run : $(BIN_SO)
> ./run.py

$(BIN_SO) : *.c
> $(CC) -Wall -g -shared -fPIC *.c -o $(BIN_SO)

.PHONY : clean
clean :
> @$(RM) $(BIN_SO) $(OBJDIR)/*
> $(PEEK)
