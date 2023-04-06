XX := flex
YY := bison
CC := gcc
INPUTXX := gcc.l
INPUTYY := gcc.y
OUTPUTCC := Gcc.o
OUTPUTXX := lex.yy.c
OUTPUTYY1 := y.tab.c
OUTPUTYY2 := y.tab.h

all :
	$(YY) -d -y $(INPUTYY)
	$(XX) $(INPUTXX)
	$(CC) -o $(OUTPUTCC) $(OUTPUTXX) $(OUTPUTYY1)

clean:
	rm -f $(OUTPUTCC)
	rm -f $(OUTPUTXX)
	rm -f $(OUTPUTYY1)
	rm -f $(OUTPUTYY2)

update:
	rm -f $(OUTPUTCC)
	rm -f $(OUTPUTXX)
	rm -f $(OUTPUTYY1)
	rm -f $(OUTPUTYY2)
	$(YY) -d -y $(INPUTYY)
	$(XX) $(INPUTXX)
	$(CC) -o $(OUTPUTCC) $(OUTPUTXX) $(OUTPUTYY1)
