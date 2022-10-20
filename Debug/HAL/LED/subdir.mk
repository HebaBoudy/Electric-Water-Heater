################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LED/LED_Prog.c 

OBJS += \
./HAL/LED/LED_Prog.o 

C_DEPS += \
./HAL/LED/LED_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LED/%.o: ../HAL/LED/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\APP" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\I2C" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\HeatingElement" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\Fan" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\AT24C16A" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\GIE" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\Timer" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LM35" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\ADC" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\EXT_INT" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LCD" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\SSD" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\DIO" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LED" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


