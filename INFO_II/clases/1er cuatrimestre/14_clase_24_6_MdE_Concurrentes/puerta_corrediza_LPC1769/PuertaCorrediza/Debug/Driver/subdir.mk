################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/cr_startup_lpc175x_6x.c \
../Driver/crp.c 

OBJS += \
./Driver/cr_startup_lpc175x_6x.o \
./Driver/crp.o 

C_DEPS += \
./Driver/cr_startup_lpc175x_6x.d \
./Driver/crp.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/%.o: ../Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\nicoc\Documents\MCUXpressoIDE_11.0.0_2516\workspace\PuertaCorrediza\Biblioteca info 2 LPC" -I"C:\Users\nicoc\Documents\MCUXpressoIDE_11.0.0_2516\workspace\PuertaCorrediza\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


