################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Bomb.cpp \
../Bomberman.cpp \
../Character.cpp \
../Fire.cpp \
../Rock.cpp \
../Wall.cpp 

OBJS += \
./Bomb.o \
./Bomberman.o \
./Character.o \
./Fire.o \
./Rock.o \
./Wall.o 

CPP_DEPS += \
./Bomb.d \
./Bomberman.d \
./Character.d \
./Fire.d \
./Rock.d \
./Wall.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


