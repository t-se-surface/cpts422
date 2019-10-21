#MakeFile for Turing Machine App
PROGNAME = tmapp
CPPFLAGS = -g

default: tmapp

tmapp: cpp_files/main.cpp commands.o tape.o turing_machine.o input_alphabet.o tape_alphabet.o transition_function.o transition.o states.o final_states.o validate.o uppercase.o
	g++ -g -o $@ cpp_files/main.cpp commands.o turing_machine.o tape.o input_alphabet.o tape_alphabet.o transition_function.o transition.o states.o final_states.o validate.o uppercase.o

turing_machine.o: cpp_files/turing_machine.cpp headers/turing_machine.h
	g++ -g -c cpp_files/turing_machine.cpp headers/turing_machine.h

tape.o: cpp_files/tape.cpp headers/tape.h
	g++ -g -c cpp_files/tape.cpp headers/tape.h

input_alphabet.o: cpp_files/input_alphabet.cpp headers/input_alphabet.h
	g++ -g -c cpp_files/input_alphabet.cpp headers/input_alphabet.h

tape_alphabet.o: cpp_files/tape_alphabet.cpp headers/tape_alphabet.h
	g++ -g -c cpp_files/tape_alphabet.cpp headers/tape_alphabet.h

transition_function.o: cpp_files/transition_function.cpp headers/transition_function.h
	g++ -g -c cpp_files/transition_function.cpp headers/transition_function.h

transition.o: cpp_files/transition.cpp headers/transition.h headers/direction.h
	g++ -g -c cpp_files/transition.cpp headers/transition.h headers/direction.h

states.o: cpp_files/states.cpp headers/states.h
	g++ -g -c cpp_files/states.cpp headers/states.h

final_states.o: cpp_files/final_states.cpp headers/final_states.h
	g++ -g -c cpp_files/final_states.cpp headers/final_states.h

validate.o: cpp_files/validate.cpp headers/validate.h
	g++ -g -c cpp_files/validate.cpp headers/validate.h

uppercase.o: cpp_files/uppercase.cpp headers/uppercase.h
	g++ -g -c cpp_files/uppercase.cpp headers/uppercase.h

commands.o: cpp_files/commands.cpp headers/commands.h
	g++ -g -c cpp_files/commands.cpp headers/commands.h 

clean:
	rm *.o
	rm headers/*.h.gch

immaculate:
	rm -f tmapp