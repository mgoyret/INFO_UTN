################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/funciones.c \
../src/main.c 

OBJS += \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/funciones.o \
./src/main.o 

C_DEPS += \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/funciones.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Federico\Documents\MCUXpressoIDE_10.3.0_2200\workspace\Teclado_RGB\inc" -I"C:\Users\Federico\Desktop\Informatica II\biblioteca\bibliotecaInfo2-Distribucion-060618" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


