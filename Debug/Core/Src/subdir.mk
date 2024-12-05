################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/fsm.c \
../Core/Src/fsm_auto.c \
../Core/Src/fsm_manual.c \
../Core/Src/fsm_tuning.c \
../Core/Src/i2c-lcd.c \
../Core/Src/input_reading.c \
../Core/Src/lcd.c \
../Core/Src/led_display.c \
../Core/Src/main.c \
../Core/Src/scheduler.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/sw_timer.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c 

OBJS += \
./Core/Src/fsm.o \
./Core/Src/fsm_auto.o \
./Core/Src/fsm_manual.o \
./Core/Src/fsm_tuning.o \
./Core/Src/i2c-lcd.o \
./Core/Src/input_reading.o \
./Core/Src/lcd.o \
./Core/Src/led_display.o \
./Core/Src/main.o \
./Core/Src/scheduler.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/sw_timer.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o 

C_DEPS += \
./Core/Src/fsm.d \
./Core/Src/fsm_auto.d \
./Core/Src/fsm_manual.d \
./Core/Src/fsm_tuning.d \
./Core/Src/i2c-lcd.d \
./Core/Src/input_reading.d \
./Core/Src/lcd.d \
./Core/Src/led_display.d \
./Core/Src/main.d \
./Core/Src/scheduler.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/sw_timer.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/fsm.cyclo ./Core/Src/fsm.d ./Core/Src/fsm.o ./Core/Src/fsm.su ./Core/Src/fsm_auto.cyclo ./Core/Src/fsm_auto.d ./Core/Src/fsm_auto.o ./Core/Src/fsm_auto.su ./Core/Src/fsm_manual.cyclo ./Core/Src/fsm_manual.d ./Core/Src/fsm_manual.o ./Core/Src/fsm_manual.su ./Core/Src/fsm_tuning.cyclo ./Core/Src/fsm_tuning.d ./Core/Src/fsm_tuning.o ./Core/Src/fsm_tuning.su ./Core/Src/i2c-lcd.cyclo ./Core/Src/i2c-lcd.d ./Core/Src/i2c-lcd.o ./Core/Src/i2c-lcd.su ./Core/Src/input_reading.cyclo ./Core/Src/input_reading.d ./Core/Src/input_reading.o ./Core/Src/input_reading.su ./Core/Src/lcd.cyclo ./Core/Src/lcd.d ./Core/Src/lcd.o ./Core/Src/lcd.su ./Core/Src/led_display.cyclo ./Core/Src/led_display.d ./Core/Src/led_display.o ./Core/Src/led_display.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/scheduler.cyclo ./Core/Src/scheduler.d ./Core/Src/scheduler.o ./Core/Src/scheduler.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/sw_timer.cyclo ./Core/Src/sw_timer.d ./Core/Src/sw_timer.o ./Core/Src/sw_timer.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su

.PHONY: clean-Core-2f-Src

