# This makefile can be used to build all or some of the sample
# programs.  To build all of them, use the command
# 'make all'.  To build one, say addtwo, use the command
# 'make addtwo'.

# Portions of this makefile require the use of GNU make.
# see http://www.gnu.org/software/make for more information.

VERSION=10.0
WSLINKDIR = $(shell pwd)/..
SYS = MacOSX-x86-64
CADDSDIR = ${WSLINKDIR}/CompilerAdditions
EXTRA_CFLAGS=-stdlib=libstdc++ -stdlib=libc++ -stdlib=libc++

INCDIR = ${CADDSDIR}
LIBDIR = ${CADDSDIR}

WSPREP = ${CADDSDIR}/wsprep
RM = rm

BINARIES = addtwo bitops counter factor factor2 factor3 quotient reverse sumalist

all : $(BINARIES)

algorithm3 : algorithm3tm.o algorithm3.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} algorithm3tm.o algorithm3.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

algorithm2 : algorithm2tm.o algorithm2.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} algorithm2tm.o algorithm2.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

algorithm1 : algorithm1tm.o algorithm1.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} algorithm1tm.o algorithm1.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

updownstac : updownstactm.o updownstac.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} updownstactm.o updownstac.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@


bits : bitstm.o bits.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} bitstm.o bits.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

addtwo : addtwotm.o addtwo.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} addtwotm.o addtwo.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

bitops : bitopstm.o bitops.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} bitopstm.o bitops.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

counter : countertm.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} countertm.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

factor : factor.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} factor.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

factor2 : factor2.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} factor2.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

factor3 : factor3.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} factor3.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

quotient : quotient.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} quotient.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

reverse : reversetm.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} reversetm.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

sumalist : sumalisttm.o
	${CXX} ${EXTRA_CFLAGS} -I${INCDIR} sumalisttm.o -L${LIBDIR} -lWSTPi4 -lc++ -framework Foundation -o $@

%.o : %.cxx
	${CXX} -c ${EXTRA_CFLAGS} -I${INCDIR} $<

algorithm3tm.cxx : algorithm3.tm
	${WSPREP} $? -o $@

algorithm2tm.cxx : algorithm2.tm
	${WSPREP} $? -o $@

algorithm1tm.cxx : algorithm1.tm
	${WSPREP} $? -o $@

updownstactm.cxx : updownstac.tm
	${WSPREP} $? -o $@

addtwotm.cxx : addtwo.tm
	${WSPREP} $? -o $@

bitopstm.cxx : bitops.tm
	${WSPREP} $? -o $@

bitstm.cxx : bits.tm
	${WSPREP} $? -o $@

countertm.cxx : counter.tm
	${WSPREP} $? -o $@

reversetm.cxx : reverse.tm
	${WSPREP} $? -o $@

sumalisttm.cxx : sumalist.tm
	${WSPREP} $? -o $@

clean :
	@ ${RM} -rf *.o *tm.cxx $(BINARIES)
