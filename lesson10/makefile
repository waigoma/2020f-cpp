#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip


TARGET	=	ex10_1 ex10_2 ex10_3 ex10_4 ex10_5 ex10_6 ex10_7 \
		q10_1_1 q10_1_2 q10_2 q10_3_1 q10_3_2 q10_4

WEXECS	=	ex10_1.exe ex10_2.exe ex10_3.exe ex10_4.exe ex10_5.exe \
		ex10_6.exe ex10_7.exe \
		q10_1_1.exe q10_1_2.exe q10_2.exe q10_3_1.exe q10_3_2.exe \
		q10_4.exe

WORKDIR	=	lesson10

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
