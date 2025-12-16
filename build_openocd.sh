#! /bin/sh

if [ "$1" = "-i" ]
then 
echo "Incremental build.."
make -j 32
else
echo "Clean Build.."
#cd openocd
make clean 
make clean-am
make distclean
./bootstrap
./configure --disable-werror --enable-eud --disable-internal-libjaylink --disable-jlink --disable-ftdi --disable-dummy --disable-rshim --disable-stlink --disable-ti-icdi --disable-ulink --disable-usb-blaster-2 --disable-ft232r --disable-vsllink --disable-xds110 --disable-cmsis-dap-v2 --disable-osbdm --disable-opendous --disable-aice --disable-usbprog --disable-rlink --disable-armjtagew --disable-cmsis-dap --disable-nulink --disable-kitprog --disable-usb-blaster --disable-presto --disable-openjtag --disable-parport --disable-parport-giveio --disable-jtag_vpi --disable-jtag_dpi --disable-amtjtagaccel --disable-zy1000-master --disable-zy1000 --disable-ioutil --disable-bcm2835gpio --disable-imx_gpio --disable-ep93xx --disable-at91rm9200 --disable-gw16012 --disable-oocd_trace --disable-buspirate --disable-sysfsgpio --disable-xlnx-pcie-xvc --disable-minidriver-dummy --disable-remote-bitbang --disable-parport-ppdev --disable-esp-usb-jtag
make -j 32
#cd ..
fi
