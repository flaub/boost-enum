.PHONY: package

DEPS=\
	Makefile \
	libs/test/enum.cpp \
	boost/enum.hpp \
	boost/enum/iterator.hpp \
	boost/enum/base.hpp \
	boost/enum/macros.hpp \
	boost/enum/bitfield.hpp 

test_enum : ${DEPS}
	g++ -Wall -Werror -I. -o test_enum libs/test/enum.cpp

enum.i : ${DEPS}
	g++ -I. -E -o enum.i libs/test/enum.cpp

package: 
	zip -r enum boost/ libs/ Makefile enum.sln enum.vcproj LICENSE_1_0.txt -x *.svn*

