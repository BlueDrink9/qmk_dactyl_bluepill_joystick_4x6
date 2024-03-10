# Build Options
#   change yes to no to disable
JOYSTICK_DRIVER=analog
POINTING_DEVICE_DRIVER=analog_joystick
SERIAL_DRIVER = usart
DEFERRED_EXEC_ENABLE = yes
SRC += features/breathing/breathing.c
SRC += features/layer_lock.c
