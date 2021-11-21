################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Arcade.c \
../src/Game.c \
../src/LinkedList.c \
../src/Segundo_parcial.c \
../src/controller.c \
../src/idFactory.c \
../src/input.c \
../src/menu.c \
../src/myStr.c \
../src/parser.c 

OBJS += \
./src/Arcade.o \
./src/Game.o \
./src/LinkedList.o \
./src/Segundo_parcial.o \
./src/controller.o \
./src/idFactory.o \
./src/input.o \
./src/menu.o \
./src/myStr.o \
./src/parser.o 

C_DEPS += \
./src/Arcade.d \
./src/Game.d \
./src/LinkedList.d \
./src/Segundo_parcial.d \
./src/controller.d \
./src/idFactory.d \
./src/input.d \
./src/menu.d \
./src/myStr.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


