################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include drivers/src/subdir.mk
-include aplicacion/src/subdir.mk
-include Primitivas/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Display_y_Debounce_SinConversor.axf

# Tool invocations
Display_y_Debounce_SinConversor.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="Display_y_Debounce_SinConversor.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "Display_y_Debounce_SinConversor_Debug.ld" -o "Display_y_Debounce_SinConversor.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Display_y_Debounce_SinConversor.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Display_y_Debounce_SinConversor.axf"; # arm-none-eabi-objcopy -v -O binary "Display_y_Debounce_SinConversor.axf" "Display_y_Debounce_SinConversor.bin" ; # checksum -p LPC1769 -d "Display_y_Debounce_SinConversor.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
