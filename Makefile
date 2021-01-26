flags := -std=c11 -Wall -Wextra -Werror -Wpedantic -I resorce/include -L resource/lib -l SDL2 -I resorce/include -L resource/lib -l SDL2_ttf -I resorce/include -L resource/lib -l SDL2_image -I resource/include -L resource/lib -l SDL2_mixer 
name := endgame

all: MK_OBJ

MK_OBJ: 
	clang $(flags) src/*.c -o $(name)

clean: 
	rm -f $(name)

uninstall:
	rm -f  $(name)

reinstall:
	make uninstall
	make
