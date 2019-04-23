positionscoring: dict.o positionscoring.o
	g++ -o $@ $^

%.o: %.cpp
	g++ -c -o $@ $^


clean:
	rm -f *.o
	rm -vf positionscoring *.o *~