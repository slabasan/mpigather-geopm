all: prog

LIBS=-L$$HOME/ex-mpigather-geopm/geopm/build/lib -lgeopm
INC=-I$$HOME/ex-mpigather-geopm/geopm/build/include

prog: main.cpp
	mpicxx -Wall -O3 -g ${INC} -o $@ $< ${LIBS}

clean:
	rm -f prog
