#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex11_1 ex11_2 ex11_3 ex11_4 ex11_5 ex11_6 \
		q11_1 q11_2_1 q11_2_2 q11_2_3 q11_3 q11_4_1 q11_4_2

WEXECS	=	ex11_1.exe ex11_2.exe ex11_3.exe ex11_4.exe \
		ex11_5.exe ex11_6.exe \
		q11_1.exe q11_2_1.exe q11_2_2.exe q11_2_3.exe \
		q11_3.exe q11_4_1.exe q11_4_2.exe

WORKDIR	=	lesson11

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
