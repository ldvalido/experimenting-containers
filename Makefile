all: clean unroot.compile pivotroot.compile memory.compile namespace.compile

unroot.compile:
	gcc unroot.c -o unroot
pivotroot.compile:
	gcc pivot_root.c -o pivot_root
memory.compile:
namespace.compile:

clean:
	rm -f *.0
	rm -f unroot
	rm -f pivotroot