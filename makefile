StudentManagement: main.o Student.o Tokenizer.o Finders.o
	mkdir bin
	gcc -o bin/StudentManagement main.o Student.o Tokenizer.o Finders.o
	mv main.o Student.o Tokenizer.o Finders.o bin

main.o: src/main.c
	gcc -c src/main.c

Student.o: src/Student.c src/Student.h
	gcc -c src/Student.c

Tokenizer.o: src/Tokenizer.c src/Tokenizer.h
	gcc -c src/Tokenizer.c

Finders.o: src/Finders.c src/Finders.h
	gcc -c src/Finders.c

clean:
	rm bin/StudentManagement bin/Student.o bin/main.o bin/Tokenizer.o bin/Finders.o