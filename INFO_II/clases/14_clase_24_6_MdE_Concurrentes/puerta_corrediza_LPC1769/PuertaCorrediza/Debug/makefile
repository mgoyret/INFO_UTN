################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Primitivas/subdir.mk
-include Driver/subdir.mk
-include Aplicacion/subdir.mk
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
all: PuertaCorrediza.axf

# Tool invocations
PuertaCorrediza.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\Users\nicoc\Documents\MCUXpressoIDE_11.0.0_2516\workspace\PuertaCorrediza\Biblioteca info 2 LPC" -Xlinker -Map="PuertaCorrediza.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "PuertaCorrediza_Debug.ld" -o "PuertaCorrediza.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) PuertaCorrediza.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "PuertaCorrediza.axf"; # arm-none-eabi-objcopy -v -O binary "PuertaCorrediza.axf" "PuertaCorrediza.bin" ; # checksum -p LPC1769 -d "PuertaCorrediza.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
