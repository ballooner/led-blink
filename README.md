# What it does
This is a simple program that will blink an LED on/off 5 times with a 1 second delay using the libgpiod library.

# How to run
Run: 
```console
gcc main.c -o main -lgpiod
sudo ./main
```

# Required Hardware
* 1 Raspberry Pi 5
* 1 Breadboard
* 1 LED light of any color
* 2 MtF Jumper Wires
* 1 100 Ohm Resistor

# Hardware Setup
1. Connect Male side of dupont wire to GPIO pin 9 (ground) and Female side to breadboard
2. Connect Male side of dupont wire to GPIO pin 11 (GPIO 17) and Female side to breadboard
3. Connect 100 Ohm Resistor to breadboard
4. Link LED Anode to resistor and Cathode to somewhere it can connect to the ground connector

# Software Setup
Download [libgpiod](https://libgpiod.readthedocs.io/en/latest/building.html) and follow the installation guide

# Expected Behavior
Blink LED on/off 5 times with a 1 second delay
