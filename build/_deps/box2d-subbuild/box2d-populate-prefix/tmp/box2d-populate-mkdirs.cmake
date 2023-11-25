# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-src"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-build"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/tmp"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/src"
  "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/imag1ne/GameEngines/tilemaps/Sprite-animation-systems/build/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
