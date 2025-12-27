################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utils/Src/filter.c 

OBJS += \
./Utils/Src/filter.o 

C_DEPS += \
./Utils/Src/filter.d 


# Each subdirectory must supply rules for building sources it contributes
Utils/Src/%.o Utils/Src/%.su Utils/Src/%.cyclo: ../Utils/Src/%.c Utils/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/HAL/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/BSP/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Control/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Utils/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Utils-2f-Src

clean-Utils-2f-Src:
	-$(RM) ./Utils/Src/filter.cyclo ./Utils/Src/filter.d ./Utils/Src/filter.o ./Utils/Src/filter.su

.PHONY: clean-Utils-2f-Src

