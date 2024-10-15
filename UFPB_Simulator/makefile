all: success.txt src.zip map.png

C = objetos.c misc.c substantivo.c locais.c movimento.c inventory.c parsexec.c tutorial.c survive.c main.c
H = objetos.h misc.h substantivo.h locais.h movimento.h inventory.h parsexec.h tutorial.h survive.h

success.txt: UFPB_Simulator.exe testscript.txt baseline.txt
	./test.sh
	mv -f transcript.txt $@
UFPB_Simulator: $(C) $(H)
	gcc -Wall -Wextra -Wpedantic -Werror $(C) -o $@
objetos.h: objetos.awk objetos.txt
	awk -v pass=h -f objetos.awk objetos.txt > $@
objetos.c: objetos.awk objetos.txt
	awk -v pass=c1 -f objetos.awk objetos.txt > $@
	awk -v pass=c2 -f objetos.awk objetos.txt >> $@
map.png: map.gv
	dot -Tpng -o $@ $<
map.gv: map.awk objetos.txt
	awk -f map.awk objetos.txt > $@
src.zip: $(C) $(H) objetos.txt makefile testscript.txt baseline.txt
	zip -rq $@ $^
clean:
	$(RM) objetos.c objetos.h UFPB_Simulator map.gv map.png transcript.txt success.txt src.zip
