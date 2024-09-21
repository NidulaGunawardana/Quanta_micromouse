################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/src/SerialPrint.c \
../libs/src/mainloop.c \
../libs/src/motor_speed.c 

OBJS += \
./libs/src/SerialPrint.o \
./libs/src/mainloop.o \
./libs/src/motor_speed.o 

C_DEPS += \
./libs/src/SerialPrint.d \
./libs/src/mainloop.d \
./libs/src/motor_speed.d 


# Each subdirectory must supply rules for building sources it contributes
libs/src/%.o libs/src/%.su libs/src/%.cyclo: ../libs/src/%.c libs/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L073xx -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/nadil/Desktop/Quanta_micromouse/motor_speed_controller/libs/lic" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-libs-2f-src

clean-libs-2f-src:
	-$(RM) ./libs/src/SerialPrint.cyclo ./libs/src/SerialPrint.d ./libs/src/SerialPrint.o ./libs/src/SerialPrint.su ./libs/src/mainloop.cyclo ./libs/src/mainloop.d ./libs/src/mainloop.o ./libs/src/mainloop.su ./libs/src/motor_speed.cyclo ./libs/src/motor_speed.d ./libs/src/motor_speed.o ./libs/src/motor_speed.su

.PHONY: clean-libs-2f-src

