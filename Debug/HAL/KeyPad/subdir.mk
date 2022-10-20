################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KeyPad/KeyPad_Prog.c 

OBJS += \
./HAL/KeyPad/KeyPad_Prog.o 

C_DEPS += \
./HAL/KeyPad/KeyPad_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KeyPad/%.o: ../HAL/KeyPad/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\APP" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\Fan" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\AT24C16A" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\AT24C16A" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\I2C" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\SPI" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\UART" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\Servo" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\DCMotor" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\WDT" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\GIE" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\Timer" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LM35" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\ADC" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\KeyPad" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\EXT_INT" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LCD" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\APP\Projects" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\SSD" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\PB" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\Buzzer" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\MCAL\DIO" -I"C:\Users\LENOVO.SXM10\Desktop\SLAVE\slave\HAL\LED" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


