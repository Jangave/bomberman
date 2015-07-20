################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/entity/Imob.cpp \
../core/entity/Mob.cpp \
../core/entity/Object.cpp 

OBJS += \
./core/entity/Imob.o \
./core/entity/Mob.o \
./core/entity/Object.o 

CPP_DEPS += \
./core/entity/Imob.d \
./core/entity/Mob.d \
./core/entity/Object.d 


# Each subdirectory must supply rules for building sources it contributes
core/entity/%.o: ../core/entity/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


