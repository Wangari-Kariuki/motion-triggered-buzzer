## Motion triggered buzzer tutorial

This is a quick guide for creating a motion-triggered alarm system using the ESP32 S3 starter kit, a buzzer, and an ultrasonic ranging module. This project demonstrates fundamental knowledge of sensor-driven event detection and response systems, which can be applied in various contexts, such as:
- Alarm systems in commercial buildings
- Parking assistance systems
- Intruder or security alarms

These systems trigger alerts, cameras, or notifications based on motion or distance changes. 

Hardware Component list:

<table>
  <tr>
    <td align="center"><strong>ESP32-S3 WROOM</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/esp32.PNG" alt = "esp32" width="200" height="150"></td>
    <td align="center"><strong>GPIO Extension board</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/GPIO_extentions_board.PNG" alt = "GPIO board" width="200" height="150"></td>
    <td align="center"><strong>Active buzzer</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/buzzer.PNG" alt = "buzzer" width="200" height="150"></td>
  </tr>
  <tr>
    <td align="center"><strong>Ultrasonic ranging module</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/ranging_module.PNG" alt = "ranging module" width="200" height="150"></td>
    <td align="center"><strong>Jumper wires x6</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/wires.PNG" alt = "wires" width="200" height="150"></td>
    <td align="center"><strong>USB Cable</strong><br><img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/Cable.PNG" alt = "usb cable" width="200" height="150"></td>
  </tr>
</table>

## Component knowledge

**How the buzzer works and the difference between active and passive buzzer.**


Active buzzers generate sound by producing their own frequency when triggered. They contain an internal oscillator circuit and sound-generation electronics, so when power is applied, the buzzer makes a sound. 
Passive buzzers, on the other hand, require external frequency generation. They do not have internal oscillators, so the ESP32 must create the oscillating signal, usually through software using PWM.<a href= "https://docs.freenove.com/projects/fnk0084/en/latest/fnk0084/codes/C/7_Buzzer.html"> More information about this on this tutorial page </a>


**How the ultrasonic ranging module works**



The ranging module operates on the principle that sound travels through air and is reflected when it encounters an obstacle. 

The sensor emits an ultrasonic pulse and then waits for the echo. It measures the time interval between the emission of the ultrasonic wave and the reception of its reflection. This period ends when the wave is received back after being reflected, and the time difference (delta) is recorded. 

Since the speed of sound in air is constant, we can calculate the distance between the module and the obstacles using the formula: s = vt/2, where 's' represents distance, 'v' is the speed of sound, and 't' is the recorded time.
<a href = "https://docs.freenove.com/projects/fnk0034/en/latest/fnk0034/codes/tutorial/24_Ultrasonic_Ranging.html#chapter-ultrasonic-ranging">More details in this tutorial </a>

Link to raw source code file <a href = "https://github.com/Wangari-Kariuki/motion-triggered-buzzer/blob/main/Final_projectMovementAlarm.ino">github Link</a>>

**Circuit**

The connection of the ranging module(HC-SR04)  and the buzzer is shown below.


<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/circuit.png" width="600">


**Sketch and Code**

Download and extract content of FNK0034;  Freenove_RFID_Starter_Kit_v2.0 folder provided in <a href = "https://docs.freenove.com/en/latest/about-freenove/tutorial.html"> this freenove tutorial page</a>

Upload the ultrasonic_ranging.ino sketch from the folder to the Arduino IDE.

Define max distance

<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/snip1.PNG" width="600">



Initialize  new distance, set distance  ddistance, and track

<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/snip3.PNG" width="600">


Set up the PIN_BUZZER to output mode 
Change the serial port to begin at port 115200

<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/snip2.PNG" width="600">


Create a condition to determine the distance threshold as (SET_DISTANCE)

<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/snip4.PNG" width="600">


Add trigger conditions to set the buzzer on or off depending on the variation between new distance and set distance.

<img src = "https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/snip5.PNG" width="600">



Check the code and execute it; the buzzer beeps when an object passes in front of the sensor.

### Video demo of the working device
<video width="400" controls>
  <source src="https://raw.githubusercontent.com/Wangari-Kariuki/motion-triggered-buzzer/main/Assets/IMG_6610.mp4" type="video/mp4">
</video>
