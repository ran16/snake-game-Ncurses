compiler = clang++ -Wall

all: bin/main.out

bin/main.out: bin/main.o bin/records.o bin/player.o bin/game.o bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/fruit_speed.o bin/fruit_doublePoints.o
	${compiler} $^ -lncurses -o bin/main.out

bin/main.o: src/main.cpp
	${compiler} $^ -c -o bin/main.o

bin/records.o: src/records.h src/records.cpp
	${compiler} src/records.cpp -c -o bin/records.o

bin/player.o: src/player.h src/player.cpp
	${compiler} src/player.cpp -c -o bin/player.o

bin/game.o: src/game.h src/game.cpp
	${compiler} src/game.cpp -c -o bin/game.o

bin/position.o: src/position.h src/position.cpp
	${compiler} src/position.cpp -c -o bin/position.o

bin/snake.o:  src/snake.h src/snake.cpp
	${compiler} src/snake.cpp -c -o bin/snake.o

bin/fruit.o: src/fruit.h src/fruit.cpp
	${compiler} src/fruit.cpp -c -o bin/fruit.o

bin/fruit_plus.o: src/fruit_plus.h src/fruit_plus.cpp
	${compiler} src/fruit_plus.cpp -c -o bin/fruit_plus.o

bin/fruit_speed.o: src/fruit_speed.h src/fruit_speed.cpp
	${compiler} src/fruit_speed.cpp -c -o bin/fruit_speed.o

bin/fruit_doublePoints.o: src/fruit_doublePoints.h src/fruit_doublePoints.cpp
	${compiler} src/fruit_doublePoints.cpp -c -o bin/fruit_doublePoints.o

bin/snakeTester.out: bin/records.o bin/player.o bin/game.o bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/fruit_speed.o bin/fruit_doublePoints.o src/snakeTester.cpp
	${compiler} $^ -lncurses -o bin/snakeTester.out


bin/gameTester.out: src/gameTester.cpp bin/game.o bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/player.o bin/fruit_speed.o bin/fruit_doublePoints.o
	${compiler} $^ -lncurses -o bin/gameTester.out

bin/gameTester2.out: src/gameTester2.cpp bin/game.o bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/player.o bin/fruit_speed.o bin/fruit_doublePoints.o
	${compiler} $^ -lncurses -o bin/gameTester2.out

bin/fruit_plusTester.out: src/fruit_plusTester.cpp bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/player.o
	${compiler} $^ -lncurses -o bin/fruit_plusTester.out

bin/fruit_speedTester.out: src/fruit_speedTester.cpp bin/position.o bin/snake.o bin/fruit.o bin/fruit_speed.o bin/player.o
		${compiler} $^ -lncurses -o bin/fruit_speedTester.out

bin/fruit_doublePointsTester.out: src/fruit_doublePointsTester.cpp bin/position.o bin/snake.o bin/fruit.o bin/fruit_doublePoints.o bin/player.o
	${compiler} $^ -lncurses -o bin/fruit_doublePointsTester.out

bin/mainTester.out: src/mainTester.cpp bin/records.o bin/player.o bin/game.o bin/position.o bin/snake.o bin/fruit.o bin/fruit_plus.o bin/fruit_speed.o bin/fruit_doublePoints.o
	${compiler} $^ -lncurses -o bin/mainTester.out

bin/positionTester.out: src/positionTester.cpp bin/position.o
	${compiler} $^ -o bin/positionTester.out

bin/playerTester.out: src/playerTester.cpp bin/player.o
	${compiler} $^ -o bin/playerTester.out

bin/recordsTester.out: src/recordsTester.cpp bin/records.o bin/fruit.o bin/position.o bin/snake.o bin/player.o
	${compiler} $^ -o bin/recordsTester.out -lncurses



tests: bin/snakeTester.out bin/fruit_plusTester.out bin/fruit_speedTester.out bin/fruit_doublePointsTester.out bin/gameTester.out bin/gameTester2.out  bin/positionTester.out bin/playerTester.out bin/mainTester.out bin/recordsTester.out
	bin/snakeTester.out < tests/snakeInput.txt | diff - tests/snakeOutput.txt
	bin/fruit_plusTester.out
	bin/fruit_speedTester.out
	bin/fruit_doublePointsTester.out
	bin/gameTester.out < tests/gameInput.txt
	bin/gameTester2.out < tests/gameInput2.txt
	>records/names.txt
	>records/scores.txt
	>records/number_of_records.txt
	bin/mainTester.out < tests/mainInput.txt | diff - tests/mainOutput.txt
	bin/mainTester.out < tests/mainInput2.txt | diff - tests/mainOutput2.txt
	bin/mainTester.out < tests/mainInput3.txt | diff - tests/mainOutput3.txt
	bin/mainTester.out < tests/mainInput4.txt | diff - tests/mainOutput4.txt
	bin/mainTester.out < tests/mainInput5.txt | diff - tests/mainOutput5.txt
	bin/positionTester.out
	bin/playerTester.out
	>records/names.txt
	>records/scores.txt
	>records/number_of_records.txt
	bin/recordsTester.out < tests/recordsInput.txt | diff - tests/recordsOutput.txt


clean:
	rm -f ./bin/*.out
