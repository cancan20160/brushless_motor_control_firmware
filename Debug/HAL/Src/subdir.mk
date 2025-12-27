################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Src/hal_adc.c \
../HAL/Src/hal_gpio.c \
../HAL/Src/hal_timer.c 

OBJS += \
./HAL/Src/hal_adc.o \
./HAL/Src/hal_gpio.o \
./HAL/Src/hal_timer.o 

C_DEPS += \
./HAL/Src/hal_adc.d \
./HAL/Src/hal_gpio.d \
./HAL/Src/hal_timer.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Src/%.o HAL/Src/%.su HAL/Src/%.cyclo: ../HAL/Src/%.c HAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/HAL/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/BSP/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Control/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Utils/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-HAL-2f-Src

clean-HAL-2f-Src:
	-$(RM) ./HAL/Src/hal_adc.cyclo ./HAL/Src/hal_adc.d ./HAL/Src/hal_adc.o ./HAL/Src/hal_adc.su ./HAL/Src/hal_gpio.cyclo ./HAL/Src/hal_gpio.d ./HAL/Src/hal_gpio.o ./HAL/Src/hal_gpio.su ./HAL/Src/hal_timer.cyclo ./HAL/Src/hal_timer.d ./HAL/Src/hal_timer.o ./HAL/Src/hal_timer.su

.PHONY: clean-HAL-2f-Src

