#MakeFile for tmapp
PROGNAME = tmapp

default: tmapp

tmapp: tmapp.o
	g++ -g -o $@ tmapp.o 

tmapp.o: tmapp.cpp
	g++ -g -c tmapp.cpp

clean:
	rm *.o

immaculate:
	rm -f $(PROGNAME)

