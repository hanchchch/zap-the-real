CFLAGS += -w

all: zap

zap: src/main.o \
	src/include/zap_tmp.o \
	src/include/zap_lastlog.o \
	src/include/latest.o \
	src/include/utmp_ll/search.o \
	src/include/utmp_ll/types.o \
	src/include/utmp_ll/utils/option.o \
	src/include/utmp_ll/utils/file.o \
	src/include/utmp_ll/utils/time.o
	cc $^ -o $@

clean:
	rm -f zap *.o src/*.o src/include/*.o src/include/utmp_ll/*.o src/include/utmp_ll/utils/*.o
