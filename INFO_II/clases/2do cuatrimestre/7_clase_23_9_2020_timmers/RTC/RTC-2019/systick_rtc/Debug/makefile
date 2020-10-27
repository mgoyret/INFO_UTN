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
all: systick_rtc.axf

# Tool invocations
systick_rtc.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="systick_rtc.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "systick_rtc_Debug.ld" -o "systick_rtc.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) systick_rtc.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "systick_rtc.axf"; # arm-none-eabi-objcopy -O binary "systick_rtc.axf" "systick_rtc.bin" ; checksum -p LPC1769 -d "systick_rtc.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
