CXX = $(shell [ `g++ -v 2>&1 | grep -o 'version [0-9]\+' | cut -d' ' -f2` -le 9 ] && echo g++-10 || echo g++)
CXXFLAGS += -std='c++20' -Wall -Wextra -Wsign-compare -fmax-errors=2 -pedantic

# Sur Mac, supprimer la ligne suivante
CXXFLAGS += -Walloc-zero -Wctor-dtor-privacy -Wdeprecated-copy-dtor -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wformat-signedness -Winit-self -Wlogical-op -Wnon-virtual-dtor -Wnull-dereference -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wstrict-null-sentinel -Wsuggest-attribute=const -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wuseless-cast -Wvolatile -Wzero-as-null-pointer-constant -fmax-errors=2 -Wformat=2 -fsanitize=undefined,address,leak
LDLIBS   += -lfltk -lfltk_images -ljpeg

SOURCES = $(wildcard *.cpp View/*.cpp Model/*.cpp Controller/*.cpp tooling/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, ${SOURCES})

.PHONY: default
default: main

main: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LDFLAGS} $^ -o $@ ${LOADLIBES} ${LDLIBS}

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
.PHONY: clean
clean:
	-rm *.o && rm Model/*.o && rm View/*.o && rm Controller/*.o && rm tooling/*.o
.PHONY: mrclean
mrclean: clean
	-rm ${BINS}
