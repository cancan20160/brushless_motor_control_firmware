################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Src/brake.c \
../BSP/Src/current_sensor.c \
../BSP/Src/direction.c \
../BSP/Src/hall_sensor_driver.c \
../BSP/Src/pwm_driver.c \
../BSP/Src/temperature_sensor.c \
../BSP/Src/throttle.c \
../BSP/Src/voltage_sensor.c 

OBJS += \
./BSP/Src/brake.o \
./BSP/Src/current_sensor.o \
./BSP/Src/direction.o \
./BSP/Src/hall_sensor_driver.o \
./BSP/Src/pwm_driver.o \
./BSP/Src/temperature_sensor.o \
./BSP/Src/throttle.o \
./BSP/Src/voltage_sensor.o 

C_DEPS += \
./BSP/Src/brake.d \
./BSP/Src/current_sensor.d \
./BSP/Src/direction.d \
./BSP/Src/hall_sensor_driver.d \
./BSP/Src/pwm_driver.d \
./BSP/Src/temperature_sensor.d \
./BSP/Src/throttle.d \
./BSP/Src/voltage_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Src/%.o BSP/Src/%.su BSP/Src/%.cyclo: ../BSP/Src/%.c BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/HAL/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/BSP/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Control/Inc" -I"C:/Users/Can/Documents/STM32CubeIDE/BLDC_Motor_Driver/Utils/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-Src

clean-BSP-2f-Src:
	-$(RM) ./BSP/Src/brake.cyclo ./BSP/Src/brake.d ./BSP/Src/brake.o ./BSP/Src/brake.su ./BSP/Src/current_sensor.cyclo ./BSP/Src/current_sensor.d ./BSP/Src/current_sensor.o ./BSP/Src/current_sensor.su ./BSP/Src/direction.cyclo ./BSP/Src/direction.d ./BSP/Src/direction.o ./BSP/Src/direction.su ./BSP/Src/hall_sensor_driver.cyclo ./BSP/Src/hall_sensor_driver.d ./BSP/Src/hall_sensor_driver.o ./BSP/Src/hall_sensor_driver.su ./BSP/Src/pwm_driver.cyclo ./BSP/Src/pwm_driver.d ./BSP/Src/pwm_driver.o ./BSP/Src/pwm_driver.su ./BSP/Src/temperature_sensor.cyclo ./BSP/Src/temperature_sensor.d ./BSP/Src/temperature_sensor.o ./BSP/Src/temperature_sensor.su ./BSP/Src/throttle.cyclo ./BSP/Src/throttle.d ./BSP/Src/throttle.o ./BSP/Src/throttle.su ./BSP/Src/voltage_sensor.cyclo ./BSP/Src/voltage_sensor.d ./BSP/Src/voltage_sensor.o ./BSP/Src/voltage_sensor.su

.PHONY: clean-BSP-2f-Src

