echo cloning AnyKernel...
rm -rf ~/AnyKernel
git clone git://github.com/yanniks/AnyKernel.git ~/AnyKernel
echo done!
echo exporting some functions...
export ARCH=arm
echo done!
echo cleaning...
make clean
echo done!
echo start compiling for $DEFCONFIG ...
make $DEFCONFIG_defconfig
make
echo done!
echo creating update zip...
bash zip
echo done!
if [ "$RELEASE" = "true" ]
then
  echo releasing...
  mv /var/lib/jenkins/kernel-*.zip /var/www/kernel
  echo released new kernel binary under http://yauniks.homeunix.net/
else
  echo everything done!
fi
