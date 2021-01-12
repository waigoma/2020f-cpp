#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex4_1 ex4_2_1 ex4_2_2 ex4_3 ex4_4_1 ex4_4_2 ex4_5 ex4_6 \
		q4_1_1 q4_1_2 q4_1_3 q4_2_1 q4_2_2 q4_3 q4_4 \
		q4_5_1 q4_5_2 q4_5_3 q4_6_1 q4_6_2 q4_6_3

WEXECS	=	ex4_1.exe ex4_2_1.exe ex4_2_2.exe ex4_3.exe \
		ex4_4_1.exe ex4_4_2.exe ex4_5.exe ex4_6.exe \
		q4_1_1.exe q4_1_2.exe q4_1_3.exe \
		q4_2_1.exe q4_2_2.exe q4_3.exe q4_4.exe \
		q4_5_1.exe q4_5_2.exe q4_5_3.exe q4_6_1.exe \
		q4_6_2.exe q4_6_3.exe

WORKDIR	=	lesson04

ARCHIVE	=	$(WORKDIR).zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) $(WORKDIR)/q*.cpp)

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
