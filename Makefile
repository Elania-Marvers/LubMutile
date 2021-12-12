cc = gcc
EXEC = src/libmutile.so
DEP = -I./include/
DEK = # Flag de compilation

LIBPATHLIB = ${ROOT}/usr/lib
LIBPATHINC = ${ROOT}/usr/include

all : install

install :
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
