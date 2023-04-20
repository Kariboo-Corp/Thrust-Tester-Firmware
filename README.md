# Thrust Tester Firmware

## Purpose of this firmware
This firmware is intended to be used with the [Thrust Tester Board](https://github.com/aiRCS-Lab/Thrust-Tester-Hardware). It allows you to control the ESC (external) through a potentiometer (or an analogic signal between 0V and 5V, respectively 0% and 100% thrust). It reads and averages value from the load cell no. 1 (for now ...). These values are displayed on an I2C LCD screen and send through USB (serial converter) to a PC. This let us use some serial ploter in order to have some nice live graphs about what is going on.

## Contribute & Use
This firmware is open source. It's using the well known PlatformIO style. You will need to download and install it on your VS Code in order to compile the firmware and upload it flawlessly. 

With the default configuration inside the `platformio.ini` file you will need an Atmel Ice to flash the firmware. 


_If your ATmega328PB is brand new you need to first flash the firmware with an Atmel Ice or any other ISP programmer. For next update, you could use the USB port on the board to flash newer firmware thanks to Arduino bootloader._

## Calibration
Calibration values given in the code are related to our test setup and might not work with your load cells. Then, you need to calibrate your own load cells and you own board (resistors tolerance, etc.). Each HX711 needs to be calibrated with it load cell. You **CAN'T** swap cells, or reuse it or the calibration will be gone.

1. Call set_scale() with no parameter.
2. Call tare() with no parameter.
3. Place a known weight on the scale and call get_units(10).
4. Divide the result in step 3 to your known weight. You should get about the parameter you need to pass to set_scale().
5. Adjust the parameter in step 4 until you get an accurate reading.

Currently, you will need to write your own sketch to calibrate your load cells.

## TODO
 - Fully remote control trough USB
 - Calibration trough USB