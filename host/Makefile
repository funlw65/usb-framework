GIT_REV=$(shell git rev-parse HEAD)

all: main.c
	gcc -o host -Wall -Wextra -DGIT_REV=\"$(GIT_REV)\" main.c `pkg-config --cflags --libs libusb-1.0`

clean:
	rm -f host 
