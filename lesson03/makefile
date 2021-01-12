#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip


TARGET	=	ex3_1 ex3_2 ex3_3 ex3_4 ex3_5  ex3_6 ex3_7 ex3_8 \
		q3_1_1 q3_1_2 q3_2 q3_3_1 q3_3_2 q3_3_3 q3_4_1 q3_4_2

WEXECS	=	ex3_1.exe ex3_2.exe ex3_3.exe ex3_4.exe ex3_5.exe \
		ex3_6.exe ex3_7.exe ex3_8.exe \
		q3_1_1.exe q3_1_2.exe q3_2.exe \
		q3_3_1.exe q3_3_2.exe q3_3_3.exe q3_4_1.exe q3_4_2.exe

ARCHIVE	=	lesson03.zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) lesson03/q*.cpp)

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
