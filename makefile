#MakeFile for Turing Machine App
PROGNAME = tmapp
CPPFLAGS = -g

#default: tmapp

default: tmapp
#	g++ -g -o $@ tmapp.o turing_machine.o tape.o input_alphabet.o tape_alphabet.o transition_function.o states.o final_states.o

tmapp: main.cpp commands.o tape.o turing_machine.o input_alphabet.o tape_alphabet.o transition_function.o transition.o states.o final_states.o validate.o uppercase.o
	g++ -g -o $@ main.cpp commands.o turing_machine.o tape.o input_alphabet.o tape_alphabet.o transition_function.o transition.o states.o final_states.o validate.o uppercase.o

turing_machine.o: turing_machine.cpp turing_machine.h
	g++ -g -c turing_machine.cpp turing_machine.h

tape.o: tape.cpp tape.h
	g++ -g -c tape.cpp tape.h

input_alphabet.o: input_alphabet.cpp input_alphabet.h
	g++ -g -c input_alphabet.cpp input_alphabet.h

tape_alphabet.o: tape_alphabet.cpp tape_alphabet.h
	g++ -g -c tape_alphabet.cpp tape_alphabet.h

transition_function.o: transition_function.cpp transition_function.h
	g++ -g -c transition_function.cpp transition_function.h

transition.o: transition.cpp transition.h direction.h
	g++ -g -c transition.cpp transition.h direction.h

states.o: states.cpp states.h
	g++ -g -c states.cpp states.h

final_states.o: final_states.cpp final_states.h
	g++ -g -c final_states.cpp final_states.h

validate.o: validate.cpp validate.h
	g++ -g -c validate.cpp validate.h

uppercase.o: uppercase.cpp uppercase.h
	g++ -g -c uppercase.cpp uppercase.h

commands.o: commands.cpp commands.h
	g++ -g -c commands.cpp commands.h 
	
#tmapp.o: tmapp.cpp
#	g++ -g -c tmapp.cpp	

clean:
	rm *.o
	rm *.h.gch

immaculate:
	rm -f tmapp



