INCLUDE(../../cmakemodules/AssureCMakeRootFile.cmake) # Avoid user mistake in CMake source directory

#-----------------------------------------------------------------
# CMake file for the MRPT application:  kinect-3d-slam
#
#  Run with "cmake ." at the root directory
#-----------------------------------------------------------------
PROJECT(kinect_3d_slam)

# ---------------------------------------------
# TARGET:
# ---------------------------------------------
# Define the executable target:
ADD_EXECUTABLE(kinect-3d-slam
               kinect-3d-slam_main.cpp)

SET(TMP_TARGET_NAME "kinect-3d-slam")



# Add the required libraries for linking:
TARGET_LINK_LIBRARIES(${TMP_TARGET_NAME} ${MRPT_LINKER_LIBS})

# Dependencies on MRPT libraries:
#  Just mention the top-level dependency, the rest will be detected automatically, 
#  and all the needed #include<> dirs added (see the script DeclareAppDependencies.cmake for further details)
DeclareAppDependencies(${TMP_TARGET_NAME} mrpt-gui mrpt-slam mrpt-hwdrivers mrpt-vision)

DeclareAppForInstall(${TMP_TARGET_NAME})

AppStartMenuLink(${TMP_TARGET_NAME} "Very simple live 3D-SLAM with Kinect")   # Add link to the Start menu (in Windows Installable packages)
