################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Control/Src/commutation.c \
../Control/Src/motor_control.c \
../Control/Src/state_machine.c 

OBJS += \
./Control/Src/commutation.o \
./Control/Src/motor_control.o \
./Control/Src/state_machine.o 

C_DEPS += \
./Control/Src/commutation.d \
./Control/Src/motor_control.d \
./Control/Src/state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
Control/Src/%.o Control/Src/%.su Control/Src/%.cyclo: ../Control/Src/%.c Control/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/HAL/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/BSP/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Control/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Utils/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Control-2f-Src

clean-Control-2f-Src:
	-$(RM) ./Control/Src/commutation.cyclo ./Control/Src/commutation.d ./Control/Src/commutation.o ./Control/Src/commutation.su ./Control/Src/motor_control.cyclo ./Control/Src/motor_control.d ./Control/Src/motor_control.o ./Control/Src/motor_control.su ./Control/Src/state_machine.cyclo ./Control/Src/state_machine.d ./Control/Src/state_machine.o ./Control/Src/state_machine.su

.PHONY: clean-Control-2f-Src

