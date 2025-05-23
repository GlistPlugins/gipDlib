# ===================================================================================
#  The dlib CMake configuration file
#
#             ** File generated automatically, do not modify **
#
#  Usage from an external project:
#    In your CMakeLists.txt, add these lines:
#
#    find_package(dlib REQUIRED)
#    target_link_libraries(MY_TARGET_NAME dlib::dlib)
#
# ===================================================================================



 
# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET dlib-shared AND NOT dlib_BINARY_DIR)
   # Compute paths
   get_filename_component(dlib_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
   include("${dlib_CMAKE_DIR}/dlib.cmake")
   # Check if Threads::Threads target is required and find it if necessary
   get_target_property(dlib_deps_threads_check dlib::dlib INTERFACE_LINK_LIBRARIES)
   list(FIND dlib_deps_threads_check "Threads::Threads" dlib_deps_threads_idx)
   if (${dlib_deps_threads_idx} GREATER -1)
      if (NOT TARGET Threads)
         find_package(Threads REQUIRED)
      endif()
   endif()
   unset(dlib_deps_threads_idx)
   unset(dlib_deps_threads_check)
endif()

set(dlib_LIBRARIES dlib::dlib)
set(dlib_LIBS      dlib::dlib)
set(dlib_INCLUDE_DIRS "/clang64/include" "")

mark_as_advanced(dlib_LIBRARIES)
mark_as_advanced(dlib_LIBS)
mark_as_advanced(dlib_INCLUDE_DIRS)

# Mark these variables above as deprecated.
function(__deprecated_var var access)
   if(access STREQUAL "READ_ACCESS")
      message(WARNING "The variable '${var}' is deprecated!  Instead, simply use target_link_libraries(your_app dlib::dlib).  See http://dlib.net/examples/CMakeLists.txt.html for an example.")
   endif()
endfunction()
variable_watch(dlib_LIBRARIES __deprecated_var)
variable_watch(dlib_LIBS __deprecated_var)
variable_watch(dlib_INCLUDE_DIRS __deprecated_var)



