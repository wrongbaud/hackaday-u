SRCS=$(wildcard *.c)

OBJS=$(SRCS:.c=)

ASM=$(SRCS:.c=.S)

bins: $(OBJS)

asm:
	$(foreach var,$(OBJS),objdump -d -M intel $(var) > $(var).S;)
