################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Primitivas/PR_7Seg.c \
../Primitivas/teclado_prim.c 

OBJS += \
./Primitivas/PR_7Seg.o \
./Primitivas/teclado_prim.o 

C_DEPS += \
./Primitivas/PR_7Seg.d \
./Primitivas/teclado_prim.d 


# Each subdirectory must supply rules for building sources it contributes
Primitivas/%.o: ../Primitivas/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\aplicacion\inc" -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\drivers\inc" -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\drivers\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


