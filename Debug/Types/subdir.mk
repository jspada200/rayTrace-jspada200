################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Types/Face.cpp \
../Types/GeometricSolid.cpp \
../Types/Ray.cpp \
../Types/Renderer.cpp \
../Types/Scene.cpp \
../Types/Vec3.cpp 

OBJS += \
./Types/Face.o \
./Types/GeometricSolid.o \
./Types/Ray.o \
./Types/Renderer.o \
./Types/Scene.o \
./Types/Vec3.o 

CPP_DEPS += \
./Types/Face.d \
./Types/GeometricSolid.d \
./Types/Ray.d \
./Types/Renderer.d \
./Types/Scene.d \
./Types/Vec3.d 


# Each subdirectory must supply rules for building sources it contributes
Types/%.o: ../Types/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


