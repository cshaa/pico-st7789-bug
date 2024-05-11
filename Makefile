CFLAGS:="-DPICO_BOARD=pico $(CFLAGS)"

.PHONY: clean build

clean:
	@rm -rf build

build:
	@mkdir -p build
	@cd build; cmake .. $(CFLAGS)
	@cd build; make main

flash:
	@picotool load -f build/main.uf2
