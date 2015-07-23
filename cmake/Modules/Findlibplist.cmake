# - Try to find libplist
# Once done this will define
#
#  libplist_FOUND - System has libplist
#  libplist_INCLUDE_DIR - The libplist include directory
#  libplist_LIBRARIES - The libraries needed to use libplist


IF (libplist_INCLUDE_DIR AND libplist_LIBRARIES)
   SET(libplist_FOUND TRUE)
ENDIF (libplist_INCLUDE_DIR AND libplist_LIBRARIES)

FIND_PATH(libplist_INCLUDE_DIR plist/plist.h
   /usr/local/inclue
   /usr/include
)

FIND_LIBRARY(libplist_LIBRARIES 
    NAMES plist++ libplist++
    PATH /usr/local/lib /usr/lib
)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(libplist DEFAULT_MSG libplist_LIBRARIES libplist_INCLUDE_DIR)