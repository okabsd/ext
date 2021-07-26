CC := cc
CFLAGS :=
DEPS :=
OBJ := ext.o
BUILD := build
WARN := -Wall

PROG := ext
PREFIX := /usr/local
MAN := /share/man/man1/

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(WARN)

build/$(PROG): $(OBJ)
	mkdir -p $(BUILD)
	$(CC) -o $@ $^ $(CFLAGS) $(WARN)

install:
	cp $(BUILD)/$(PROG) $(PREFIX)/bin
	mkdir -p $(PREFIX)$(MAN)
	cp $(PROG).1 $(PREFIX)$(MAN)

uninstall:
	rm $(PREFIX)/bin/$(PROG)
	rm $(PREFIX)$(MAN)$(PROG).1

clean:
	rm -r $(OBJ)
	rm -rf $(BUILD)/

.PHONY: install uninstall clean
