################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CONFIG.c \
../Drivers/GPIO.c \
../Drivers/Inic.c \
../Drivers/Interrupcion_ext.c \
../Drivers/Oscilador.c \
../Drivers/PWM_Salidas.c \
../Drivers/cr_startup_lpc175x_6x.c \
../Drivers/crp.c 

OBJS += \
./Drivers/CONFIG.o \
./Drivers/GPIO.o \
./Drivers/Inic.o \
./Drivers/Interrupcion_ext.o \
./Drivers/Oscilador.o \
./Drivers/PWM_Salidas.o \
./Drivers/cr_startup_lpc175x_6x.o \
./Drivers/crp.o 

C_DEPS += \
./Drivers/CONFIG.d \
./Drivers/GPIO.d \
./Drivers/Inic.d \
./Drivers/Interrupcion_ext.d \
./Drivers/Oscilador.d \
./Drivers/PWM_Salidas.d \
./Drivers/cr_startup_lpc175x_6x.d \
./Drivers/crp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\nicoc\Documents\MCUXpressoIDE_10.2.0_759\workspace\Led_PWM\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


