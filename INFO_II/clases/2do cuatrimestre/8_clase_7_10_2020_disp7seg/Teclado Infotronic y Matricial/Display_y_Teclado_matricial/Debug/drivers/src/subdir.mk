################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/FW_InitExpansion3.c \
../drivers/src/GPIO.c \
../drivers/src/Inic_PLL.c \
../drivers/src/Init_GPIO.c \
../drivers/src/RGB.c \
../drivers/src/Systick.c \
../drivers/src/Teclado.c \
../drivers/src/cr_startup_lpc176x.c \
../drivers/src/crp.c 

OBJS += \
./drivers/src/FW_InitExpansion3.o \
./drivers/src/GPIO.o \
./drivers/src/Inic_PLL.o \
./drivers/src/Init_GPIO.o \
./drivers/src/RGB.o \
./drivers/src/Systick.o \
./drivers/src/Teclado.o \
./drivers/src/cr_startup_lpc176x.o \
./drivers/src/crp.o 

C_DEPS += \
./drivers/src/FW_InitExpansion3.d \
./drivers/src/GPIO.d \
./drivers/src/Inic_PLL.d \
./drivers/src/Init_GPIO.d \
./drivers/src/RGB.d \
./drivers/src/Systick.d \
./drivers/src/Teclado.d \
./drivers/src/cr_startup_lpc176x.d \
./drivers/src/crp.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\aplicacion\inc" -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\drivers\inc" -I"C:\Users\fedeb\Documents\MCUXpressoIDE_10.2.0_759\workspace\Display_y_Teclado_matricial\drivers\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


