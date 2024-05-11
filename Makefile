.PHONY: clean build

clean:
	@rm -rf build

build:
	@mkdir -p build
	@cd build; cmake ..
	@cd build; make main
