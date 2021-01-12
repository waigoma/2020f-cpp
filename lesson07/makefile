#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex7_1 ex7_2 ex7_3 ex7_4 ex7_5 ex7_6 ex7_7 ex7_8 \
		q7_1_1 q7_1_2 q7_1_3 q7_2_1 q7_2_2 q7_3_1 q7_3_2 q7_4_1 q7_4_2

WEXECS	=	ex7_1.exe ex7_2.exe ex7_3.exe ex7_4.exe ex7_5.exe ex7_6.exe \
		ex7_7.exe ex7_8.exe \
		q7_1_1.exe q7_1_2.exe q7_1_3.exe q7_2_1.exe q7_2_2.exe \
		q7_3_1.exe q7_3_2.exe q7_4_1.exe q7_4_2.exe

WORKDIR	=	lesson07

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
