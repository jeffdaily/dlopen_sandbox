CFLAGS = -Wall -ansi -pedantic

libdriver.so: driver.c driver.h
	$(CC) -shared -fPIC $(CFLAGS) -o $@ $<

clean:
	rm -f libdriver.so
