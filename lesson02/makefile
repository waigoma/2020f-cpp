#
#	makefile
#

CXX		=	g++
CXXFLAGS	=	$(CXXINCLUDE) $(DEBUG)
CXXINCLUDE	=
DEBUG		=
## DEBUG		=	-g


TARGET	=	ex1_2.exe ex1_3.exe \
		ex2_3.exe ex2_4.exe ex2_5.exe ex2_6.exe ex2_7.exe ex2_8.exe \
		q2_1.exe q2_2.exe q2_3.exe q2_4.exe

default:
	@echo make XXX となるようにターゲットを指定してください

ex1_2:		ex1_2.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

ex1_2.exe:	ex1_2.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

ex1_3:		ex1_3.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

ex1_3.exe:	ex1_3.cpp
	$(CXX) -o $@ $(CXXFLAGS) $<

all:	$(TARGET)

clean:	
	-$(RM) $(TARGET)
