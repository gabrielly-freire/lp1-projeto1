SOURCES = Main.cpp \
          util/util.cpp \
          dominio/Astronauta.cpp \
          dominio/Gerenciador.cpp \
          dominio/Voo.cpp

all: programa #alvo

programa: $(SOURCES)
	g++ $(SOURCES) -o programa

clean:
	rm -f programa
