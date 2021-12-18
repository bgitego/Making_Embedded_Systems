################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/stm32g4xx_hal_msp.c \
../Src/stm32g4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32g4xx.c \
../Src/user_main.c 

OBJS += \
./Src/main.o \
./Src/stm32g4xx_hal_msp.o \
./Src/stm32g4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32g4xx.o \
./Src/user_main.o 

C_DEPS += \
./Src/main.d \
./Src/stm32g4xx_hal_msp.d \
./Src/stm32g4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32g4xx.d \
./Src/user_main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Inc -IC:/Users/bot-10/STM32Cube/Repository/STM32Cube_FW_G4_V1.3.0/Drivers/STM32G4xx_HAL_Driver/Inc -IC:/Users/bot-10/STM32Cube/Repository/STM32Cube_FW_G4_V1.3.0/Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -IC:/Users/bot-10/STM32Cube/Repository/STM32Cube_FW_G4_V1.3.0/Drivers/CMSIS/Device/ST/STM32G4xx/Include -IC:/Users/bot-10/STM32Cube/Repository/STM32Cube_FW_G4_V1.3.0/Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.d ./Src/main.o ./Src/stm32g4xx_hal_msp.d ./Src/stm32g4xx_hal_msp.o ./Src/stm32g4xx_it.d ./Src/stm32g4xx_it.o ./Src/syscalls.d ./Src/syscalls.o ./Src/system_stm32g4xx.d ./Src/system_stm32g4xx.o ./Src/user_main.d ./Src/user_main.o

.PHONY: clean-Src

