CC = gcc
CFLAGS = -Wall -Werror -Wextra

.PHONY: all clean

all: lab

lab:
	@echo "Please specify a lab number and a target, e.g., make lab=1 target=lb2"

ifdef lab
	$(MAKE) -C lab$(lab) $(target)
endif

clean:
ifdef lab
	$(MAKE) -C lab$(lab) clean
endif

run:
ifdef lab
	./lab$(lab)/$(target)
endif
