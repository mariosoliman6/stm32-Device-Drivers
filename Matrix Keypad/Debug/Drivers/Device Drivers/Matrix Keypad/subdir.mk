################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.c 

OBJS += \
./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.o 

C_DEPS += \
./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.o: ../Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.c Drivers/Device\ Drivers/Matrix\ Keypad/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Drivers/Device Drivers/Matrix Keypad/Matrix_Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Device-20-Drivers-2f-Matrix-20-Keypad

clean-Drivers-2f-Device-20-Drivers-2f-Matrix-20-Keypad:
	-$(RM) ./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.cyclo ./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.d ./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.o ./Drivers/Device\ Drivers/Matrix\ Keypad/Matrix_Keypad.su

.PHONY: clean-Drivers-2f-Device-20-Drivers-2f-Matrix-20-Keypad

