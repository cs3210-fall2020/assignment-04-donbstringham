# Author: Don Stringham <donstringham@weber.edu>
.DEFAULT_GOAL=clean

# VARIABLES
CC=gcc
BUILD_TIME ?= $(shell date +%FT%T%z)
SDIR=./src
ODIR=$(SDIR)
BDIR=./bin

# TARGETS
bld: 
	$(CC) $(CFLAGS) $(SDIR)/myshell.c -o $(BDIR)/mysh -L/usr/local/Cellar/readline/8.0.4/lib

run:
	$(BDIR)/mysh

release:
	git tag v$(V)
	@read -p "Press enter to confirm and push to origin ..." && git push origin v$(V)

.PHONY: clean
clean:
	-rm -r $(BDIR)
	-rm -f $(ODIR)/*.o
