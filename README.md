# CS:GO Bomb Trigger

CS:GO Bomb Trigger will inform a perephiral connected to your computer via the serial port that the bomb has been planted.
Perfect to link an Arduino with a display to inform the player about the bomb time left.

## Features

 - Based on the Game State Integration features of CS:GO
 - Created with Qt to provide a GUI
 - Minimizable and auto-connect with cmd options

## Install

1. Download "bomb_trigger_v1.exe" and "gamestate_integration_bt.cfg".
2. Put "gamestate_integration_bt.cfg" in Steam\steamapps\common\Counter-Strike Global Offensive\csgo\cfg.
3. Install and enjoy by launching "bomb_trigger.exe".

## GUI preview

![gui](http://i.imgur.com/oalXG9S.png)

## Notes

 - The whole project is based on [Crow](https://github.com/ipkn/crow/), an open source library that allows the program to handle JSON request.
 - The CS:GO process will communicate by default on the port 30080 with the program.
 - Serial port specifications :
    - 9600 bauds
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

**Example :** I want to launch the program at the start of my comptuter discreetly and connect to the COM3
 - Put a shortcut of the program in %ProgramData%\Microsoft\Windows\Start Menu\Programs\Startup
 - Give it theses Command-Line Options : -p COM3 -h

## Bibliography

- [Icon used](http://www.flaticon.com/free-icon/bomb-warning_16562)
- [Game State Integration documentation](https://developer.valvesoftware.com/wiki/Counter-Strike:_Global_Offensive_Game_State_Integration)
