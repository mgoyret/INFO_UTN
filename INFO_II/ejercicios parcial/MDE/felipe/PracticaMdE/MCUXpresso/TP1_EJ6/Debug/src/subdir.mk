################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP1_EJ6.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/maquinaestados.c 

OBJS += \
./src/TP1_EJ6.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/maquinaestados.o 

C_DEPS += \
./src/TP1_EJ6.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/maquinaestados.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m3 -mthumb -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


