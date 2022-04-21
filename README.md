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
  - esp8266 package

  In order to install the esp8266 package, you'll need to:

  - Start Arduino IDE and open the Preferences window.
  - Enter https://arduino.esp8266.com/stable/package_esp8266com_index.json into the File>Preferences>Additional Boards Manager URLs field of the Arduino IDE. You can add multiple URLs, separating them with commas.
  - Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).

Connect your board to a USB port on your computer. In Arduino IDE, go to "Tools" and then click on "Ports". You should see a COM*X* (where X is a number) letting you know your board is being recognized by your computer.

### Resolving Library Dependencies

After downloading this repository to your computer, you'll need to open it in Arduino IDE by going to File -> Open and then searching for the folder where you downloaded this project. The first few lines in the code are some comments and then some libraries that this project relies on. These libraries are:

- MD_Parola
- MD_MAX72xx
- JsonStreamingParser
- ArduinoJson
- InstagramStats

Don't worry about downloading the libraries, they have been included in this project and you can find them inside the "Libraries" folder. You will, however, need to add each of them individually to Arduino IDE by going to Sketch -> Include Library -> Add .ZIP Library

Now, press the cyan Checkmark icon in the top-left corner of Arduino IDE, this button is called "Verify". The code should compile with no errors. If it doesn't, make sure you added all the libraries mentioned above.

## Setting up the program

In order to get accurate results, we'll need some information:

- Facebook and Instagram Access Tokens and User IDs
- Wifi settings

You will need to change the fields *INSTAGRAM_ACCESS_TOKEN*,  *IG_USER_ID*, *FACEBOOK_ACCESS_TOKEN*, *FB_USER_ID* with information gathered from Facebook's Graph API. How to get such information is out of scope for this guide, but you can watch [this video](https://www.youtube.com/watch?v=9UCyRyJyZAo&t=0s) to learn how to do that.

You'll also need to edit the fields *ssid* and *password* with the corresponding Wi-Fi Network name and password you wish to use.

## Verifying and compiling

Now, verify your code is working by clicking on the "Verify" button and upload your code to the board if it compiles correctly. You can upload the code by clicking on the right arrow right next to the Verify button.

That's it! In just a few seconds, your display should show you the accurate number of Instagram followers and Facebook Likes your pages currently have. If all you see is a "0" next to each icon, make sure you have correctly set up the User IDs and Access Tokens.



  