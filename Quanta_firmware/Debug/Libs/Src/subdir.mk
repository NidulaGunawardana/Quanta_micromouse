################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libs/Src/L3GD20.c \
../Libs/Src/adc.c \
../Libs/Src/encoder.c \
../Libs/Src/led.c \
../Libs/Src/mainloop.c \
../Libs/Src/motor.c \
../Libs/Src/move.c \
../Libs/Src/sensors.c 

C_DEPS += \
./Libs/Src/L3GD20.d \
./Libs/Src/adc.d \
./Libs/Src/encoder.d \
./Libs/Src/led.d \
./Libs/Src/mainloop.d \
./Libs/Src/motor.d \
./Libs/Src/move.d \
./Libs/Src/sensors.d 

OBJS += \
./Libs/Src/L3GD20.o \
./Libs/Src/adc.o \
./Libs/Src/encoder.o \
./Libs/Src/led.o \
./Libs/Src/mainloop.o \
./Libs/Src/motor.o \
./Libs/Src/move.o \
./Libs/Src/sensors.o 


# Each subdirectory must supply rules for building sources it contributes
Libs/Src/%.o Libs/Src/%.su Libs/Src/%.cyclo: ../Libs/Src/%.c Libs/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/Libs/Inc" -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/algorithm/lnc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libs-2f-Src

clean-Libs-2f-Src:
	-$(RM) ./Libs/Src/L3GD20.cyclo ./Libs/Src/L3GD20.d ./Libs/Src/L3GD20.o ./Libs/Src/L3GD20.su ./Libs/Src/adc.cyclo ./Libs/Src/adc.d ./Libs/Src/adc.o ./Libs/Src/adc.su ./Libs/Src/encoder.cyclo ./Libs/Src/encoder.d ./Libs/Src/encoder.o ./Libs/Src/encoder.su ./Libs/Src/led.cyclo ./Libs/Src/led.d ./Libs/Src/led.o ./Libs/Src/led.su ./Libs/Src/mainloop.cyclo ./Libs/Src/mainloop.d ./Libs/Src/mainloop.o ./Libs/Src/mainloop.su ./Libs/Src/motor.cyclo ./Libs/Src/motor.d ./Libs/Src/motor.o ./Libs/Src/motor.su ./Libs/Src/move.cyclo ./Libs/Src/move.d ./Libs/Src/move.o ./Libs/Src/move.su ./Libs/Src/sensors.cyclo ./Libs/Src/sensors.d ./Libs/Src/sensors.o ./Libs/Src/sensors.su

.PHONY: clean-Libs-2f-Src

