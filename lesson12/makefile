#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex12_1 ex12_2 ex12_3 ex12_4 ex12_5 ex12_6 ex12_6_1 ex12_7 \
		q12_1_1 q12_1_2 q12_2_1 q12_2_2 q12_2_3 q12_3

WEXECS	=	ex12_1.exe ex12_2.exe ex12_3.exe ex12_4.exe \
		ex12_5.exe ex12_6.exe ex12_6_1.exe ex12_7.exe \
		q12_1_1.exe q12_1_2.exe \
		q12_2_1.exe q12_2_2.exe q12_2_3.exe q12_3.exe

WORKDIR	=	lesson12

ARCHIVE	=	$(WORKDIR).zip

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGET)

clean:	
	-$(RM) $(WEXECS) $(TARGET)

zip:
	-(cd ..; $(ZIPCMD) $(ARCHIVE) $(WORKDIR)/q*.cpp $(WORKDIR)/data*.txt $(WORKDIR)/data*.csv $(WORKDIR)/makefile)

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
