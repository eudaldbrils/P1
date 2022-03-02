LDLIBS += -lm

p1: p1.o pav_analysis.o fic_wave.o
	gcc -o p1 p1.o pav_analysis.o fic_wave.o $(LDLIBS)

p1.o: p1.c pav_analysis.h fic_wave.h
	gcc -c p1.c

pav_analysis.o: pav_analysis.c pav_analysis.h
	gcc -c pav_analysis.c

fic_wave.o: fic_wave.c fic_wave.h
	gcc -c fic_wave.c