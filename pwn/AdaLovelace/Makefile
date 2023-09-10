CC:=clang
CFLAGS:=-Oz -g -mno-sse

BUILD=./build

all: clean release

release: ${BUILD}/punchcard.tar.xz

${BUILD}/mainframe: src/main.c ${BUILD}
	${CC} -o $@ ${CFLAGS} $<

${BUILD}:
	mkdir -p $@

${BUILD}/punchcard.py ${BUILD}/blank_card.txt: src/punchcard.py tests/blank_card.txt
	cp $? ${BUILD}

${BUILD}/punchcard.tar.xz: ${BUILD}/mainframe ${BUILD}/punchcard.py ${BUILD}/blank_card.txt
	tar -C ${BUILD} -cJvf $@ $(notdir $?)


clean:
	rm -rf ${BUILD}

.PHONY: all clean release
