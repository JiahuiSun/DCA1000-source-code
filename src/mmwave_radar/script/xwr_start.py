#!/usr/bin/env python3
import serial
import time
import sys


if __name__ == "__main__":
    serial_port_CLI = sys.argv[1]
    xwr_cfg = sys.argv[2]
    # wait for DCA first
    time.sleep(5)
    CLIport = serial.Serial(serial_port_CLI, 115200, timeout=1)
    if CLIport.is_open:
        config = [line.rstrip('\r\n') for line in open(xwr_cfg)]
        for i in config:
            if(i == '' or i[0] == '%'):
                continue
            CLIport.write((i+'\n').encode())
            time.sleep(0.01)
    else:
        raise Exception("Open serial port failed.")
    