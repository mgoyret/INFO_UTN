################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Servo_PWM.c \
../App/cr_startup_lpc175x_6x.c \
../App/crp.c 

OBJS += \
./App/Servo_PWM.o \
./App/cr_startup_lpc175x_6x.o \
./App/crp.o 

C_DEPS += \
./App/Servo_PWM.d \
./App/cr_startup_lpc175x_6x.d \
./App/crp.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o: ../App/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\nicoc\Documents\MCUXpressoIDE_10.2.0_759\workspace\Servo_PWM\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


