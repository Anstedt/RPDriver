# RPDriver
Learn how to create Linux drivers on RP

### Setup RP for building Modules
sudo apt-get update
sudo apt-get upgrade
sudo rpi-update
sudo apt install raspberrypi-kernel-headers git bc bison flex libssl-dev make

### Simple Module
dmesg --follow # In a separate terminal
cd /opt/git/RPDriver/simple_mod
make
sudo insmod hello.ko
sudo rmmod hello.ko

### Threads in Module
dmesg --follow # In a separate terminal
cd /opt/git/thread
make
sudo insmod pix_mod.ko
sudo rmmod pix_mod.ko
