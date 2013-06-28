#!/usr/bin/env bash

function check_result {
  if [ "0" -ne "$?" ]
  then
    echo $1
    exit 1
  fi
}

if [ -z "$DEFCONFIG" ]
then
  if [ -z "$1" ]
  then
    echo DEFCONFIG not specified
    exit 1
  fi
  export DEFCONFIG=$1
fi

echo cloning AnyKernel...
rm -rf ~/AnyKernel
git clone git://github.com/yanniks/AnyKernel.git ~/AnyKernel
echo done!
echo exporting some functions...
export ARCH=arm
echo done!
echo cleaning...
make clean
check_result "Cleaning failed."
echo done!
echo start compiling for $DEFCONFIG ...
make $DEFCONFIG_defconfig
check_result "Setting defconfig failed."
make
check_result "Build failed."
echo done!
echo creating update zip...
bash zip
check_result "Creating zip failed."
echo done!
if [ "$RELEASE" = "true" ]
then
  echo releasing...
  mv /var/lib/jenkins/kernel-*.zip /var/www/kernel
  echo released new kernel binary under http://yauniks.homeunix.net/
  check_result "Release failed."
else
  echo everything done!
fi
