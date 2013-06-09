#!/bin/bash

DEFCONFIG_FILE=$1

if [ -z "$DEFCONFIG_FILE" ]; then
	echo "Need defconfig file(spade_defconfig)!"
	exit -1
fi

if [ ! -e arch/arm/configs/$DEFCONFIG_FILE ]; then
	echo "No such file : arch/arm/configs/$DEFCONFIG_FILE"
	exit -1
fi

# update current config
export ARCH=arm
make $DEFCONFIG_FILE

# run menuconfig
make menuconfig

# copy .config to defconfig
rm arch/arm/configs/${DEFCONFIG_FILE}
mv .config arch/arm/configs/${DEFCONFIG_FILE}
# clean kernel object
make mrproper
