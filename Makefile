cc = gcc
EXEC = libmutile.so
DEP = -I./include/
SRC		=	$(shell find src/ -name "*.c")
OBJ		=	$(SRC:.c=.o)
DEK = # Flag de compilation

LIBPATHLIB = ${ROOT}/usr/lib
LIBPATHINC = ${ROOT}/usr/include

all : $(EXEC)


$(EXEC): $(OBJ)
	$(cc) -shared -o $(EXEC) $(OBJ) $(DEK) $(DEP)
	@echo "[COMPILE]" $@

.c.o:
	@gcc -c $< -o $@ $(DEP) $(DEK)
	@echo "[GCC]" $<

clean :
	@rm -f *.o *.so
	@rm -f $(shell find src/ -name "*.o")


install : all
	sudo cp -r $(EXEC) $(LIBPATHLIB) 
	sudo cp -r include/* $(LIBPATHINC) 
	@echo "[INSTALLED]" $(EXEC) "IN" $(LIBPATHLIB)
	@echo "[INSTALLED]" include/* "IN" $(LIBPATHINC)


uninstall : 
	sudo rm -f $(LIBPATHLIB)/$(EXEC) 
	sudo rm -f $(LIBPATHINC)/mutile.h 
	@echo "[UNINSTALLED]" $(EXEC) "IN" $(LIBPATHLIB)
	@echo "[UNINSTALLED]" include/* "IN" $(LIBPATHINC)


re : clean uninstall all install


.SUFFIXES: .c .o
