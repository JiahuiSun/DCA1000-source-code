#!/usr/bin/env python3
import serial
import time
import sys


if __name__ == "__main__":
    serial_port_CLI = sys.argv[1]
    CLIport = serial.Serial(serial_port_CLI, 115200, timeout=1)
    if CLIport.is_open:
        CLIport.write(('sensorStop'+'\n').encode())
        time.sleep(0.01)
    else:
        raise Exception("Open serial port failed.")
    