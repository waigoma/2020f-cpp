#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex6_1 ex6_2 ex6_3 ex6_4 ex6_5 ex6_6  \
		q6_1_1 q6_1_2 q6_1_3 q6_2 q6_3_1 q6_3_2 q6_4_1 q6_4_2 \
		q6_5_1 q6_5_2

WEXECS	=	ex6_1.exe ex6_2.exe ex6_3.exe ex6_4.exe ex6_5.exe ex6_6.exe \
		q6_1_1.exe q6_1_2.exe q6_1_3.exe q6_2.exe \
		q6_3_1.exe q6_3_2.exe q6_4_1.exe q6_4_2.exe \
		q6_5_1.exe q6_5_2.exe

WORKDIR	=	lesson06

ARCHIVE	=	$(WORKDIR).zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) $(WORKDIR)/q*.cpp $(WORKDIR)/makefile)

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
