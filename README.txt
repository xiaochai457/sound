# ------------------------- Sound Level Sensor-------------------------------
Sound level meter project made by hu jinrong, Feb.2018.

This prject uses a Raspberry PI 3 Mode B as a sound sensor. A usb sound card
with microphone and a RJ45 cable are needed as peripheral. The application runs
periodically every second and take record from microphone at a sple rate of 
16000Hz. The sound is then calculated into 80 pieces of RMS value and displayed 
as a bar chart on terminal screen. If communication is enable (conditional 
compilation), the sound will be re-calculated into 8 pieces of Faslevel data
and sent out to a PHP sever program.

List of Contents
1. Configuration intructions
2. Installation instructions
3. Operating instructions
4. File  manifest
5. copyright and license
6. Contact information

1.configuration intructions
hardware:
Raspberry PI mode b, a sd card,a usb sound card,
microphone and a RJ45 cable
software:
putty

2.installation intructions
First use the RJ45 cable connect to Respberry PI and a usb cable to the power. 
Then insert you SD card to the Respberry and installate sound card and microphone.


3.operating instructions
operating system:windows 10
how to operate:
opening the putty with the ip you get from the email.
useing comment "make" and run "./sound.a"

4.File manifest
comm.c  comm.h  main.c  makefile  project.tar  README.md  README.txt  screen.c
screen.h sound.c sound.h test.wav

5.copyright and license
Copyright (C) <2018>  <Hujinrong>
    
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
                    
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
                                    
You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

6.Contact information
Hujinrong
Dept. of Information technolog
Vaasa University of Alied Sciences
Vuorikatu 14-18 B29, 65100, Vaasa, Finland
page: www.cc.puv.fi/~e1700695
email:1529004324@qq.com
	  e1700695@edu.vamk.fi
 
