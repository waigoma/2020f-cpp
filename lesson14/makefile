#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
LINK.o		=	$(LINK.cc)
LDLIBS		=	-lgdi32
DEBUG		=
DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	Test ex14_1 ex14_2 ex14_3 ex14_4 \
		q14_1_1 q14_1_2 q14_1_3 q14_2_1 \
		q14_2_2 q14_3_1 q14_3_2 q14_4_1 q14_4_2

OBJS	=	Test.o ex14_1.o ex14_2.o ex14_3.o ex14_4.o \
		q14_1_1.o q14_1_2.o q14_1_3.o q14_2_1.o \
		q14_2_2.o q14_3_1.o q14_3_2.o q14_4_1.o q14_4_2.o

WEXECS	=	Test.exe ex14_1.exe ex14_2.exe ex14_3.exe ex14_4.exe \
		q14_1_1.exe q14_1_2.exe q14_1_3.exe q14_2_1.exe \
		q14_2_2.exe q14_3_1.exe q14_3_2.exe q14_4_1.exe q14_4_2.exe

WORKDIR	=	lesson14

ARCHIVE	=	$(WORKDIR).zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(OBJS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) $(WORKDIR)/q*.cpp $(WORKDIR)/canvas/canvas.h $(WORKDIR)/canvas/canvas.cpp $(WORKDIR)/makefile)

Test:		Test.o canvas/canvas.o
ex14_1:		ex14_1.o canvas/canvas.o
ex14_2:		ex14_2.o canvas/canvas.o
ex14_3:		ex14_3.o
ex14_4:		ex14_4.o
q14_1_1:	q14_1_1.o canvas/canvas.o
q14_1_2:	q14_1_2.o canvas/canvas.o
q14_1_3:	q14_1_3.o canvas/canvas.o
q14_2_1:	q14_2_1.o canvas/canvas.o
q14_2_2:	q14_2_2.o canvas/canvas.o
q14_3_1:	q14_3_1.o
q14_3_2:	q14_3_2.o
q14_4_1:	q14_4_1.o
q14_4_2:	q14_4_2.o canvas/canvas.o

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
