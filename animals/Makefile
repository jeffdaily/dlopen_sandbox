app = dlopen_study
lib = libcat.so libdog.so

CFLAGS = -Wall -ansi -pedantic
LDFLAGS = -ldl

all: $(app) $(lib)

$(app): $(app).c
	$(CC) -o $@ $< -ldl

lib%.so: %.c
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

clean:
	$(RM) $(app) $(lib)

run: all
	./$(app) cat
	./$(app) dog
	-./$(app) bear

$(lib): animal.h
