#!/bin/sh
arduino-cli upload -p /dev/ttyTarget -i ./wfh_monitor.ino.Seeeduino.samd.seeed_wio_terminal.bin -b Seeeduino:samd:seeed_wio_terminal --verbose --log-level trace --additional-urls https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json