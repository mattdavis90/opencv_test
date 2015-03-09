APPS := extract stitch track
LIBS := $(shell pkg-config --libs --cflags opencv)

SRCS := $(addsuffix .cpp, $(addprefix src/,$(APPS)))
BINS := $(addprefix bin/,$(APPS))

.phony: all $(BINS) clean

all: $(BINS)
	@echo All done

$(APPS): %: bin/%

$(BINS): bin/%: src/%.cpp
	@echo Building $@
	@g++ -o $@ $< $(LIBS)
	@echo Finished building $@

clean:
	@echo Cleaning...
	@rm -f bin/*
	@echo All clean

