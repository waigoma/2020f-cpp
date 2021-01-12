#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

TARGET	=	ex5_1 ex5_2 ex5_3 ex5_4 ex5_5 \
		ex5_6 ex5_7 ex5_8 ex5_9 ex5_10 \
		q5_1 q5_2_1 q5_2_2 q5_2_3 q5_2_4 \
		q5_3_1 q5_3_2 q5_3_3 q5_4_1 q5_4_2

WEXECS	=	ex5_1.exe ex5_2.exe ex5_3.exe ex5_4.exe ex5_5.exe \
		ex5_6.exe ex5_7.exe ex5_8.exe ex5_9.exe ex5_10.exe \
		q5_1.exe q5_2_1.exe q5_2_2.exe q5_2_3.exe q5_2_4.exe \
		q5_3_1.exe q5_3_2.exe q5_3_3.exe q5_4_1.exe q5_4_2.exe

WORKDIR	=	lesson05

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
