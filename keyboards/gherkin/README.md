make
mv ../../.build/gherkin_paulLayout.hex .
ls /dev/tty* | grep ACM0
sudo avrdude -p atmega32u4 -P /dev/ttyACM0  -c avr109  -U flash:w:gherkin_paulLayout.hex


------
About
------

First pass at adding support for the gherkin keyboard. Compiles but completely
untested. Intended to kick-start development.

* [Gherkin project on 40% Keyboards](http://www.40percent.club/2016/11/gherkin.html)
* [The original TMK firmware](https://github.com/di0ib/tmk_keyboard/tree/master/keyboard/gherkin)

Credit to JadedC for the initial work.

