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
all: Contados_autos.axf

# Tool invocations
Contados_autos.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/mica/Documents/Informatica_II/MCUXpresso_11.1.1_3241/workspace/Contados_autos/bibliotecaInfo2-Distribucion-060618" -Xlinker -Map="Contados_autos.map" -Xlinker --cref -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "Contados_autos_Debug.ld" -o "Contados_autos.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Contados_autos.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Contados_autos.axf"; # arm-none-eabi-objcopy -v -O binary "Contados_autos.axf" "Contados_autos.bin" ; # checksum -p LPC1769 -d "Contados_autos.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
