# CS:GO Bomb Trigger

CS:GO Bomb Trigger will inform a perephiral connected to your computer via the serial port that the bomb has been planted.

## Features

 - Based on the Game State Integration features of CS:GO
 - Created with Qt to provide a GUI
 - Minimizable and auto-connect with cmd options

## GUI preview

![gui](http://i.imgur.com/oalXG9S.png)

## Notes

 - The whole project is based on [Crow](https://github.com/ipkn/crow/), an open source library that allows the program to handle JSON request.
 - The CS:GO process will communicate by default on the port 30080 with the program.
 - Serial port specifications :
    - baudrate : 9600 bauds
    - 8-data bits
    - no parity bit
 - When the bomb has been planted, the character 'a' will be sent to the peripheral.
 - When the round has ended, the character 'b' will be sent to the peripheral.
 - All theses parameters can be change in the file "configuration.h" (need a rebuild).
 - The executable given has been built for x86 machine.

## Command-Line Options

```
-p port  : Connect to the <port> at the start of the application if it's possible
-h       : Hide the window
```

