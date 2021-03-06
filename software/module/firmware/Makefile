PROJECT_NAME = $(shell basename "$(realpath ./)")

#List all of the application source files that need to be compiled
#############################################
APPLICATION_SRCS = $(notdir $(wildcard ./*.c))
APPLICATION_SRCS += led.c
APPLICATION_SRCS += timer.c
APPLICATION_SRCS += prng.c
APPLICATION_SRCS += delay.c
APPLICATION_SRCS += SEGGER_RTT.c

APPLICATION_SRCS += stm32f0xx_gpio.c
APPLICATION_SRCS += stm32f0xx_rcc.c
APPLICATION_SRCS += stm32f0xx_i2c.c
APPLICATION_SRCS += stm32f0xx_dma.c
APPLICATION_SRCS += stm32f0xx_misc.c
APPLICATION_SRCS += stm32f0xx_tim.c
APPLICATION_SRCS += stm32f0xx_spi.c
APPLICATION_SRCS += stm32f0xx_pwr.c
APPLICATION_SRCS += stm32f0xx_exti.c
APPLICATION_SRCS += stm32f0xx_syscfg.c
APPLICATION_SRCS += stm32f0xx_usart.c

APPLICATION_SRCS += stm32f0xx_i2c_cpal.c
APPLICATION_SRCS += stm32f0xx_i2c_cpal_hal.c

APPLICATION_SRCS += deca_device.c
APPLICATION_SRCS += deca_params_init.c

LDFLAGS += -lm

#The exact STM part number All CAPS
############################################
#DEVICE ?= STM32F031G6
DEVICE ?= STM32F091CC

ifeq ($(DEVICE), STM32F031G6)
DEVICE_FAMILY ?= STM32F031
CFLAGS += -DBOARD_V=1
endif
ifeq ($(DEVICE), STM32F091CC)
DEVICE_FAMILY ?= STM32F091
CFLAGS += -DBOARD_V=2
endif

## HACK FOR stm32f031
## Need to define this so that CPAL will compile.
## It is never used, however.
ifeq ($(DEVICE_FAMILY), STM32F031)
CFLAGS += -DI2C2_IRQn=24
endif

# Adjust clock speed of HSE (High-Speed external oscillator)
ifeq ($(DEVICE_FAMILY), STM32F091)
# Use 16 MHz external oscillator
HSE_CLK_FREQ = 16000000
CFLAGS += -DHSE_VALUE=$(HSE_CLK_FREQ)
endif

# Allow to circumvent BLE interface
ifneq ($(BYPASS_HOST_INTERFACE), )
CFLAGS += -DBYPASS_HOST_INTERFACE
endif
ifneq ($(RANGE_TEST), )
CFLAGS += -DRANGE_TEST
endif
ifneq ($(CALIBRATION), )
CFLAGS += -DCALIBRATION
endif

# Add empty variable to add flags over command line
CDBG +=
CFLAGS += $(CDBG)

CFLAGS += -Wall -Wextra

# Automatically add debugging symbols (no effect due to the -s option later on in ../stm32f0-base/stm32f0xx-gcc-setup/template/Makefile)
#CFLAGS += -g

#The install locations of the STM Standard library
#################################################
LIBRARY_START_PATH ?= ../stm32f0-base/sdk/stm32f0xx-1.5.0/

#The location of the gcc setup template
################################################
TEMPLATE_PATH ?= ../stm32f0-base/stm32f0xx-gcc-setup/template/

#Any places that you put custom header files
###############################################
LIBRARY_PATHS += ../include ../dw1000-driver

#Any places that you put custom source files
##############################################
SOURCE_PATHS += ../source ../dw1000-driver

ifndef LIBRARY_START_PATH
$(error An LIBRARY_START_PATH must be defined. Edit Makefile to define a valid LIBRARY_PATH)
endif

ifneq ($(PID), )
ID = c0:98:e5:42:00:$(PID)
endif

# Set an ID for programming the nodes EUI
ifeq ($(ID), )
ID = c0:98:e5:42:00:FF
endif


# This creates a .bin file for loading the calibration values into the flash of the module.
USER_FLASH_COMMANDS = $(shell ./insert_calibration.py $(ID))

# Compiler flags
# Optimize for debugging (results in too large file size)
#CFLAGS += -Og
# Optimize for size
CFLAGS += -Os
# Set correct port for GDB server
GDB_PORT_NUMBER = 2331

include $(TEMPLATE_PATH)Makefile
