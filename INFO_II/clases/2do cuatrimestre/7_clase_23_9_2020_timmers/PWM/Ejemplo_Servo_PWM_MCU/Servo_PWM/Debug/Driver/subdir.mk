################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/CONFIG.c \
../Driver/GPIO.c \
../Driver/Inic.c \
../Driver/Oscilador.c 

OBJS += \
./Driver/CONFIG.o \
./Driver/GPIO.o \
./Driver/Inic.o \
./Driver/Oscilador.o 

C_DEPS += \
./Driver/CONFIG.d \
./Driver/GPIO.d \
./Driver/Inic.d \
./Driver/Oscilador.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/%.o: ../Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\nicoc\Documents\MCUXpressoIDE_10.2.0_759\workspace\Servo_PWM\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


