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

Step 1.
  # apt-get install libcv-dev libhighgui-dev libcvaux-dev libgtkmm-2.4-dev libcairomm-1.0-dev libboost-dev
  # sudo apt-get install cmake cmake-curses-gui
Step 2. 
  # git clone git://git.code.sf.net/p/vxl/git vxl-git
  # git checkout -b dev15 a880ccc
  # mkdir vxl-bin
  # cd vxl-bin
  # ccmake ../vxl-git
  # ccmake ./
  # make           (or you can use 'make -j 8' to boost the compilation)
  # sudo make install
  Configure and generate Makefile by the two "ccmake" commands
  set BUILD_SHARED_LIBS to ON
  set BUILD_TESTING to OFF (this will make the build shorter)
  set EXAMPLES to OFF (make the build shorter)
  Set everything else to default
Step 3.
  #sudo ln -s /usr/local/lib/libvnl.so /usr/lib/
  #sudo ln -s /usr/local/lib/libmvl.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvnl_algo.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvgl.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvcl.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvil1.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvbl.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvgl_algo.so /usr/lib/
  #sudo ln -s /usr/local/lib/libvul.so /usr/lib/
  #sudo ln -s /usr/local/lib/libnetlib.so /usr/lib/
  #sudo ln -s /usr/local/lib/libv3p_netlib.so /usr/lib/ 
Step 4.
  # cd opengazer-0.1.2
  # make
  # sudo addgroup $USER video
  
<strong>Run</strong>
  # ./opengazer

Other files used by opengazer

   calpoints.txt   Coordinates calibration points 
   		   (as fraction of the screen)

   points.txt      Coordinates of the tracking points on the user face, in
   		   pixels.  This file is saved when the user clicks
   		   "Save points"
   
<strong>References</strong>
http://www.mirkules.com/opengazer/opengazer-installation
http://www.inference.phy.cam.ac.uk/opengazer/README
https://github.com/opengazer/OpenGazer/issues/1

   
