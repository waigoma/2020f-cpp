#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
LINK.o		=	$(LINK.cc)
LDLIBS		=	-lgdi32
LOADLIBS	=	canvas/canvas.o
DEBUG		=
## DEBUG		=	-g
ZIPCMD		=	zip

THIS		=	$(TARGET09)
TARGETS		=	$(TARGET01) $(TARGET02) $(TARGET03) $(TARGET04) \
			$(TARGET05) $(TARGET06) $(TARGET07) $(TARGET08) \
			$(TARGET09)
OBJS		=	$(OBJSCV) $(OBJS01) $(OBJS02) $(OBJS03) $(OBJS04) \
			$(OBJS05) $(OBJS06) $(OBJS07) $(OBJS08) $(OBJS09)
WEXECS		=	$(WEXECS01) $(WEXECS02) $(WEXECS03) $(WEXECS04) \
			$(WEXECS05) $(WEXECS06) $(WEXECS07) $(WEXECS08) \
			$(WEXECS09)
SRC		=	$(SRC09) $(SRCCV)

TITLE		=	adv09
ARCHIVE		=	$(TITLE).zip

####
TARGET09	=	adv09
OBJS09		=	adv09.o
WEXECS09	=	adv09.exe
SRC09		=	adv09.cpp

TARGET08	=	adv08
OBJS08		=	adv08.o
WEXECS08	=	adv08.exe
SRC08		=	adv08.cpp

TARGET07	=	adv07
OBJS07		=	adv07.o
WEXECS07	=	adv07.exe
SRC07		=	adv07.cpp

TARGET06	=	adv06 adv06-sub1 adv06-sub2 adv06-sub3
OBJS06		=	adv06.o adv06-sub1.o adv06-sub2.o adv06-sub3.o
WEXECS06	=	adv06.exe adv06-sub1.exe adv06-sub2.exe adv06-sub3.exe
SRC06		=	adv06.cpp adv06-sub1.cpp adv06-sub2.cpp adv06-sub3.cpp

TARGET05	=	adv05
OBJS05		=	adv05.o
WEXECS05	=	adv05.exe
SRC05		=	adv05.cpp

TARGET04	=	adv04
OBJS04		=	adv04.o
WEXECS04	=	adv04.exe
SRC04		=	adv04.cpp

TARGET03	=	adv03 adv03-sub
OBJS03		=	adv03.o adv03-sub.o
WEXECS03	=	adv03.exe adv03-sub.exe
SRC03		=	adv03.cpp adv03-sub.cpp

TARGET02	=	adv02-pre adv02 adv02-sub
OBJS02		=	adv02-pre.o adv02.o adv02-sub.o
WEXECS02	=	adv02-pre.exe adv02.exe adv02-sub.exe
SRC02		=	adv02-pre.cpp adv02.cpp adv02-sub.cpp 

TARGET01	=	Test adv01
OBJS01		=	Test.o adv01.o
WEXECS01	=	Test.exe adv01.exe
SRC01		=	adv01.cpp

OBJSCV		=	canvas/canvas.o
SRCCV		=	canvas/canvas.cpp canvas/canvas.h

default:
	@echo make XXX となるようにターゲットを指定してください

all:	$(TARGETS)

this:	$(THIS)

clean:	
	-$(RM) $(WEXECS) $(TARGETS) $(OBJS)

zip:
	-$(ZIPCMD) $(ARCHIVE) $(SRC)

adv09:			adv09.o canvas/canvas.o
adv08:			adv08.o canvas/canvas.o
adv07:			adv07.o canvas/canvas.o
adv06:			adv06.o canvas/canvas.o
adv06-sub1:		adv06-sub1.o canvas/canvas.o
adv06-sub2:		adv06-sub2.o canvas/canvas.o
adv06-sub3:		adv06-sub3.o canvas/canvas.o
adv05:			adv05.o canvas/canvas.o
adv04:			adv04.o
adv03:			adv03.o canvas/canvas.o
adv03-sub:		adv03-sub.o canvas/canvas.o
adv02-pre:		adv02-pre.o canvas/canvas.o
adv02:			adv02.o canvas/canvas.o
adv02-sub:		adv02-sub.o canvas/canvas.o
adv01:			adv01.o canvas/canvas.o
Test:			Test.o canvas/canvas.o

canvas/canvas.o:	canvas/canvas.cpp canvas/canvas.h

##
##	extra rules for cygwin
##
.SUFFIXES:	.cpp .exe

.cpp.exe:
		$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
