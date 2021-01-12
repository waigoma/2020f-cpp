#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex13_1 ex13_2 ex13_3 ex13_4 ex13_5 ex13_6 ex13_7 ex13_8 \
		q13_1 q13_2_1 q13_2_2 q13_3 q13_4 q13_5


WEXECS	=	ex13_1.exe ex13_2.exe ex13_3.exe ex13_4.exe ex13_5.exe \
		ex13_6.exe ex13_7.exe ex13_8.exe \
		q13_1.exe q13_2_1.exe q13_2_2.exe q13_3.exe q13_4.exe q13_5.exe

WORKDIR	=	lesson13

ARCHIVE	=	$(WORKDIR).zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) $(WORKDIR)/q*.cpp $(WORKDIR)/data* $(WORKDIR)/makefile)

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
