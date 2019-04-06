# CASE line follower robot 2019
Project repository for CASE hardware and software developement for attending the Swedish Robotic Championship 2019.
The robot got 3rd place in the Swedish Robotic Championship 2019.
![Diploma](https://i.imgur.com/QrNVJYN.jpg)

### Contributors
    -   Oskar Johansson
    -   Isak Åslund 
    -   Stefan Larsson

### Structure
    -   Software - All code for running the robot
    -   Hardware - PCB and hardware design

### Pictures
[Picture album](https://imgur.com/a/kjrejrC)

**V0.1**
![Initial Concept](https://i.imgur.com/QrNVJYN.jpg)

**V0.2**
![Working prototype](https://i.imgur.com/gPaBWxP.jpg)

**V1.0**
![Competition design](https://i.imgur.com/HKyBY4A.jpg)

**PCB**
Two PCBs was designed, one for arduino and one for STM32.
Due to battery being applied to the VB pin on the STM32 it burned up. 
This caused us to use an arduino nano with breadboard instead. 
Since then a updated PCB has been made.
![CASE STm32 PCB](https://i.imgur.com/Lj2sfSK.jpg)

### Pinout Help
https://components101.com/microcontrollers/arduino-nano

### Info for development
IDE - Visual Studio Code + PlattformIO
If you want to simplify development change the formatter for cpp to the following:
"{ BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}", more info [here](https://stackoverflow.com/questions/46111834/format-curly-braces-on-same-line-in-c-vscode)