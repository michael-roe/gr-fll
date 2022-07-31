find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_FLL gnuradio-fll)

FIND_PATH(
    GR_FLL_INCLUDE_DIRS
    NAMES gnuradio/fll/api.h
    HINTS $ENV{FLL_DIR}/include
        ${PC_FLL_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_FLL_LIBRARIES
    NAMES gnuradio-fll
    HINTS $ENV{FLL_DIR}/lib
        ${PC_FLL_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-fllTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_FLL DEFAULT_MSG GR_FLL_LIBRARIES GR_FLL_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_FLL_LIBRARIES GR_FLL_INCLUDE_DIRS)
