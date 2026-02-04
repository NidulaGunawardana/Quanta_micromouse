################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../algorithm/Src/minimaze.cpp 

OBJS += \
./algorithm/Src/minimaze.o 

CPP_DEPS += \
./algorithm/Src/minimaze.d 


# Each subdirectory must supply rules for building sources it contributes
algorithm/Src/%.o algorithm/Src/%.su algorithm/Src/%.cyclo: ../algorithm/Src/%.cpp algorithm/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/Libs/Inc" -I"D:/Micromouse/Firmware/Quanta_micromouse/Quanta_firmware/algorithm/lnc" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-algorithm-2f-Src

clean-algorithm-2f-Src:
	-$(RM) ./algorithm/Src/minimaze.cyclo ./algorithm/Src/minimaze.d ./algorithm/Src/minimaze.o ./algorithm/Src/minimaze.su

.PHONY: clean-algorithm-2f-Src

