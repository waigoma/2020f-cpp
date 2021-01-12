#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex9_1 ex9_2 ex9_3 ex9_4 ex9_5 ex9_6 \
		q9_1 q9_2_1 q9_2_2 q9_3_1 q9_3_2 q9_3_3 q9_4_1

WEXECS	=	ex9_1.exe ex9_2.exe ex9_3.exe ex9_4.exe ex9_5.exe ex9_6.exe \
		q9_1.exe q9_2_1.exe q9_2_2.exe \
		q9_3_1.exe q9_3_2.exe q9_3_3.exe q9_4_1.exe

WORKDIR	=	lesson09

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
