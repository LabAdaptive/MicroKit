BIN    = bin
JFLAGS = -g -d $(BIN)
JC = javac

CLASSES = src/*.java 

default: bin classes

bin:
	mkdir -p bin 

classes: $(CLASSES)
	$(JC) $(JFLAGS) $(CLASSES)

clean:
	        $(RM) $(BIN)/*.class
