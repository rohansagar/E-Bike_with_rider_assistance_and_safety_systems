################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
drivers/buttons.obj: /Users/rohan/ti/tivaware_c_series_2_1_4_178/examples/boards/ek-tm4c123gxl/drivers/buttons.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 --include_path="/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --include_path="/Users/rohan/workspace_v9/Lighting_Unit_RTOS" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/examples/boards/ek-tm4c123gxl" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS/Source/include" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --advice:power=all -g --c99 --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="drivers/$(basename $(<F)).d_raw" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

drivers/rgb.obj: /Users/rohan/ti/tivaware_c_series_2_1_4_178/examples/boards/ek-tm4c123gxl/drivers/rgb.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O2 --include_path="/Applications/ti/ccs910/ccs/tools/compiler/ti-cgt-arm_18.12.2.LTS/include" --include_path="/Users/rohan/workspace_v9/Lighting_Unit_RTOS" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/examples/boards/ek-tm4c123gxl" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS/Source/include" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS" --include_path="/Users/rohan/ti/tivaware_c_series_2_1_4_178/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --advice:power=all -g --c99 --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --ual --preproc_with_compile --preproc_dependency="drivers/$(basename $(<F)).d_raw" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


