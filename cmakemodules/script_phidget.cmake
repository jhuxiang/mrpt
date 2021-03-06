# Support for phidget Interface Kit with proximity sensor device :
# ===================================================
SET( MRPT_HAS_PHIDGET OFF CACHE BOOL "Add supprt for Phidget Interface kit with range sensors")
IF(MRPT_HAS_PHIDGET)
	SET(CMAKE_MRPT_HAS_PHIDGET 1)
	SET(PHIDGET_ROOT_DIR "/usr/local" CACHE PATH "Path where libPhidget21 was installed, if phidget21.h is in /usr/local/include, set this variable to /usr/local.")
	IF(UNIX)
		IF(NOT EXISTS ${PHIDGET_ROOT_DIR}/include/phidget21.h)
			SET(CMAKE_MRPT_HAS_PHIDGET 0)
			MESSAGE("Can't find incude file phidget21.h, please set a correct PHIDGET_ROOT_DIR")
		ENDIF(NOT EXISTS ${PHIDGET_ROOT_DIR}/include/phidget21.h)
		IF(NOT EXISTS ${PHIDGET_ROOT_DIR}/lib/libphidget21.so)
			SET(CMAKE_MRPT_HAS_PHIDGET 0)
			MESSAGE("Can't find incude file libphidget21.so, please set a correct PHIDGET_ROOT_DIR")
		ENDIF(NOT EXISTS ${PHIDGET_ROOT_DIR}/lib/libphidget21.so)
	ELSE(UNIX)
		SET(CMAKE_MRPT_HAS_PHIDGET 0)
		MESSAGE("The MRPT Phidget library interface is only supported on linux, please turn off MRPT_HAS_PHIDGET")
	ENDIF(UNIX)
ENDIF(MRPT_HAS_PHIDGET)


IF(CMAKE_MRPT_HAS_PHIDGET)
	INCLUDE_DIRECTORIES("${PHIDGET_ROOT_DIR}/include/")
	LINK_DIRECTORIES("${PHIDGET_ROOT_DIR}/lib")
ENDIF(CMAKE_MRPT_HAS_PHIDGET)

# Can only be a system lib:
SET(CMAKE_MRPT_HAS_PHIDGET_SYSTEM 0)
IF(CMAKE_MRPT_HAS_PHIDGET)
	SET(CMAKE_MRPT_HAS_PHIDGET_SYSTEM 1)
ENDIF(CMAKE_MRPT_HAS_PHIDGET)

