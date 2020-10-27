################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_GPIO.c \
../Drivers/DR_PINSEL.c \
../Drivers/DR_PLL.c \
../Drivers/DR_Systick.c \
../Drivers/cr_startup_lpc175x_6x.c \
../Drivers/crp.c \
../Drivers/init.c 

OBJS += \
./Drivers/DR_GPIO.o \
./Drivers/DR_PINSEL.o \
./Drivers/DR_PLL.o \
./Drivers/DR_Systick.o \
./Drivers/cr_startup_lpc175x_6x.o \
./Drivers/crp.o \
./Drivers/init.o 

C_DEPS += \
./Drivers/DR_GPIO.d \
./Drivers/DR_PINSEL.d \
./Drivers/DR_PLL.d \
./Drivers/DR_Systick.d \
./Drivers/cr_startup_lpc175x_6x.d \
./Drivers/crp.d \
./Drivers/init.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\nicoc\Documents\MCUXpressoIDE_11.1.1_3241\workspace\LedSystick\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


