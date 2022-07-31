INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FLL fll)

FIND_PATH(
    FLL_INCLUDE_DIRS
    NAMES fll/api.h
    HINTS $ENV{FLL_DIR}/include
        ${PC_FLL_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FLL_LIBRARIES
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

include("${CMAKE_CURRENT_LIST_DIR}/fllTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FLL DEFAULT_MSG FLL_LIBRARIES FLL_INCLUDE_DIRS)
MARK_AS_ADVANCED(FLL_LIBRARIES FLL_INCLUDE_DIRS)
