CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -Werror=vla
EXEC = biquadris
OBJECTS = main.o gamestate.o commandlist.o command.o clockwisecmd.o downcmd.o leftcmd.o rightcmd.o counterclockwisecmd.o dropcmd.o levelup.o leveldown.o norandom.o random.o sequence.o icmd.o jcmd.o lcmd.o tcmd.o scmd.o zcmd.o ocmd.o restart.o sacommand.o heavy.o force.o blind.o board.o block.o tile.o level.o level0.o level1.o level2.o level3.o level4.o observer.o effect.o heavyeffect.o blindeffect.o forceeffect.o centredropeffect.o graphicsobserver.o playerwindow.o stats.o boardobserver.o currentblock.o immobiletiles.o nextblock.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} 

-include ${DEPENDS}

.PHONY: clean
	
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
