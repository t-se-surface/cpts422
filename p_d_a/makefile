#MakeFile for Turing Machine App
PROGNAME = pda_app
CPPFLAGS = -g

default: pda_app

pda_app: cpp_files/main.cpp commands.o push_down_automata.o input_alphabet.o transition_function.o transition.o states.o stack_alphabet.o final_states.o validate.o uppercase.o configuration_settings.o instantaneous_description.o
	g++ -g -o $@ cpp_files/main.cpp commands.o push_down_automata.o input_alphabet.o transition_function.o transition.o states.o stack_alphabet.o final_states.o validate.o uppercase.o configuration_settings.o instantaneous_description.o

push_down_automata.o: cpp_files/push_down_automata.cpp headers/push_down_automata.h
	g++ -g -c cpp_files/push_down_automata.cpp headers/push_down_automata.h

input_alphabet.o: file_parsers/cpp_files/input_alphabet.cpp file_parsers/headers/input_alphabet.h
	g++ -g -c file_parsers/cpp_files/input_alphabet.cpp file_parsers/headers/input_alphabet.h

transition_function.o: file_parsers/cpp_files/transition_function.cpp file_parsers/headers/transition_function.h
	g++ -g -c file_parsers/cpp_files/transition_function.cpp file_parsers/headers/transition_function.h

transition.o: file_parsers/cpp_files/transition.cpp file_parsers/headers/transition.h
	g++ -g -c file_parsers/cpp_files/transition.cpp file_parsers/headers/transition.h

states.o: file_parsers/cpp_files/states.cpp file_parsers/headers/states.h
	g++ -g -c file_parsers/cpp_files/states.cpp file_parsers/headers/states.h

stack_alphabet.o: file_parsers/cpp_files/stack_alphabet.cpp file_parsers/headers/stack_alphabet.h
	g++ -g -c file_parsers/cpp_files/stack_alphabet.cpp file_parsers/headers/stack_alphabet.h

final_states.o: file_parsers/cpp_files/final_states.cpp file_parsers/headers/final_states.h
	g++ -g -c file_parsers/cpp_files/final_states.cpp file_parsers/headers/final_states.h

validate.o: validation/cpp_files/validate.cpp validation/headers/validate.h
	g++ -g -c validation/cpp_files/validate.cpp validation/headers/validate.h

uppercase.o: validation/cpp_files/uppercase.cpp validation/headers/uppercase.h
	g++ -g -c validation/cpp_files/uppercase.cpp validation/headers/uppercase.h

commands.o: cpp_files/commands.cpp headers/commands.h
	g++ -g -c cpp_files/commands.cpp headers/commands.h

configuration_settings.o: cpp_files/configuration_settings.cpp headers/configuration_settings.h
	g++ -g -c cpp_files/configuration_settings.cpp headers/configuration_settings.h

instantaneous_description.o: cpp_files/instantaneous_description.cpp headers/instantaneous_description.h
	g++ -g -c cpp_files/instantaneous_description.cpp headers/instantaneous_description.h

clean:
	rm *.o
	rm headers/*.h.gch

immaculate:
	rm -f tmapp
