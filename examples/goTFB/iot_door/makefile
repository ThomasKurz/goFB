default: fbt/%.fbt c/%.c bin

fbt/%.fbt: tfb/%.tfb
	goTFB -i=tfb -o=fbt

c/%.c: fbt/%.fbt
	goFB -i=./fbt -o=./c -l=c -t=Top

bin: c/%.c
	gcc c/*.c -o iot_door.out

clean:
	rm -f iot_door.out
	rm -f fbt/*
	rm -f c/*