This is intended to be a base package for developing USB-devices based on the
STM32F103.

* <code>dfu/</code> contains a DFU bootloader, customized for a certain kind of
  [board](/doc/board.jpg?raw=true).

* <code>firmware/</code> contains the firmware itself

* <code>host/</code> contains an example of the host software

* <code>common/constants.h</code> contains constants that are shared between the host and
  the device
