################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Disp/Src/display.c 

OBJS += \
./Disp/Src/display.o 

C_DEPS += \
./Disp/Src/display.d 


# Each subdirectory must supply rules for building sources it contributes
Disp/Src/%.o Disp/Src/%.su Disp/Src/%.cyclo: ../Disp/Src/%.c Disp/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/Libs/Inc" -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/Disp/Inc" -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/Drivers/SSD1306/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Disp-2f-Src

clean-Disp-2f-Src:
	-$(RM) ./Disp/Src/display.cyclo ./Disp/Src/display.d ./Disp/Src/display.o ./Disp/Src/display.su

.PHONY: clean-Disp-2f-Src

