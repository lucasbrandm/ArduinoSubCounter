# ArduinoSubCounter

## Description
This project is based on TheSwedishMaker's "This is The 20$ Subscriber Counter - Youtube & Instagram" project with some modifications to update Instagram's API calls and replace Youtube's integration with Facebook instead.

The objective of this project is to create a display that integrates Arduino with some API calls that shows how many Followers and Likes a certain user has on Instagram and Facebook. In this readme file, we'll go over the basic setup too get things working and how to make changes in order to adjust for a different user.

## Requirements

You'll need:
 - Wemos' D1 or D1 Mini Arduino Board
 - DOT Matrix 7219 Display
 - Wires
 - Plastic casing (optional)
 - Drivers for the board
 - Python
 - Arduino IDE
 - Libraries (included)

## Setup

### Connecting the Wires
Here is a simple diagram showing how to connect the wires. The items on the left correspond to connections in the display and the ones on the right are on the Arduino board.

- VCC -> 3V3
- GND -> GND
- DIN -> D8
- CS  -> D7
- CLK -> D6

### Downloading stuff
 You'll then need to install the drivers for the board, Python and the Arduino IDE. You'll also need to install the package for this specific board. You can find all of that in the links below:

  - [Drivers](https://www.wemos.cc/en/latest/ch340_driver.html)
  - [Python](https://www.python.org/downloads/)
  - [Arduino IDE](https://www.arduino.cc/en/software)
  - [esp8266 package](https://github.com/esp8266/Arduino)

  In order to install the esp8266 package, you'll need to:

  - Start Arduino IDE and open the Preferences window.
  - Enter https://arduino.esp8266.com/stable/package_esp8266com_index.json into the File>Preferences>Additional Boards Manager URLs field of the Arduino IDE. You can add multiple URLs, separating them with commas.
  - Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).




  