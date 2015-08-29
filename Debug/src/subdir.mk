################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/BPM.c \
../src/Median.c \
../src/UnityTestsProject.c 

OBJS += \
./src/BPM.o \
./src/Median.o \
./src/UnityTestsProject.o 

C_DEPS += \
./src/BPM.d \
./src/Median.d \
./src/UnityTestsProject.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/rrak/workspace/C_Median_TestProject/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


