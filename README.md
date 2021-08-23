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
## Good example on creating kernel threads. The rest can be ignored.
# NOTE thread priority has changed in newer kernels like current PI
# See https://lwn.net/Articles/818388/
dmesg --follow # In a separate terminal
cd /opt/git/thread
make
sudo insmod pix_mod.ko
sudo rmmod pix_mod.ko

### Timers in Module
## Currently called hello.c, should be renamed
cd /opt/git/RPDriver/timer
make
sudo insmod hello.ko
sudo rmmod hello.ko

### DM
## simple : http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
Simple module like others
## char : http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/
Character device that can be written and read from user space
Also has udev control for permissions
## charmutex : http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/
Same as character device but mutex protected
## led : http://derekmolloy.ie/kernel-gpio-programming-buttons-and-leds/
Led control using sysfs and run in a thread. Compiles by setting group access to none.
Not tested since this IO is for Beagle board NOT PI.
