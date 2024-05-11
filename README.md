# Raspberry Pi Pico – Demo Project

Blinks the built-in LED and print "Hello World (elapsed time)" to the USB tty.

```sh
make build
# or
make build CFLAGS="-DPICO_W=ON" # for Pico W
make build CFLAGS="-DPICO_W=OFF" # for Pico
# then
make flash
```

