# Install script for directory: /Users/maratgasanov/ML_VK/1semestr/educad

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/RenderableEntity/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/Utils/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/Angem/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/Entity/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/Canvas/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/render/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/AngemWorker/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/Controller/cmake_install.cmake")
  include("/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/UI/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/maratgasanov/ML_VK/1semestr/educad/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
