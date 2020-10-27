################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
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
all: ejemplo_intext.axf

# Tool invocations
ejemplo_intext.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="ejemplo_intext.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "ejemplo_intext_Debug.ld" -o "ejemplo_intext.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) ejemplo_intext.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "ejemplo_intext.axf"; # arm-none-eabi-objcopy -O binary "ejemplo_intext.axf" "ejemplo_intext.bin" ; checksum -p LPC1769 -d "ejemplo_intext.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
