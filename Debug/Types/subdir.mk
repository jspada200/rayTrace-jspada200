################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Types/Ray.cpp \
../Types/Vec3.cpp 

OBJS += \
./Types/Ray.o \
./Types/Vec3.o 

CPP_DEPS += \
./Types/Ray.d \
./Types/Vec3.d 


# Each subdirectory must supply rules for building sources it contributes
Types/%.o: ../Types/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


