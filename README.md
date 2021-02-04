## RP2040
Baremetal Raspberry Pi Pico playground  

## Intro
This project aims to build a working Pi without any standard C library,  
In another word, let us do it from scratch.


## How to use this project
This project is intended to use with **Eclipse CDT**.  
You can also build the project without Eclipse CDT.  
  
### Setting up environment
```bash
# useful tools
sudo apt install git

# compiler
sudo apt install gcc-arm-none-eabi gcc gdb-multiarch automake autoconf build-essential
```

### Building and cleaning project
```bash
# build
make all

# clean
make clean
```