OpenGazer
=================


<strong>Requirements</strong>:<br>
  vxl >= 1.5.1	        http://vxl.sourceforge.net/<br>
  opencv >= 0.9.7	http://sourceforge.net/projects/opencvlibrary<br>
  gtkmm-2.4 >= 2.8.0	http://www.gtkmm.org/<br>
  cairomm-1.0 >= 0.6.0  http://cairographics.org/cairomm/<br>
  boost >= 1.32.0	http://www.boost.org/<br>
  An off-the-shelf webcam<br>
	
Under <strong>Ubuntu1204 LTS</strong> (Must be 1204 version) testing:

Directory Structure:<br>
.<br>
├── opengazer-0.1.2<br>
├── vxl-bin<br>
└── vxl-git<br>

Step 1.<br>
  # apt-get install libcv-dev libhighgui-dev libcvaux-dev libgtkmm-2.4-dev libcairomm-1.0-dev libboost-dev<br>
  # sudo apt-get install cmake cmake-curses-gui<br>
Step 2. <br>
  # git clone git://git.code.sf.net/p/vxl/git vxl-git<br>
  # git checkout -b dev15 a880ccc<br>
  # mkdir vxl-bin<br>
  # cd vxl-bin<br>
  # ccmake ../vxl-git<br>
  # ccmake ./<br>
  # make           (or you can use 'make -j 8' to boost the compilation)<br>
  # sudo make install<br>
  Configure and generate Makefile by the two "ccmake" commands<br>
  set BUILD_SHARED_LIBS to ON<br>
  set BUILD_TESTING to OFF (this will make the build shorter)<br>
  set EXAMPLES to OFF (make the build shorter)<br>
  Set everything else to default<br>
Step 3.<br>
  #sudo ln -s /usr/local/lib/libvnl.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libmvl.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvnl_algo.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvgl.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvcl.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvil1.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvbl.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvgl_algo.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libvul.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libnetlib.so /usr/lib/<br>
  #sudo ln -s /usr/local/lib/libv3p_netlib.so /usr/lib/ <br>
Step 4.<br>
  # cd opengazer-0.1.2<br>
  # make<br>
  # sudo addgroup $USER video<br>
  
<strong>Run</strong><br>
  # ./opengazer<br>

Other files used by opengazer

   calpoints.txt   Coordinates calibration points <br>
   		   (as fraction of the screen)<br>
<br>
   points.txt      Coordinates of the tracking points on the user face, in<br>
   		   pixels.  This file is saved when the user clicks<br>
   		   "Save points"<br>
   
<strong>References</strong><br>
http://www.mirkules.com/opengazer/opengazer-installation<br>
http://www.inference.phy.cam.ac.uk/opengazer/README<br>
https://github.com/opengazer/OpenGazer/issues/1<br>

   
