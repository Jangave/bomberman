################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/Ambient.cpp \
../core/Drawer.cpp \
../core/Image.cpp \
../core/Map.cpp \
../core/Node.cpp \
../core/Position.cpp \
../core/Shape.cpp \
../core/Window.cpp 

OBJS += \
./core/Ambient.o \
./core/Drawer.o \
./core/Image.o \
./core/Map.o \
./core/Node.o \
./core/Position.o \
./core/Shape.o \
./core/Window.o 

CPP_DEPS += \
./core/Ambient.d \
./core/Drawer.d \
./core/Image.d \
./core/Map.d \
./core/Node.d \
./core/Position.d \
./core/Shape.d \
./core/Window.d 


# Each subdirectory must supply rules for building sources it contributes
core/%.o: ../core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


